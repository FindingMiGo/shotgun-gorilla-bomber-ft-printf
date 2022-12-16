#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include "../ft_printf.h"

#define C_RED    "\033[31m"
#define C_GREEN  "\033[32m"
#define C_DIM    "\033[2m"
#define C_BOLD   "\033[1m"
#define C_RESET  "\033[0m"
#define ARRLEN(a) (sizeof(a) / sizeof((a)[0]))

static int g_total;
static int g_pass;
static int g_fail;

static char g_flags_buf[10];
static const char *g_flag_chars = "#0+ -";
static const char *g_fld[] = {"", "0", "1", "3", "6", "7", "10", "15"};
static const char *g_acc[] = {"", ".", ".0", ".1", ".3", ".10", ".15"};

typedef int (*t_printfn)(const char *, ...);

typedef struct {
	char	buf[4096];
	int		len;
	int		ret;
} t_capture;

static t_capture capture(t_printfn fn, const char *fmt, int spec, void *val)
{
	t_capture	c;
	int			pipefd[2];
	int			saved;

	pipe(pipefd);
	saved = dup(1);
	dup2(pipefd[1], 1);
	if (spec == 'p')
		c.ret = fn(fmt, *(unsigned long *)val);
	else if (spec == 'x' || spec == 'X')
		c.ret = fn(fmt, *(long long *)val);
	else if (spec == 'u')
		c.ret = fn(fmt, *(unsigned int *)val);
	else if (spec == 's')
		c.ret = fn(fmt, *(char **)val);
	else
		c.ret = fn(fmt, *(int *)val);
	fflush(stdout);
	dup2(saved, 1);
	close(saved);
	close(pipefd[1]);
	c.len = read(pipefd[0], c.buf, sizeof(c.buf) - 1);
	if (c.len < 0)
		c.len = 0;
	c.buf[c.len] = '\0';
	close(pipefd[0]);
	return (c);
}

static void run_test(const char *fmt, int spec, void *val, const char *val_str)
{
	t_capture	expected;
	t_capture	actual;

	expected = capture((t_printfn)printf, fmt, spec, val);
	actual = capture((t_printfn)ft_printf, fmt, spec, val);
	g_total++;
	if (expected.len == actual.len
		&& memcmp(expected.buf, actual.buf, expected.len) == 0
		&& expected.ret == actual.ret)
	{
		g_pass++;
		return ;
	}
	g_fail++;
	fprintf(stderr, C_RED "FAIL" C_RESET " " C_DIM "%s" C_RESET " [%s]\n",
		fmt, val_str);
	if (expected.len != actual.len
		|| memcmp(expected.buf, actual.buf, expected.len) != 0)
		fprintf(stderr, "  out: " C_GREEN "\"%s\"" C_RESET
			" → " C_RED "\"%s\"" C_RESET "\n", expected.buf, actual.buf);
	if (expected.ret != actual.ret)
		fprintf(stderr, "  ret: " C_GREEN "%d" C_RESET
			" → " C_RED "%d" C_RESET "\n", expected.ret, actual.ret);
}

static void test_spec(const char *flags, int spec, void *val, const char *val_str)
{
	char	fmt[64];
	size_t	i;
	size_t	j;

	for (i = 0; i < ARRLEN(g_fld); i++)
	{
		for (j = 0; j < ARRLEN(g_acc); j++)
		{
			snprintf(fmt, sizeof(fmt), "%%%s%s%s%c",
				flags, g_fld[i], g_acc[j], spec);
			run_test(fmt, spec, val, val_str);
		}
	}
}

#define TEST(flags, spec, arr, names) \
	do { \
		for (size_t _i = 0; _i < ARRLEN(arr); _i++) \
			test_spec(flags, spec, &(arr)[_i], (names)[_i]); \
	} while (0)

