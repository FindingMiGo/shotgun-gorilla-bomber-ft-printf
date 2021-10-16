test :
	$(MAKE) ../
	@$(CC) -Wall -Wextra -Werror ft_printftester.c ../libftprintf.a
	@mkdir -p out
	@./a.out > out/printf.txt
	@./a.out 1 > out/ft_printf.txt
	diff out/printf.txt out/ft_printf.txt > out/diff.txt
	@rm ./a.out

.PHONY: testdiff
