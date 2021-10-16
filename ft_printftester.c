#include<stdio.h>
#include"../ft_printf.h"
#include<string.h>

static char	g_num[10];
char		*flag = "#0+ -";
char		acc[6][4] = { "" , "." , ".0" , ".1", ".10", ".15"};
char		fld[5][3] = { "" , "0" , "1", "10", "15"};

void	ft_printf_tester_int(char *fmt, int d, int flg)
{
	char *tmp;
	char *tmp2;
	char *fmt_d;
	int	r;
	size_t		i = 0;
	size_t		j = 0;

	while (i < 6)
	{
		tmp = ft_strjoin(fmt, fld[i]);
		while(j < 5)
		{
			tmp2 = ft_strjoin(tmp, acc[j]);
			fmt_d = ft_strjoin(tmp2, "d");
			free(tmp2);
			printf("%s[d = %d],\t", fmt_d, d);
			fflush(stdout);
			if (flg == 1)
				r = ft_printf(fmt_d, d);
			else
				r = printf(fmt_d, d);
			fflush(stdout);
			printf(",[%d]\n", r);
			fflush(stdout);
			j++;
			free(fmt_d);
		}
		free(tmp);
		i++;
		j = 0;
	}
}

void	ft_printf_tester_char(char *fmt, char c, int flg)
{
	char *tmp;
	char *tmp2;
	char *fmt_c;
	int	r;
	size_t		i = 0;
	size_t		j = 0;

	while (i < 6)
	{
		tmp = ft_strjoin(fmt, fld[i]);
		while(j < 5)
		{
			tmp2 = ft_strjoin(tmp, acc[j]);
			fmt_c = ft_strjoin(tmp2, "c");
			free(tmp2);
			printf("%s[d = %d],\t", fmt_c, c);
			fflush(stdout);
			if (flg == 1)
				r = printf(fmt_c, c);
			else
				r = ft_printf(fmt_c, c);
			fflush(stdout);
			printf(",[%d]\n", r);
			fflush(stdout);
			j++;
			free(fmt_c);
		}
		free(tmp);
		i++;
		j = 0;
	}
}

void	ft_printf_tester_po(char *fmt, unsigned long p, int flg)
{
	char *tmp;
	char *tmp2;
	char *fmt_c;
	int	r;
	size_t		i = 0;
	size_t		j = 0;

	while (i < 6)
	{
		tmp = ft_strjoin(fmt, fld[i]);
		while(j < 5)
		{
			tmp2 = ft_strjoin(tmp, acc[j]);
			fmt_c = ft_strjoin(tmp2, "p");
			free(tmp2);
			printf("%s[d = %ld],\t", fmt_c, p);
			fflush(stdout);
			if (flg == 1)
				r = printf(fmt_c, p);
			else
				r = ft_printf(fmt_c, p);
			fflush(stdout);
			printf(",[%d]\n", r);
			fflush(stdout);
			j++;
			free(fmt_c);
		}
		free(tmp);
		i++;
		j = 0;
	}
}

void	ft_printf_tester_hex(char *fmt, long long p, int flg)
{
	char *tmp;
	char *tmp2;
	char *fmt_c;
	int	r;
	size_t		i = 0;
	size_t		j = 0;

	while (i < 6)
	{
		tmp = ft_strjoin(fmt, fld[i]);
		while(j < 5)
		{
			tmp2 = ft_strjoin(tmp, acc[j]);
			fmt_c = ft_strjoin(tmp2, "x");
			free(tmp2);
			printf("%s[x = %lld],\t", fmt_c, p);
			fflush(stdout);
			if (flg == 1)
				r = printf(fmt_c, p);
			else
				r = ft_printf(fmt_c, p);
			fflush(stdout);
			printf(",[%d]\n", r);
			fflush(stdout);
			j++;
			free(fmt_c);
		}
		free(tmp);
		i++;
		j = 0;
	}
}

void	ft_printf_tester_hex2(char *fmt, long long p, int flg)
{
	char *tmp;
	char *tmp2;
	char *fmt_c;
	int	r;
	size_t		i = 0;
	size_t		j = 0;

	while (i < 6)
	{
		tmp = ft_strjoin(fmt, fld[i]);
		while(j < 5)
		{
			tmp2 = ft_strjoin(tmp, acc[j]);
			fmt_c = ft_strjoin(tmp2, "X");
			free(tmp2);
			printf("%s[x = %lld],\t", fmt_c, p);
			fflush(stdout);
			if (flg == 1)
				r = printf(fmt_c, p);
			else
				r = ft_printf(fmt_c, p);
			fflush(stdout);
			printf(",[%d]\n", r);
			fflush(stdout);
			j++;
			free(fmt_c);
		}
		free(tmp);
		i++;
		j = 0;
	}
}

