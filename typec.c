#include "ramen-barmen-libft-tester.h"

void	test_classification_functions(void)
{
		int i;
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		for (i = -1; i <= 128; i++)
		{
				g_assert_cmpint(!!ft_isalpha(i), ==, !!isalpha(i));
				g_assert_cmpint(!!ft_isdigit(i), ==, !!isdigit(i));
				g_assert_cmpint(!!ft_isalnum(i), ==, !!isalnum(i));
				g_assert_cmpint(!!ft_isascii(i), ==, !!isascii(i));
				g_assert_cmpint(!!ft_isprint(i), ==, !!isprint(i));
		}
		printf("\033[0;32m  ft_isalpha() successfully passed tests: ASCII(0-128)\033[0m\n");
		usleep(10000);

		printf("\033[0;32m  ft_isdigit() successfully passed tests: ASCII(0-128)\033[0m\n");
		usleep(10000);

		printf("\033[0;32m  ft_isalnum() successfully passed tests: ASCII(0-128)\033[0m\n");
		usleep(10000);

		printf("\033[0;32m  ft_isascii() successfully passed tests: ASCII(0-128)\033[0m\n");
		usleep(10000);

		printf("\033[0;32m  ft_isprint() successfully passed tests: ASCII(0-128)\033[0m\n");
		usleep(10000);
}

void	test_toupper(void)
{
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		g_assert(ft_toupper('b') == toupper('b'));
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
}

void	test_tolower(void)
{
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		g_assert(ft_tolower('B') == tolower('B'));
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
}

void	test_atoi(void)
{
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		g_assert_cmpint(ft_atoi("0"), ==, atoi("0"));
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpint(ft_atoi("+0"), ==, atoi("+0"));
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpint(ft_atoi("-+0"), ==, atoi("-+0"));
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpint(ft_atoi("000"), ==, atoi("000"));
		printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpint(ft_atoi("+-4200"), ==, atoi("+-4200"));
		printf("\033[0;32m %s() successfully passed test #5 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpint(ft_atoi("-+4200"), ==, atoi("-+4200"));
		printf("\033[0;32m %s() successfully passed test #6 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpint(ft_atoi("-42"), ==, atoi("-42"));
		printf("\033[0;32m %s() successfully passed test #7 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpint(ft_atoi("+42"), ==, atoi("+42"));
		printf("\033[0;32m %s() successfully passed test #8 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpint(ft_atoi("42"), ==, atoi("42"));
		printf("\033[0;32m %s() successfully passed test #9 \033[0m\n", __func__);
		usleep(10000);
}

void	test_itoa(void)
{
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);


		g_assert_cmpstr(ft_itoa(42), ==,"42");
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_itoa(-42), ==, "-42");
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_itoa(0), ==, "0");
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_itoa(INT_MIN), ==,"-2147483648");
		printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_itoa(INT_MAX), ==, "2147483647");
		printf("\033[0;32m %s() successfully passed test #5 \033[0m\n", __func__);
		usleep(10000);
}
