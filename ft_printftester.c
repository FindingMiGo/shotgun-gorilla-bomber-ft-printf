#include<stdio.h>
#include"ft_printf.h"
#include <string.h>

static char	g_num[10];
static char *flag = "#0+ -";

void	ft_printf_tester_int(char *fmt, int d)
{
	int r;
	char *tmp;
	char *fmt_d;

	tmp = ft_strjoin(fmt, "150");
	fmt_d = ft_strjoin(tmp, "d");
	free(tmp);
	write(1, fmt_d, strlen(fmt_d));
	write(1, "\n", 1);
	r = ft_printf(fmt_d, d);
	printf(",\t");
	printf("%d\n", r);
	r = printf(fmt_d, d);
	printf(",\t");
	printf("%d\n", r);
	printf("\n");
	free(fmt_d);
}

void	ft_printf_tester_hex(char *fmt, int d)
{
	int r;
	char *tmp;
	char *fmt_x;

	tmp = ft_strjoin(fmt, "3.3");
	fmt_x = ft_strjoin(tmp, "x");
	free(tmp);
	write(1, fmt_x, strlen(fmt_x));
	write(1, "\n", 1);
	r = ft_printf(fmt_x, d);
	printf(",\t");
	printf("%d\n", r);
	r = printf(fmt_x, d);
	printf(",\t");
	printf("%d\n", r);
	printf("\n");
	free(fmt_x);
}

void	ft_printf_tester(char *fmt)
{
	// ft_printf_tester_int(fmt, 100);
	// ft_printf_tester_int(fmt, 0);
	// ft_printf_tester_int(fmt, 1);
	// ft_printf_tester_int(fmt, -1);
	// ft_printf_tester_int(fmt, INT_MAX);
	// ft_printf_tester_int(fmt, INT_MIN);
	ft_printf_tester_hex(fmt, 100);
	ft_printf_tester_hex(fmt, 0);
	ft_printf_tester_hex(fmt, 1);
	ft_printf_tester_hex(fmt, -1);
	ft_printf_tester_hex(fmt, INT_MAX);
	ft_printf_tester_hex(fmt, INT_MIN);
	printf("\n");

	free(fmt);
}

void	ft_printf_combn_rec(int	n, int	depth, int	val)
{
	if (depth == n)
	{
		g_num[n] = 0;
		ft_printf_tester(ft_strjoin("%", g_num));
		return ;
	}
	while (val <= 4)
	{
		g_num[depth] = flag[val];
		ft_printf_combn_rec(n, depth + 1, val + 1);
		val++;
	}
}

void	ft_printf_combn(int n)
{
	return(ft_printf_combn_rec(n, 0, 0));
}

int main(void)
{
	int count;

	count = 5;
	while(count > 0)
		ft_printf_combn(count--);
	return 0;
}
