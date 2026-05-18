/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milnicki <milnicki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:25:59 by milnicki          #+#    #+#             */
/*   Updated: 2026/05/18 17:09:06 by milnicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <ctype.h>
#include "libft.h"
#include <bsd/string.h>
#include <glib.h>
#include <locale.h>
#include <unistd.h>

const char *ramen_ascii[] = {
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⡀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠋⠉⣿⣤⣤⡾⠏⠛⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨⣿⣳⣿⠡⣠⣄⣚⣿⡟⣗⡄⠐⣈⣻⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⠟⠁⣀⠛⢋⡿⢻⡿⢻⠟⠁⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠛⠉⠉⠉⠉⠓⠶⣶⠲⠖⠒⠛⠒⠛⠒⠓⠓⠒⠒⠒⠶⠿⠶⣿⣿⣶⡿⢁⣾⣿⣄⠀⠀⠀⠀⠀⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⢀⣠⣴⡟⠀⠀⠀⠀⣀⣤⣄⣀⠈⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⢁⡾⠛⢿⠿⣧⣄⡉⠀⠈⠿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⢀⣠⡴⠚⠉⣽⠃⠀⠀⢀⡴⠋⠉⠉⠙⢦⡀⠹⣦⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠀⣀⡴⠋⣠⠞⠁⠀⠈⠀⠉⠙⠳⣦⣀⠠⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⢀⣴⠛⠁⠀⠀⢀⣿⢀⠀⠀⢸⠀⠀⠀⠀⠀⠀⢳⠀⠹⣇⠔⡁⠀⣰⠌⢀⣈⣭⠿⠛⢉⣴⣾⣷⣤⣄⣀⡀⠀⠀⠀⠀⠀⠙⢷⣟⢿⡇⠀⠀⠀⠀⠀⠀⠀⠀",
"⢀⡿⠁⠀⠀⠀⣠⡼⣷⠸⡄⠀⠉⢷⡀⠀⠀⠀⢀⡼⠀⠀⣿⢀⣉⣷⡶⠿⢿⣏⣤⠶⣿⣿⡽⣶⣭⣉⠻⣯⡙⠳⢤⣀⠀⠀⠀⠀⢹⣾⣧⠀⠀⠀⠀⠀⠀⠀⠀",
"⢸⡇⠀⠀⣠⢾⡟⠂⢻⡆⢳⣄⡀⠀⠙⠶⠤⠴⠛⠡⠔⢻⣿⣻⣿⡴⠶⠛⢻⣏⣡⣾⠿⠷⣤⣦⣴⣽⣷⣞⢿⡌⠘⢏⢳⣄⠀⠀⢀⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀",
"⠈⣷⡄⢰⡏⠰⠓⢠⡴⠿⡾⠿⢷⡀⠀⠀⠀⠀⠀⠀⣠⣾⣟⣿⡌⣷⣤⣴⡿⢛⣩⡴⠶⠳⣿⠿⢿⣿⠾⣿⡟⠋⠁⠀⠲⢽⡆⢀⣼⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⣿⣿⣶⣿⣄⠀⠸⣧⣀⣀⣀⣽⣟⣶⠶⡶⢶⣶⣫⣿⣋⣉⣙⣿⠌⣿⢷⡿⢻⡇⠀⠀⠀⠘⣻⠶⣶⠾⠟⢹⠆⠀⠀⢀⣼⣷⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⢻⡌⠻⢿⣿⣷⣶⣬⣍⢻⣏⠻⣿⣟⠻⠿⢛⣻⣧⣌⣉⣉⣭⠟⢠⣿⡐⢿⣆⠻⣦⣀⣀⣴⠟⣠⡟⠀⢀⣀⣤⣴⣾⣿⣿⠟⢁⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⢿⣦⣀⠉⠛⠿⣿⣻⣿⣿⠷⢿⣿⣿⣽⣟⣻⣤⣉⣛⣫⣥⡀⢀⣸⣇⣼⣟⣶⣤⣭⣭⣴⣾⣿⠶⢿⢛⣏⣹⡴⠛⠁⢀⣴⣾⠿⣿⣟⣷⣦⠀⠀⠀⠀⠀⠀",
"⠀⠀⠈⣿⣿⣿⣶⣤⣀⡈⠉⠛⠛⠶⠶⣦⣭⣎⣭⣋⣟⣙⣛⣛⣻⣛⣛⣛⣏⣻⣍⣯⣭⣱⡶⠶⠿⠓⠛⠋⠉⣀⡄⠀⣠⣟⣾⠃⠀⠈⠙⠛⠁⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠈⠻⣿⣷⢯⡿⣽⢿⣶⣶⡲⣤⠤⣄⣀⣀⣁⣈⣉⡉⠉⠁⠉⠉⠉⣈⣁⣈⣀⣀⣀⡤⣤⠴⣲⠒⣏⣿⠏⠀⡴⣧⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠙⢿⣿⣽⣻⣟⣮⣟⣷⡌⢳⡘⢬⢲⡡⢎⠭⣙⠏⢯⡹⢭⡙⢥⠚⡔⡣⣜⢡⠞⣠⢛⡤⢯⡴⢬⡷⣞⣷⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠙⢷⣿⣟⣾⡽⣾⢿⡆⡝⣆⠣⡜⣡⢋⢆⡛⢦⠱⢦⡙⢦⠛⣬⠱⡌⠮⡜⢥⣋⡜⢯⣤⣞⣵⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⣯⣿⣯⣟⣿⣶⣌⠳⡜⢤⢋⠦⡙⢦⡙⠦⡙⢦⠹⢤⠓⣍⠞⡸⢆⡱⢎⣽⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⠛⠻⣿⣾⣿⣷⣯⡘⢣⠞⡲⢩⠦⣙⠲⣍⠲⡙⢦⡙⢦⣩⣵⣾⠿⡟⢣⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡄⠠⠰⠘⢿⣿⣿⡿⣿⣷⣮⣵⣧⣾⣤⣷⣬⣧⣽⣶⣿⣿⣿⣿⠃⢃⠀⠂⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣄⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣍⡀⠂⠌⠛⢿⣿⣿⣿⣽⣯⣿⣽⣯⣿⣽⣿⣽⣷⣿⠿⠋⠡⠈⠁⠈⠼⠃⢀⣀⣠⣤⠤⠶⠶⠚⠛⠋⠉⠉⠀⠀⣐⣿⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠳⠦⣔⣀⠊⠉⠉⠛⠛⠛⠿⠻⠟⠟⠻⠛⠛⠩⠙⣀⣂⣤⣤⣶⠶⠶⠒⠚⠋⠉⠉⠀⠀⢀⣀⣀⣴⣤⣶⠶⠶⢿⡟⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠉⠐⠀⠉⠐⢠⣥⣬⣭⠶⠷⠞⠛⠋⠉⠉⣀⣀⣀⣠⣒⣤⣥⣬⠶⠶⢿⠛⠻⠭⠉⠁⠀⠀⠈⠉⠀⣀⣀⣤⡀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣤⡤⠤⠶⠒⠛⠋⢉⠉⣁⣀⣠⣤⣤⣴⠶⠾⠾⠟⠛⠛⠙⠉⠉⠀⠀⢀⣀⣀⣠⣤⠤⠤⠶⠖⠚⠛⠛⠉⠉⠉⠁⢀⣿",
"⠀⠀⠀⠀⠀⠀⠀⠀⢀⣶⠛⠛⠉⢉⣀⣀⣠⣤⣤⣴⠶⠾⠛⠛⠛⠉⠉⠀⠀⣀⣀⣀⣤⣤⡤⠶⠶⠖⠚⠛⠋⠉⠉⠁⠀⢀⣀⣠⣤⣠⣤⣤⣤⡶⠶⠿⠟⣛⡏",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⠶⠛⠛⠋⠉⠉⣁⣀⣀⣄⡤⡤⠤⠶⠖⠒⠚⠛⠉⠉⢉⡀⣀⣀⣠⣤⣤⣤⣴⠶⠶⠷⠟⠾⠛⠛⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⠖⠚⠛⠉⠉⠉⣁⣀⣤⣄⣠⣤⣤⣴⠶⠶⠶⠛⠛⠛⠋⠙⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⠶⠶⠞⠛⠛⠛⠛⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
NULL
};

void
			ramen(void)
{
	for(int i = 0; ramen_ascii[i] != NULL; i++)
	{
		printf("%s\n", ramen_ascii[i]);
		fflush(stdout);
		usleep(10000);
	}	
	sleep(1);
}

void clear_screen() {
    printf("\033[2J\033[H");
}
void
		test_ft_strlen(void)
{
		char	*ft_strlen_str1 = "String";
		char	*ft_strlen_str2 = "";
		char	*ft_strlen_str3 = "c";
		char	*ft_strlen_str4 = "\n\r\v\f";

	printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		g_assert_cmpuint(ft_strlen(ft_strlen_str1), ==, strlen(ft_strlen_str1)); 
			printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpuint(ft_strlen(ft_strlen_str2), ==, strlen(ft_strlen_str2)); 
			printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpuint(ft_strlen(ft_strlen_str3), ==, strlen(ft_strlen_str3)); 
			printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpuint(ft_strlen(ft_strlen_str4), ==, strlen(ft_strlen_str4)); 
			printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
		usleep(80000);
}

void    
		test_memcpy(void)
{
        char memcpy_str1[11] = "0000000000";
        char memcpy_str2[11] = "1234567890";
         
	printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
        g_assert(ft_memcpy(memcpy_str1, memcpy_str2, 0) == memcpy_str1);
			printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
        g_assert(ft_memcpy(memcpy_str1, memcpy_str2, 1) == memcpy_str1);
			printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);
        g_assert(ft_memcpy(memcpy_str1, memcpy_str2, 5) == memcpy_str1);
			printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);
        g_assert(ft_memcpy(memcpy_str1, memcpy_str2, 11) == memcpy_str1);
			printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
		usleep(80000);
}

void    
		test_memset(void)
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

void
		test_memmove(void)
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
		usleep(10000);
}

void
		test_memcmp(void)
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
		usleep(10000);
}

void
		test_memchr(void)
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
		usleep(10000);
}
void
		test_classification_functions(void)
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
void
		test_calloc(void)
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
		usleep(10000);
}

void
		test_toupper(void)
{
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		usleep(10000);
		g_assert(ft_toupper('b') == toupper('b'));
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
}

void
		test_tolower(void)
{
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		usleep(10000);
		g_assert(ft_tolower('B') == tolower('B'));
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
}
void
		test_strchr(void)
{
		const char strchr_str[] = "Ysup forty two";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		usleep(10000);
		g_assert(ft_strchr(strchr_str, 'Y') == strchr_str);
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
		g_assert(ft_strchr(strchr_str, 'p') == strchr_str + 3);
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);
		g_assert(ft_strchr(strchr_str, 'w') == strchr_str + 12);
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);
}
void
		test_strrchr(void)
{
		const char strrchr_str[] = "Ysup forty two";
		
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		usleep(10000);
		g_assert(ft_strrchr(strrchr_str, 'Y') == strrchr_str);
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
		g_assert(ft_strrchr(strrchr_str, 'p') == strrchr_str + 3);
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);
		g_assert(ft_strrchr(strrchr_str, 'w') == strrchr_str + 12);
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);
}

void
		test_strlcat(void)
{
		const char *strlcat_src = "Hello";
		char strlcat_dst[] = "World";
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		usleep(10000);
		g_assert(ft_strlcat(strlcat_dst, strlcat_src, 5) == 10);
		g_assert_cmpstr(strlcat_dst, ==, "World");
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
		g_assert(ft_strlcat(strlcat_dst, strlcat_src, 2) == 7);
		g_assert_cmpstr(strlcat_dst, ==, "Wo");
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);
		g_assert(ft_strlcat(strlcat_dst, strlcat_src, 0) == 5);
		g_assert_cmpstr(strlcat_dst, ==, "Wo");
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);
}
void
		test_strlcpy(void)
{
		const char *strlcpy_src = "Hello";
		char strlcpy_dst[] = "World";
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		usleep(10000);
		ft_strlcpy(strlcpy_dst, strlcpy_src, 3);
		g_assert_cmpstr(strlcpy_dst, ==, "He");
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
		ft_strlcpy(strlcpy_dst, strlcpy_src, 6);
		g_assert_cmpstr(strlcpy_dst, ==, "Hello");
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);
		ft_strlcpy(strlcpy_dst, strlcpy_src, 0);
		g_assert_cmpstr(strlcpy_dst, ==, "Hello");
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);
}

void
		test_atoi(void)
{
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		usleep(10000);
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

void
		test_strnstr(void)
{
		const char *strnstr_haystack = "somehow somewhere it works, but why ?";
		const char *strnstr_needle = "but";
		const char *wrong_strnstr_needle = "butter";
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpstr(ft_strnstr(strnstr_haystack, strnstr_needle, 40), ==, strnstr(strnstr_haystack, strnstr_needle, 40));
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpstr(ft_strnstr(strnstr_haystack, strnstr_needle, 0), ==, strnstr(strnstr_haystack, strnstr_needle, 0));
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpstr(ft_strnstr(strnstr_haystack, wrong_strnstr_needle, 40), ==, strnstr(strnstr_haystack, wrong_strnstr_needle, 40));
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpstr(ft_strnstr(strnstr_haystack, wrong_strnstr_needle, 10), ==, strnstr(strnstr_haystack, wrong_strnstr_needle, 10));
		printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
		usleep(10000);
}
void
		test_strncmp(void)
{
		/*strncmp*/
		const char *strncmp_str1 = "forty boo";
		const char *strncmp_str2 = "forty two";
		const char *strncmp_str3 = "forty";
		const char *strncmp_str4 = "forty @o";
		const char *strncmp_str5 = "";
		const char *strncmp_str6 = "for two";
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpint(ft_strncmp(strncmp_str1, strncmp_str2, 5), ==, strncmp(strncmp_str1, strncmp_str2, 5));
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpint(ft_strncmp(strncmp_str3, strncmp_str4, 10), ==, strncmp(strncmp_str3, strncmp_str4, 10));
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpint(ft_strncmp(strncmp_str3, strncmp_str4, 1), ==, strncmp(strncmp_str3, strncmp_str4, 1));
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpint(ft_strncmp(strncmp_str5, strncmp_str6, 7), ==, strncmp(strncmp_str5, strncmp_str6, 7));
		printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpint(ft_strncmp(strncmp_str5, strncmp_str6, 1), ==, strncmp(strncmp_str5, strncmp_str6, 1));
		printf("\033[0;32m %s() successfully passed test #5 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpint(ft_strncmp(strncmp_str5, strncmp_str6, 0), ==, strncmp(strncmp_str5, strncmp_str6, 0));
		printf("\033[0;32m %s() successfully passed test #6 \033[0m\n", __func__);
		usleep(10000);
}

