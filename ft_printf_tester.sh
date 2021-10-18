#!/bin/sh

gcc -Wall -Wextra -Werror ft_printf_tester.c ../libftprintf.a
mkdir -p out
./a.out > out/printf
./a.out 1 > out/ft_printf
diff out/printf out/ft_printf > out/diff
