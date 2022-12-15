#!/bin/sh

set -e

echo "Compiling..."
gcc -Wall -Wextra -Werror ft_printf_tester.c ../libftprintf.a -o kso_tester

echo "Running tests..."
./kso_tester

rm -f kso_tester