static void test_all_values(const char *flags)
{
	/* %d */
	int td[] = {-1, 0, 1, 100, INT_MAX, INT_MIN};
	const char *td_n[] = {"-1", "0", "1", "100", "INT_MAX", "INT_MIN"};
	TEST(flags, 'd', td, td_n);

	/* %i */
	TEST(flags, 'i', td, td_n);

	/* %c */
	int tc[] = {0, '0', '0' - 256, '0' + 256, ' ', '1', '2', '3', 'a',
		127, 255};
	const char *tc_n[] = {"0", "'0'", "'0'-256", "'0'+256",
		"' '", "'1'", "'2'", "'3'", "'a'", "127", "255"};
	TEST(flags, 'c', tc, tc_n);

	/* %p */
	unsigned long tp[] = {-1UL, 1, 15, 16, 17, (unsigned long)LONG_MIN,
		(unsigned long)LONG_MAX, (unsigned long)INT_MIN,
		(unsigned long)INT_MAX, ULONG_MAX, -ULONG_MAX, 0};
	const char *tp_n[] = {"-1", "1", "15", "16", "17", "LONG_MIN",
		"LONG_MAX", "INT_MIN", "INT_MAX", "ULONG_MAX", "-ULONG_MAX", "0"};
	TEST(flags, 'p', tp, tp_n);

	/* %x %X */
	long long tx[] = {-100, -1, 1, 15, 16, 17, 99, 100, LONG_MIN,
		LONG_MAX, INT_MIN, INT_MAX, (long long)ULONG_MAX,
		(long long)(-ULONG_MAX), 0, 9223372036854775807LL};
	const char *tx_n[] = {"-100", "-1", "1", "15", "16", "17", "99", "100",
		"LONG_MIN", "LONG_MAX", "INT_MIN", "INT_MAX",
		"ULONG_MAX", "-ULONG_MAX", "0", "LLONG_MAX"};
	TEST(flags, 'x', tx, tx_n);
	TEST(flags, 'X', tx, tx_n);

	/* %u */
	unsigned int tu[] = {(unsigned int)-1, 1, 15, 16, 17, 0, UINT_MAX,
		INT_MAX};
	const char *tu_n[] = {"-1", "1", "15", "16", "17", "0", "UINT_MAX",
		"INT_MAX"};
	TEST(flags, 'u', tu, tu_n);

	/* %s */
	char *ts[] = {"", "0", "1", "hello world", "42 tokyo",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
	const char *ts_n[] = {"\"\"", "\"0\"", "\"1\"",
		"\"hello world\"", "\"42 tokyo\"", "\"aaa...(52)\""};
	TEST(flags, 's', ts, ts_n);
	char *null_str = NULL;
	test_spec(flags, 's', &null_str, "NULL");
}

/* ── tests outside the flag matrix ── */
static void test_misc(void)
{
	int		d;
	char	*s;

	/* %% */
	d = 0;
	run_test("%%", 'd', &d, "bare %%");
	run_test("100%%", 'd', &d, "100%%");
	run_test("%%hello%%", 'd', &d, "%%hello%%");

	/* empty format */
	run_test("", 'd', &d, "empty fmt");

	/* plain text */
	run_test("hello world", 'd', &d, "no specifier");

	/* text around specifiers */
	d = 42;
	run_test("abc%dxyz", 'd', &d, "text around %d");
	d = -1;
	run_test("[%d]", 'd', &d, "brackets %d");
	s = "test";
	run_test(">>%s<<", 's', &s, "text around %s");

	/* large width */
	d = 42;
	run_test("%50d", 'd', &d, "width 50");
	run_test("%100d", 'd', &d, "width 100");
	run_test("%-50d", 'd', &d, "left-align w50");
	s = "hi";
	run_test("%50s", 's', &s, "width 50 str");
	run_test("%-50s", 's', &s, "left-align w50 str");

	/* trailing % */
	run_test("hello%", 'd', &d, "trailing %");

	/* %c with NUL */
	d = 0;
	run_test("%c", 'c', &d, "NUL char");
	run_test("a%cb", 'c', &d, "text around NUL");

}

/* ── recursive flag combination generator ── */
static void combn_rec(int n, int depth, int start)
{
	int	i;

	if (depth == n)
	{
		g_flags_buf[n] = '\0';
		test_all_values(g_flags_buf);
		return ;
	}
	i = start;
	while (i < 5)
	{
		g_flags_buf[depth] = g_flag_chars[i];
		combn_rec(n, depth + 1, i + 1);
		i++;
	}
}

int	main(void)
{
	int	n;

	fprintf(stderr, "\n" C_BOLD "  Shotgun Gorilla Bomber" C_RESET
		C_DIM " — exhaustive ft_printf tester" C_RESET "\n\n");
	test_all_values("");
	n = 1;
	while (n <= 5)
	{
		combn_rec(n, 0, 0);
		n++;
	}
	test_misc();
	fprintf(stderr, "\n" C_BOLD "  Results: " C_RESET);
	if (g_fail == 0)
		fprintf(stderr, C_GREEN "ALL %d PASSED" C_RESET, g_total);
	else
		fprintf(stderr, C_GREEN "%d passed" C_RESET ", "
			C_RED "%d failed" C_RESET " / %d total",
			g_pass, g_fail, g_total);
	fprintf(stderr, "\n\n");
	return (g_fail > 0);
}
