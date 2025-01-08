#ifndef CRAYONS_H
#define CRAYONS_H

#include <stdio.h>
#include <stdlib.h>  // for malloc() and free()
#include <string.h>  // for strlen()
#include <stdbool.h> // for true and false

/*
  This library provides helpers to print text to the terminal with colors using ANSI Escape codes.
  The library supports:

  Simple formatting with standalone functions:
    print_ansi_color(ANSI_RED, "Red text");
    print_rgb_color(255, 100, 0, "Orange text");
    enum ANSIStyles styles[] = {ANSI_BOLD, ANSI_UNDERLINE};
    print_ansi_style(styles, 2, "Bold and underlined text");

  Combined formatting with TextFormat struct:
    TextFormat fmt = new_format();
    TextFormat* p = &fmt;
    p = set_rgb_color(p, 255, 0, 0);      // Red text
    p = set_ansi_bg(p, ANSI_BLUE);        // Blue background
    p = add_style(p, ANSI_BOLD);          // Bold
    print_formatted(&fmt, "Complex formatted text");

  Color support:
  - ANSI standard colors (widely supported)
  - RGB colors (may not be supported by all terminals)

  Memory is managed internally by the helper functions, but when using the apply_*
  functions directly, memory must be freed manually.
*/

// ANSI color codes for terminal text coloring
// These codes can be used with ANSI escape sequences to color terminal output
// Full reference: https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
enum ANSIColors {
  ANSI_DEFAULT = 39,
  ANSI_BLACK = 30,
  ANSI_RED = 31,
  ANSI_GREEN = 32,
  ANSI_YELLOW = 33,
  ANSI_BLUE = 34,
  ANSI_MAGENTA = 35,
  ANSI_CYAN = 36,
  ANSI_WHITE = 37,
  ANSI_BRIGHT_BLACK = 90,
  ANSI_BRIGHT_RED = 91,
  ANSI_BRIGHT_GREEN = 92,
  ANSI_BRIGHT_YELLOW = 93,
  ANSI_BRIGHT_BLUE = 94,
  ANSI_BRIGHT_MAGENTA = 95,
  ANSI_BRIGHT_CYAN = 96,
  ANSI_BRIGHT_WHITE = 97
};

// ANSI text style codes for terminal text styling
// These codes can be used with ANSI escape sequences to style terminal output
// Full reference: https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
enum ANSIStyles {
  ANSI_RESET = 0,
  ANSI_BOLD = 1,
  ANSI_DIM = 2,
  ANSI_ITALIC = 3,
  ANSI_UNDERLINE = 4,
  ANSI_BLINK = 5,
  ANSI_INVERSE = 7,
  ANSI_HIDDEN = 8,
  ANSI_STRIKETHROUGH = 9, // Not widely supported.
  ANSI_RESET_BOLD_DIM = 22,
  ANSI_RESET_ITALIC = 23,
  ANSI_RESET_UNDERLINE = 24,
  ANSI_RESET_BLINK = 25,
  ANSI_RESET_INVERSE = 27,
  ANSI_RESET_HIDDEN = 28,
  ANSI_RESET_STRIKETHROUGH = 29 // Not widely supported.
};

/*
  This function takes a color enumeration, message string and a pointer to a pointer for storing the result.
  It creates a new string containing ANSI escape sequences to color the message.

  IMPORTANT: The memory allocated by this function must be freed by the caller when no longer needed
  to prevent memory leaks.

  The function:
  1. Checks if message and result pointers are valid
  2. Calculates required memory size for ANSI sequences + message
  3. Allocates memory for the colored string
  4. Formats the string with ANSI escape sequences
  5. Assigns the formatted string to the result pointer (defined outside the function)
  6. Returns EXIT_SUCCESS if successful, EXIT_FAILURE if any errors occur

  In simpler terms the flow is:
  1. Allocate space with `malloc`
  2. Fill that space with characters using `snprintf`
  3. Return pointer to that memory through `result`

  The result is stored in a variable defined outside this function - it only returns
  a success/failure status code.

  Example usage:
    char* colored_text;
    if (apply_ansi_color(color, message, &colored_text) == EXIT_SUCCESS) {
      printf("%s\n", colored_text);
      free(colored_text);  // Must free allocated memory when done to prevent leaks
    }

  Additionally, `char** result` should be an address of a pointer and is used because it needs to modify what the passed pointer points to, so that it points to the buffer with the modified text. `char** result` would not work, since it would only change the local copy of the pointer.
*/
int apply_ansi_color(enum ANSIColors color, const char* message, char** result) {
  // Message and result are required, throw an error if either are not present.
  if (!message || !result) return EXIT_FAILURE;

  size_t message_length = strlen(message);
  size_t ansi_escape_sequence_size = 20;

  // Takes the message length and adds 20 bytes for ANSI escape sequences to
  // establish the required size to allocate to memory.
  size_t required_size = message_length + ansi_escape_sequence_size;

  // Allocates memory to a string (an array of characters) and assigns it to a pointer,
  // holding the address of the first character.
  // Throw error if it fails.
  char* buffer = (char*)malloc(required_size);
  if (!buffer) return EXIT_FAILURE;

  // Format the colored string into the buffer,
  // assigns it to the result (defined outside of this function) and exits.
  snprintf(buffer, required_size, "\033[%dm%s\033[0m", color, message);
  // Stores the address of the newly allocated character array into the pointer passed to the function.
  *result = buffer; // Follows the copied address back to the original definition.

  return EXIT_SUCCESS;
}

