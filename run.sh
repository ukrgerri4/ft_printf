#!/bin/bash

clear
gcc *.c -L. libft/libft.a
./a.out | cat -e
#rm a.out