void
		test_strdup(void)
{
		const char *strdup_str1 = "source string";
		const char *strdup_str2 = "";
		const char *strdup_str3 = "0000000000";
		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpstr(ft_strdup(strdup_str1), ==, strdup(strdup_str1));
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpstr(ft_strdup(strdup_str2), ==, strdup(strdup_str2));
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);
		g_assert_cmpstr(ft_strdup(strdup_str3), ==, strdup(strdup_str3));
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);
}

void
		test_substr(void)
{
		char *substr_str1 = "holy forty two six six six";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		g_assert_cmpstr(ft_substr(substr_str1, 15, 11), ==, "six six six");
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		g_assert_cmpstr(ft_substr(substr_str1, 19, 7), ==, "six six");
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		g_assert_cmpstr(ft_substr(NULL, 19, 7), ==, NULL);
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		g_assert_cmpstr(ft_substr(substr_str1, 48, 0), ==, "");
		printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
		g_assert_cmpstr(ft_substr(substr_str1, 0, 8), ==, "holy for");
		printf("\033[0;32m %s() successfully passed test #5 \033[0m\n", __func__);
		g_assert_cmpstr(ft_substr(substr_str1, 15, 500), ==, "six six six");
		printf("\033[0;32m %s() successfully passed test #6 \033[0m\n", __func__);
}

