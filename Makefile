test :
	@gcc -Wall -Wextra -Werror ft_printftester.c ../libftprintf.a
	@mkdir -p out
	@./a.out > out/printf
	@./a.out 1 > out/ft_printf
	diff out/printf out/ft_printf > out/diff

.PHONY: test