/*
  This function prints a message in a specified ANSI color to the terminal.
  It uses apply_ansi_color to format the string with ANSI escape sequences,
  prints the result, and handles the memory cleanup automatically.

  Parameters:
    color - ANSI color code from ANSIColors enum
    message - The text string to be colored

  The function internally manages memory allocation and deallocation,
  so the caller does not need to handle memory management.
*/
void print_ansi_color(enum ANSIColors color, char* message) {
  // Stores the address of the first character of the string.
  char* colored_text;

  // Pass the colored_text addressto the function so that it can assign the result to it.
  if (apply_ansi_color(color, message, &colored_text) == EXIT_SUCCESS) {
    printf("%s\n", colored_text);
    free(colored_text);
  }
}

/*
  This function takes RGB color values, a message string and a pointer to a pointer for storing the result.
  It creates a new string containing ANSI escape sequences to color the message with RGB values.

  IMPORTANT: The memory allocated by this function must be freed by the caller when no longer needed
  to prevent memory leaks.

  The function follows the same pattern as apply_ansi_color:
  1. Checks if message and result pointers are valid
  2. Calculates required memory size for ANSI sequences + message
  3. Allocates memory for the colored string
  4. Formats the string with ANSI escape sequences using RGB values
  5. Assigns the formatted string to the result pointer
  6. Returns EXIT_SUCCESS if successful, EXIT_FAILURE if any errors occur
*/
int apply_rgb_color(int r, int g, int b, const char* message, char** result) {
  if (!message || !result) return EXIT_FAILURE;

  size_t message_length = strlen(message);
  size_t ansi_escape_sequence_size = 25;  // Slightly larger for RGB values
  size_t required_size = message_length + ansi_escape_sequence_size;

  char* buffer = (char*)malloc(required_size);
  if (!buffer) return EXIT_FAILURE;

  snprintf(buffer, required_size, "\033[38;2;%d;%d;%dm%s\033[0m", r, g, b, message);
  *result = buffer;

  return EXIT_SUCCESS;
}

/*
  This function prints a message in a specified RGB color to the terminal.
  It uses apply_rgb_color to format the string with ANSI escape sequences,
  prints the result, and handles the memory cleanup.
*/
void print_rgb_color(int r, int g, int b, char* message) {
  char* colored_text;
  if (apply_rgb_color(r, g, b, message, &colored_text) == EXIT_SUCCESS) {
    printf("%s\n", colored_text);
    free(colored_text);
  }
}