void
		test_strjoin(void)
{
	char *strjoin_str1 = "merge";
	char *strjoin_str2 = "42424242";
	printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
	g_assert_cmpstr(ft_strjoin(strjoin_str1, strjoin_str2), ==, "merge42424242");
	printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
	g_assert_cmpstr(ft_strjoin("", ""), ==, "");
	printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
	g_assert_cmpstr(ft_strjoin(strjoin_str1+2, strjoin_str2), ==, "rge42424242");
	printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
}

void
		test_strtrim(void)
{
	char *strtrim_str1 = "-------to+++remove-----"; 
	char *strtrim_str2 = "ahahahto+++removeahahah";
	char *strtrim_str3 = "miamia++++++moremoremia";
	char *strtrim_str4 = "";
	
	printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
	g_assert_cmpstr(ft_strtrim(strtrim_str1, "-"), ==, "to+++remove");
	printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
	g_assert_cmpstr(ft_strtrim(strtrim_str2, "ah"), ==, "to+++remove");
	printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
	g_assert_cmpstr(ft_strtrim(strtrim_str3, "mia"), ==, "++++++moremore");
	printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
	g_assert_cmpstr(ft_strtrim(strtrim_str4, ""), ==, "");
	printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
	g_assert_cmpstr(ft_strtrim("", "a"), ==, "");
	printf("\033[0;32m %s() successfully passed test #5 \033[0m\n", __func__);
}

int	main(void)
{
		clear_screen();
		ramen();
		test_ft_strlen();
		test_memcpy();
		test_memset();
		test_bzero();
		test_memmove();
		test_memcmp();
		test_memchr();
		test_classification_functions();
		test_calloc();
		test_tolower();
		test_toupper();
		test_strchr();
		test_strrchr();
		test_strlcat();
		test_strlcpy();
		test_atoi();
		test_strnstr();
		test_strncmp();
		test_strdup();
		test_substr();
		test_strjoin();
		test_strtrim();
		printf("\033[0;32mAll tests passed!\033[0m\n");
		sleep(6);
		clear_screen();
		printf("\033[0;32mWINNER WINNER CHICKEN DINNER !!!\033[0m\n");
		return (0);
}

