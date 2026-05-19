#include "ramen-barmen-libft-tester.h"
void test_memcpy(void)
{
        char memcpy_str1[11] = "0000000000";
        char memcpy_str2[11] = "1234567890";
         
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

        g_assert(ft_memcpy(memcpy_str1, memcpy_str2, 0) == memcpy_str1);
		g_assert_cmpstr(memcpy_str1, ==, "0000000000");
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

        g_assert(ft_memcpy(memcpy_str1, memcpy_str2, 1) == memcpy_str1);
		g_assert_cmpstr(memcpy_str1, ==, "1000000000");
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

        g_assert(ft_memcpy(memcpy_str1, memcpy_str2, 5) == memcpy_str1);
		g_assert_cmpstr(memcpy_str1, ==, "1234500000");
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);

        g_assert(ft_memcpy(memcpy_str1, memcpy_str2, 11) == memcpy_str1);
		g_assert_cmpstr(memcpy_str1, ==, "1234567890");
		printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
		usleep(80000);
}

void	test_memset(void)
{
		char memset_str[11] = "0000000000";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		g_assert(ft_memset(memset_str, '%', 0) == memset_str);
		g_assert_cmpstr(memset_str, ==, "0000000000");
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

		g_assert(ft_memset(memset_str, '1', 1) == memset_str);
		g_assert_cmpstr(memset_str, ==, "1000000000");
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

		g_assert(ft_memset(memset_str, '*', 5) == memset_str); 
		g_assert_cmpstr(memset_str, ==, "*****00000");
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(80000);
}

void	test_memmove(void)
{
		char memmove_str1[11] = "1234567890";
		char memmove_str2[11] = "0000000000";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		g_assert(ft_memmove(memmove_str2, memmove_str1, 1) == memmove_str2);
		g_assert_cmpstr(memmove_str2, ==, "1000000000");
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

		g_assert(ft_memmove(memmove_str2, memmove_str1, 3) == memmove_str2);
		g_assert_cmpstr(memmove_str2, ==, "1230000000");
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

		g_assert(ft_memmove(memmove_str2, memmove_str1 + 1, 5) == memmove_str2);
		g_assert(ft_memmove(memmove_str2 + 3, memmove_str1 + 2, 4) == memmove_str2 + 3);
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(80000);
}

void	test_memcmp(void)
{
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		g_assert_cmpint(ft_memcmp("Hell", "Helm", 4), ==, memcmp("Hell", "Helm", 4));
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpint(ft_memcmp("Hello", "Hedlo", 0), ==, memcmp("Hello", "Hedlo", 0));
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpint(ft_memcmp("", "", 4), ==, memcmp("", "", 4));
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(80000);
}

void	test_memchr(void)
{
		char memchr_str[] = "Ysup forty two";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		g_assert(ft_memchr(memchr_str, 's', 11) == memchr_str + 1);
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

		g_assert(ft_memchr(memchr_str, 'p', 11) == memchr_str + 3);
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

		g_assert(ft_memchr(memchr_str, 'f', 11) == memchr_str + 5);
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);

		g_assert(ft_memchr(memchr_str, 't', 11) == memchr_str + 8);
		printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
		usleep(80000);
}

void    test_bzero(void)
{
		char bzero_str[11] = "1234567890";
		char bzero_expected[3] = {0, 0, 0};

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		ft_bzero(bzero_str, 3);

		g_assert_cmpmem(bzero_str, 3, bzero_expected, 3);
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(80000);
}

void	test_calloc(void)
{
		int arr[10] = {0};
		size_t arr_size = sizeof(arr);
		size_t arr_len = arr_size / sizeof(*arr);
		void *ptr;

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		ptr = ft_calloc(sizeof(int), arr_len);
		printf("\033[0;32m %s() successfully allocated array of ints\033[0m\n", __func__ );
		usleep(10000);

		g_assert_cmpmem(ptr, arr_size, arr, arr_size);
		printf("\033[0;32m %s() following array compared with hardcoded\033[0m\n", __func__ );
		usleep(10000);

		free(ptr);
		printf("\033[0;32m %s() memory successfully free'd\033[0m\n", __func__ );
		usleep(10000);

		ptr = ft_calloc(sizeof(int), 0);
		printf("\033[0;32m %s() successfully allocated array of ints with length 0\033[0m\n", __func__ );
		usleep(10000);

		g_assert_nonnull(ptr);
		printf("\033[0;32m %s() non-NULL pointer successfully returned\033[0m\n", __func__ );
		usleep(10000);

		free(ptr);
		printf("\033[0;32m %s() memory successfully free'd\033[0m\n", __func__ );
		usleep(10000);

		ptr = ft_calloc(0, arr_size);
		printf("\033[0;32m %s() successfully allocated array of ints with size 0\033[0m\n", __func__ );
		usleep(10000);

		g_assert_nonnull(ptr);
		printf("\033[0;32m %s() non-NULL pointer successfully returned\033[0m\n", __func__ );
		usleep(10000);

		free(ptr);
		printf("\033[0;32m %s() memory successfully free'd\033[0m\n", __func__ );
		usleep(80000);
}