/*
  This function takes an array of ANSI style codes, number of styles, message string and a pointer
  to a pointer for storing the result. It creates a new string containing ANSI escape sequences
  to style the message with multiple text effects.

  IMPORTANT: The memory allocated by this function must be freed by the caller when no longer needed
  to prevent memory leaks.

  Parameters:
    styles - Array of ANSI style codes from ANSIStyles enum
    num_styles - Number of style codes in the array
    message - The text string to be styled
    result - Pointer to char* that will store the resulting styled string

  The function:
  1. Checks if all input parameters are valid
  2. Calculates required memory size for ANSI sequences + message
  3. Allocates memory for the styled string
  4. Formats the string with ANSI escape sequences for each style
  5. Assigns the formatted string to the result pointer
  6. Returns EXIT_SUCCESS if successful, EXIT_FAILURE if any errors occur
*/
int apply_ansi_style(enum ANSIStyles* styles, int num_styles, const char* message, char** result) {
  if (!message || !result || !styles) return EXIT_FAILURE;

  size_t message_length = strlen(message);
  size_t ansi_escape_sequence_size = 20 + (num_styles * 3); // Extra space for style codes
  size_t required_size = message_length + ansi_escape_sequence_size;

  char* buffer = (char*)malloc(required_size);
  if (!buffer) return EXIT_FAILURE;

  // Apply each style in the array:
  int offset = snprintf(buffer, required_size, "\033[");
  for (int index = 0; index < num_styles; index++) {
    offset += snprintf(buffer + offset, required_size - offset, "%d", styles[index]);
    if (index < num_styles - 1) {
      offset += snprintf(buffer + offset, required_size - offset, ";");
    }
  }
  snprintf(buffer + offset, required_size - offset, "m%s\033[0m", message);

  *result = buffer;
  return EXIT_SUCCESS;
}

/*
  This function prints a message with multiple ANSI text styles to the terminal.
  It uses apply_ansi_style to format the string with ANSI escape sequences,
  prints the result, and handles the memory cleanup automatically.

  Parameters:
    styles - Array of ANSI style codes from ANSIStyles enum
    num_styles - Number of style codes in the array
    message - The text string to be styled

  The function internally manages memory allocation and deallocation,
  so the caller does not need to handle memory management.
*/
void print_ansi_style(enum ANSIStyles* styles, int num_styles, char* message) {
  char* styled_text;
  if (apply_ansi_style(styles, num_styles, message, &styled_text) == EXIT_SUCCESS) {
    printf("%s\n", styled_text);
    free(styled_text);
  }
}

void print_rgb_foreground_background_colors(int fr, int fg, int fb, int br, int bg, int bb, char* message) {
  printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm%s\033[0m\n",
    fr, fg, fb,  // Foreground RGB
    br, bg, bb,  // Background RGB
    message);
}

void print_ansi_foreground_background_colors(enum ANSIColors foreground_color, enum ANSIColors background_color, char* message) {
  printf("\033[%d;%dm%s\033[0m\n",
    foreground_color,     // Foreground color
    background_color + 10, // Background color (add 10 to foreground code so that ANSI escape code system sets the background color.)
    message);
}

/*
  The TextFormat struct provides a way to build complex text formatting by combining
  multiple features:
  - Foreground colors (using either ANSI codes or RGB values)
  - Background colors (using either ANSI codes or RGB values)
  - Multiple text styles (bold, italic, underline, etc.)

  Example usage:
    TextFormat fmt = new_text_format();
    TextFormat* p = &fmt;
    p = set_rgb_color(p, 255, 0, 0);      // Red text
    p = set_ansi_bg(p, ANSI_BLUE);        // Blue background
    p = add_style(p, ANSI_BOLD);          // Bold
    print_formatted(p, "Complex formatted text");
*/
typedef struct {
    // Foreground
    bool has_fg_color;
    bool is_fg_rgb;  // true for RGB, false for ANSI
    enum ANSIColors ansi_fg;
    int fg_r;
    int fg_g;
    int fg_b;

    // Background
    bool has_bg_color;
    bool is_bg_rgb;  // true for RGB, false for ANSI
    enum ANSIColors ansi_bg;
    int bg_r;
    int bg_g;
    int bg_b;

    // Styles
    enum ANSIStyles styles[10];
    int num_styles;
} TextFormat;

/*
  Sets an RGB foreground color for text formatting.

  Parameters:
    fmt - Pointer to TextFormat struct to modify
    r,g,b - RGB color values (0-255)

  Returns: Pointer to the modified TextFormat struct for chaining

  Example:
    TextFormat* fmt = &new_text_format();
    fmt = set_rgb_color(fmt, 255, 0, 0); // Bright red text
*/
TextFormat* set_rgb_color(TextFormat* fmt, int r, int g, int b) {
    fmt->has_fg_color = true;
    fmt->is_fg_rgb = true;
    fmt->fg_r = r;
    fmt->fg_g = g;
    fmt->fg_b = b;
    return fmt;
}

/*
  Sets an ANSI foreground color for text formatting.

  Parameters:
    fmt - Pointer to TextFormat struct to modify
    color - ANSI color code from ANSIColors enum

  Returns: Pointer to the modified TextFormat struct for chaining

  Example:
    TextFormat* fmt = &new_text_format();
    fmt = set_ansi_color(fmt, ANSI_RED); // Red text using ANSI code
*/
TextFormat* set_ansi_color(TextFormat* fmt, enum ANSIColors color) {
    fmt->has_fg_color = true;
    fmt->is_fg_rgb = false;
    fmt->ansi_fg = color;
    return fmt;
}

