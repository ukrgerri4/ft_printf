#!/bin/bash

clear
make fclean
make
make clean
gcc main.c libftprintf.a
./a.out | cat -e
rm a.out