# C Labs

Experiments and short programs written in C.

## Requirements

1. Docker or
2. Your preferred way of compiling C (e.g GCC).

## Setup with Docker

The following command will build an image that can compile and run `C` programs,
will bind this project folder to the container's `/home/source/` and
it will keep the container alive indefinetly so that the project can be worked on.

```bash
docker compose up --detach
```

Then access the container using the ID if known or the name which will always be `clang`:

```bash
docker exec -it clang /bin/bash
```

With access to the container switch the directory to find the project files e.g:

```bash
cd /home/source/hello
```

Compile programs and run `binaries` as needed:

```bash
# Compile the program:
gcc -o main ./main.c

# or with clang:
clang -g -Wall -std=c99 -o main ./main.c

# Run the program:
./main
```

When done, exit the interactive terminal with `Ctrl+C` and remove the containers or type `exit`:

```bash
docker compose down
```

Programs can also be inspected for memory leaks using `valgrind <file>`:

```bash
root@567cbfe975b0:/home/project/source/malloc# valgrind ./main

==40== Memcheck, a memory error detector
==40== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==40== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==40== Command: ./main
==40==
source: hello
target: Hello
==40==
==40== HEAP SUMMARY:
==40==     in use at exit: 0 bytes in 0 blocks
==40==   total heap usage: 2 allocs, 2 frees, 1,030 bytes allocated
==40==
==40== All heap blocks were freed -- no leaks are possible
==40==
==40== For counts of detected and suppressed errors, rerun with: -v
==40== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
