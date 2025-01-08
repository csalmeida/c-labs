#include <stdio.h>
#include <stdlib.h>
#include "crayons/crayons.h"

int main(void) {
  printf("\nMessage with default styles\n");

  printf("\n\033[31mThis text is red!\033[0m\n");  // Red text
  printf("\n\033[32mThis text is green!\033[0m\n"); // Green text
  printf("\n\033[33mThis text is yellow!\033[0m\n"); // Yellow text
  printf("\n\033[0mThis is normal text.\n");         // Reset to default

  print_ansi_color(ANSI_CYAN, "\nHello print_ansi_color!");
  enum ANSIStyles styles[] = {ANSI_BOLD, ANSI_UNDERLINE};
  print_ansi_style(styles, 2, "\nThis is bold and underlined!");

  printf("\n");
  print_rgb_foreground_background_colors(255, 100, 0, 0, 0, 0, "                                             ");
  print_rgb_foreground_background_colors(255, 100, 0, 0, 0, 0, "   This is orange text on black background   ");
  print_rgb_foreground_background_colors(255, 100, 0, 0, 0, 0, "                                             ");
  printf("\n");

  print_ansi_foreground_background_colors(ANSI_BLACK, ANSI_MAGENTA, "\n Black text on a magenta background ");

  print_rgb_color(100, 200, 255, "\nThis is a custom RGB color message");
  print_rgb_color(150, 75, 200, "\nSTART This is an extremely long message that goes on and on and demonstrates how our dynamic memory allocation can handle strings of any length without buffer overflow issues because we properly calculated the required size and allocated memory accordingly. Let's make this even longer to really test our dynamic allocation by adding more text here to see how it handles a truly lengthy string with lots of words and characters and punctuation marks! But wait, there's more! We can keep adding text to make this message even longer and longer, testing the limits of our dynamic allocation system. We'll add sentences, phrases, and more words to really push the boundaries of what our system can handle. The sky is the limit when it comes to string length since we're using proper dynamic memory allocation techniques that scale with the input size. This message just keeps going and going, like an energizer bunny of text processing! END");

  TextFormat fmt = new_text_format();
  TextFormat* pointer_fmt = &fmt;
  pointer_fmt = set_rgb_color(pointer_fmt, 255, 100, 0);
  print_formatted(pointer_fmt, "\nHello, World");

  TextFormat fmt_2 = new_text_format();
  TextFormat* pointer_fmt_2 = &fmt_2;
  pointer_fmt_2 = set_ansi_color(pointer_fmt_2, ANSI_GREEN);
  pointer_fmt_2 = set_ansi_style(pointer_fmt_2, ANSI_UNDERLINE);
  pointer_fmt_2 = set_ansi_style(pointer_fmt_2, ANSI_ITALIC);
  print_formatted(pointer_fmt_2, "\nHello, World 2");

  TextFormat success = new_text_format();
  TextFormat* s = &success;
  s = set_ansi_color(s, ANSI_BRIGHT_GREEN);// Bright green text
  s = set_ansi_style(s, ANSI_BOLD);             // Bold
  print_formatted(s, "\n✓ Operation completed successfully!");

  TextFormat header = new_text_format();
  TextFormat* h = &header;
  h = set_ansi_color(h, ANSI_BRIGHT_CYAN);      // Bright cyan text
  h = set_ansi_style(h, ANSI_BOLD);            // Bold
  h = set_ansi_style(h, ANSI_UNDERLINE);       // Underlined
  h = set_ansi_bg(h, ANSI_WHITE);
  print_formatted(h, "\n == Section Header == ");

  return EXIT_SUCCESS;
}
