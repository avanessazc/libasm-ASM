# libasm
> Common core project at 42 School - Paris
>
> This project is an introduction to Assembly language

## Introduction
This project is about creating a library in Assembly language, with 6 rewritten functions from C lenguage

## General guidelines
1.  The library must be called `libasm.a`.
2. You must submit a main that will test your functions and that will compile with your library to show that it’s functional.
3. You must rewrite the following functions in asm:
    - ft_strlen (man 3 strlen)
    - ft_strcpy (man 3 strcpy)
    - ft_strcmp (man 3 strcmp)
    - ft_write (man 2 write)
    - ft_read (man 2 read)
    - ft_strdup (man 3 strdup, you can call to malloc)
4. You must check for errors during syscalls and properly set them when needed
5. Your code must set the variable errno properly.
6. For that, you are allowed to call the extern ___error or errno_location.
7. You must write 64 bits ASM.
8. You can’t do inline ASM, you must do ’.s’ files.
9. You must compile your assembly code with nasm.
10. You must use the Intel syntax, not the AT&T.

## Content
`Makefile` contains the rules for compiling the Assembly code

`srcs/` contains the rewritten fucntions

`tests/` contains the main.c function with all the tests.