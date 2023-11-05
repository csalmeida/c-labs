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
gcc -o hello ./hello.c

# Run the program:
./hello
```

When done, exit the interactive terminal with `Ctrl+C` and remove the containers or type `exit`:

```bash
docker compose down
```