void	ft_printf_tester_u(char *fmt, unsigned int u, int flg)
{
	char *tmp;
	char *tmp2;
	char *fmt_u;
	int	r;
	size_t		i = 0;
	size_t		j = 0;

	while (i < 6)
	{
		tmp = ft_strjoin(fmt, fld[i]);
		while(j < 5)
		{
			tmp2 = ft_strjoin(tmp, acc[j]);
			fmt_u = ft_strjoin(tmp2, "u");
			free(tmp2);
			printf("%s[u = %d],\t", fmt_u, u);
			fflush(stdout);
			if (flg == 1)
				r = printf(fmt_u, u);
			else
				r = ft_printf(fmt_u, u);
			fflush(stdout);
			printf(",[%d]\n", r);
			fflush(stdout);
			j++;
			free(fmt_u);
		}
		free(tmp);
		i++;
		j = 0;
	}
}

void	ft_printf_tester_str(char *fmt, char *str, int flg)
{
	char *tmp;
	char *tmp2;
	char *fmt_s;
	int	r;
	size_t		i = 0;
	size_t		j = 0;

	while (i < 6)
	{
		tmp = ft_strjoin(fmt, fld[i]);
		while(j < 5)
		{
			tmp2 = ft_strjoin(tmp, acc[j]);
			fmt_s = ft_strjoin(tmp2, "s");
			free(tmp2);
			printf("%s[s = %s],\t", fmt_s, str);
			fflush(stdout);
			if (flg == 1)
				r = printf(fmt_s, str);
			else
				r = ft_printf(fmt_s, str);
			fflush(stdout);
			printf(",[%d]\n", r);
			fflush(stdout);
			j++;
			free(fmt_s);
		}
		free(tmp);
		i++;
		j = 0;
	}
}

void	ft_printf_tester(char *fmt, int flg)
{
	int testd[] = {-1 , 0 , 1, 100, INT_MAX, INT_MIN};
	int testc[] = {'0', '0' - 256, '0' + 256, ' ', '1', '2', '3', 'a'};
	unsigned long testp[] = {-1, 1, 15, 16, 17, LONG_MIN, LONG_MAX, INT_MIN, INT_MAX, ULONG_MAX, -ULONG_MAX, 0};
	long long	testx[] = {-100, -1, 1, 15, 16, 17, 99, 100, LONG_MIN, LONG_MAX, INT_MIN, INT_MAX, ULONG_MAX, -ULONG_MAX, 0, 9223372036854775807LL};
	char		tests[5][3] = { "" , "0" , "1", "10", "15"};
	long long	testu[] = {-1, 1, 15, 16, 17, LONG_MIN, LONG_MAX, INT_MIN, INT_MAX, ULONG_MAX, -ULONG_MAX, 0};
	size_t	i = 0;

	while (i < (sizeof(testd)/sizeof(int)))
		ft_printf_tester_int(fmt, testd[i++], flg);
	i = 0;
	while (i < (sizeof(testc)/sizeof(int)))
		ft_printf_tester_char(fmt, testc[i++], flg);
	i = 0;
	while (i < (sizeof(testp)/sizeof(unsigned long)))
		ft_printf_tester_po(fmt, testp[i++], flg);
	i = 0;
	while (i < (sizeof(testx)/sizeof(long long)))
		ft_printf_tester_hex(fmt, testx[i++], flg);
	i = 0;
	while (i < (sizeof(testx)/sizeof(long long)))
		ft_printf_tester_hex2(fmt, testx[i++], flg);
	i = 0;
	while (i < (sizeof(tests)/sizeof(char*)))
		ft_printf_tester_str(fmt, tests[i++], flg);
	i = 0;
	while (i < (sizeof(testu)/sizeof(long long)))
		ft_printf_tester_u(fmt, testu[i++], flg);
	free(fmt);
}

void	ft_printf_combn_rec(int	n, int	depth, int	val, int flg)
{
	if (depth == n)
	{
		g_num[n] = 0;
		ft_printf_tester(ft_strjoin("%", g_num), flg);
		if (n == 1 && val == (int)ft_strlen(flag))
			ft_printf_tester(ft_strdup("%"), flg);
		return ;
	}
	while (val <= 4)
	{
		g_num[depth] = flag[val];
		ft_printf_combn_rec(n, depth + 1, val + 1, flg);
		val++;
	}
}

void	ft_printf_combn(int flg)
{
	int count;

	count = 5;
	while(count > 0)
		ft_printf_combn_rec(count--, 0, 0, flg);
}

int main(int argc, char const *argv[])
{
	(void)argv;
	if (argc > 1)
		ft_printf_combn(1);
	else
		ft_printf_combn(0);
	return 0;
}
