#!/bin/sh

set -e

echo "Building libftprintf.a..."
make -C .. > /dev/null 2>&1 || echo "  (make skipped or failed, using existing libftprintf.a)"

echo "Compiling tester..."
gcc -Wall -Wextra -Werror ft_printf_tester.c ../libftprintf.a -o sgb_tester

echo "Running tests..."
./sgb_tester

rm -f sgb_tester
