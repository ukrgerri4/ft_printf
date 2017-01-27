#!/bin/bash

clear
gcc -Wall -Wextra -Werror *.c -L. libft/libft.a
./a.out
rm a.out