/*
  Sets an RGB background color for text formatting.

  Parameters:
    fmt - Pointer to TextFormat struct to modify
    r,g,b - RGB color values (0-255)

  Returns: Pointer to the modified TextFormat struct for chaining

  Example:
    TextFormat* fmt = &new_text_format();
    fmt = set_rgb_bg(fmt, 0, 0, 255); // Bright blue background
*/
TextFormat* set_rgb_bg(TextFormat* fmt, int r, int g, int b) {
    fmt->has_bg_color = true;
    fmt->is_bg_rgb = true;
    fmt->bg_r = r;
    fmt->bg_g = g;
    fmt->bg_b = b;
    return fmt;
}

/*
  Sets an ANSI background color for text formatting.

  Parameters:
    fmt - Pointer to TextFormat struct to modify
    color - ANSI color code from ANSIColors enum

  Returns: Pointer to the modified TextFormat struct for chaining

  Example:
    TextFormat* fmt = &new_text_format();
    fmt = set_ansi_bg(fmt, ANSI_BLUE); // Blue background using ANSI code
*/
TextFormat* set_ansi_bg(TextFormat* fmt, enum ANSIColors color) {
    fmt->has_bg_color = true;
    fmt->is_bg_rgb = false;
    fmt->ansi_bg = color;
    return fmt;
}

/*
  Adds a text style to the format options.
  Multiple styles can be combined (up to 10) to create complex formatting.

  Parameters:
    fmt - Pointer to TextFormat struct to modify
    style - ANSI style code from ANSIStyles enum

  Returns: Pointer to the modified TextFormat struct for chaining

  Example:
    TextFormat* fmt = &new_text_format();
    fmt = set_ansi_style(fmt, ANSI_BOLD); // Make text bold
    fmt = set_ansi_style(fmt, ANSI_ITALIC); // Add italic style
*/
TextFormat* set_ansi_style(TextFormat* fmt, enum ANSIStyles style) {
    if (fmt->num_styles < 10) {
        fmt->styles[fmt->num_styles++] = style;
    }
    return fmt;
}

/*
  Prints a message using the formatting specified in a TextFormat struct.
  Combines styles, foreground color and background color into a single
  ANSI escape sequence.

  Parameters:
    fmt - Pointer to TextFormat struct containing formatting options
    message - Text string to format and print

    Example:
      TextFormat fmt = new_text_format();
      fmt = set_ansi_color(&fmt, ANSI_RED);
      fmt = set_ansi_bg(&fmt, ANSI_BLUE);
      fmt = set_ansi_style(&fmt, ANSI_BOLD);
      print_formatted(&fmt, "Bold red text on blue background");
*/
void print_formatted(TextFormat* fmt, const char* message) {
    printf("\033["); // Start ANSI escape sequence

    // Apply styles first
    bool need_separator = false;
    for (int i = 0; i < fmt->num_styles; i++) {
        if (need_separator) printf(";");
        printf("%d", fmt->styles[i]);
        need_separator = true;
    }

    // Apply foreground color
    if (fmt->has_fg_color) {
        if (need_separator) printf(";");
        if (!fmt->is_fg_rgb) {
            printf("%d", fmt->ansi_fg);
        } else {
            printf("38;2;%d;%d;%d",
                fmt->fg_r,
                fmt->fg_g,
                fmt->fg_b);
        }
        need_separator = true;
    }

    // Apply background color
    if (fmt->has_bg_color) {
        if (need_separator) printf(";");
        if (!fmt->is_bg_rgb) {
            printf("%d", fmt->ansi_bg + 10);
        } else {
            printf("48;2;%d;%d;%d",
                fmt->bg_r,
                fmt->bg_g,
                fmt->bg_b);
        }
    }

    printf("m%s\033[0m", message);
}

/*
  Creates a new TextFormat struct with all fields initialized to zero/false.
  Use this to start building text formatting options.

  Returns: A new TextFormat struct

  Example:
    TextFormat fmt = new_text_format();
    // fmt is ready to have colors and styles applied
*/
TextFormat new_text_format(void) {
    TextFormat fmt = {0};  // Zero initialize everything
    return fmt;
}

#endif
