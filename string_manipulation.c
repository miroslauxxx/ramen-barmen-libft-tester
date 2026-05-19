#include "ramen-barmen-libft-tester.h"

void	test_strlen(void)
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

void	test_strchr(void)
{
		const char strchr_str[] = "Ysup forty two";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);
		g_assert(ft_strchr(strchr_str, 'Y') == strchr_str);
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

		g_assert(ft_strchr(strchr_str, 'p') == strchr_str + 3);
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

		g_assert(ft_strchr(strchr_str, 'w') == strchr_str + 12);
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(80000);
}

void	test_strrchr(void)
{
		const char strrchr_str[] = "Ysup forty two";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		g_assert(ft_strrchr(strrchr_str, 'Y') == strrchr_str);
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

		g_assert(ft_strrchr(strrchr_str, 'p') == strrchr_str + 3);
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

		g_assert(ft_strrchr(strrchr_str, 'w') == strrchr_str + 12);
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(80000);
}

void    test_strlcat(void)
{
        char strlcat_dst[10] = "World";
        char strlcat_dst1[13] = "bakery";
        char strlcat_dst3[13] = "bakery";
        char strlcat_dst4[13] = "bakery";

        printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

        g_assert(ft_strlcat(strlcat_dst, "Hello", 5) == 10);
        g_assert_cmpstr(strlcat_dst, ==, "World");
        printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
        usleep(10000);

        g_assert(ft_strlcat(strlcat_dst1, "memory", 13) == 12);
        g_assert_cmpstr(strlcat_dst1, ==, "bakerymemory");
        printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
        usleep(10000);

        g_assert(ft_strlcat(strlcat_dst3, "memory", 0) == 6);
        g_assert_cmpstr(strlcat_dst3, ==, "bakery");
        printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
        usleep(10000);

        g_assert(ft_strlcat(strlcat_dst4, "memory", 9) == 12);
        g_assert_cmpstr(strlcat_dst4, ==, "bakeryme");
        printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
        usleep(80000);
}
void    test_strlcpy(void)
{
        char strlcpy_dst1[10] = "World";
        char strlcpy_dst2[10] = "World";
        char strlcpy_dst3[10] = "World";

        printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

        g_assert(ft_strlcpy(strlcpy_dst1, "Hello", 3) == 5);
        g_assert_cmpstr(strlcpy_dst1, ==, "He");
        printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
        usleep(10000);

        g_assert(ft_strlcpy(strlcpy_dst2, "Hello", 6) == 5);
        g_assert_cmpstr(strlcpy_dst2, ==, "Hello");
        printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
        usleep(10000);

        g_assert(ft_strlcpy(strlcpy_dst3, "Hello", 0) == 5);
        g_assert_cmpstr(strlcpy_dst3, ==, "World");
        printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
        usleep(80000);
}

void	test_strnstr(void)
{
		const char *strnstr_haystack = "somehow somewhere it works, but why ?";
		const char *strnstr_needle = "but";
		const char *wrong_strnstr_needle = "butter";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

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
		usleep(80000);
}

void	test_strncmp(void)
{
		const char *strncmp_str1 = "forty boo";
		const char *strncmp_str2 = "forty two";
		const char *strncmp_str3 = "forty";
		const char *strncmp_str4 = "forty @o";
		const char *strncmp_str5 = "";
		const char *strncmp_str6 = "for two";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

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
		usleep(80000);
}

void	test_strdup(void)
{
		const char *strdup_str1 = "source string";
		const char *strdup_str2 = "";
		const char *strdup_str3 = "0000000000";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		g_assert_cmpstr(ft_strdup(strdup_str1), ==, strdup(strdup_str1));
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_strdup(strdup_str2), ==, strdup(strdup_str2));
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_strdup(strdup_str3), ==, strdup(strdup_str3));
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(80000);
}

void	test_substr(void)
{
		char *substr_str1 = "holy forty two six six six";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		g_assert_cmpstr(ft_substr(substr_str1, 15, 11), ==, "six six six");
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_substr(substr_str1, 19, 7), ==, "six six");
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_substr(NULL, 19, 7), ==, NULL);
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_substr(substr_str1, 48, 0), ==, "");
		printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_substr(substr_str1, 0, 8), ==, "holy for");
		printf("\033[0;32m %s() successfully passed test #5 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_substr(substr_str1, 15, 500), ==, "six six six");
		printf("\033[0;32m %s() successfully passed test #6 \033[0m\n", __func__);
		usleep(80000);
}

void	test_strjoin(void)
{
		char *strjoin_str1 = "merge";
		char *strjoin_str2 = "42424242";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		g_assert_cmpstr(ft_strjoin(strjoin_str1, strjoin_str2), ==, "merge42424242");
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_strjoin("", ""), ==, "");
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_strjoin(strjoin_str1+2, strjoin_str2), ==, "rge42424242");
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(80000);
}

void	test_strtrim(void)
{
		char *strtrim_str1 = "-------to+++remove-----"; 
		char *strtrim_str2 = "ahahahto+++removeahahah";
		char *strtrim_str3 = "miamia++++++moremoremia";
		char *strtrim_str4 = "";

		printf("\t\033[0;35m>>> \033[0m%s()\033[0;35m <<<\033[0m\n", __func__);

		g_assert_cmpstr(ft_strtrim(strtrim_str1, "-"), ==, "to+++remove");
		printf("\033[0;32m %s() successfully passed test #1 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_strtrim(strtrim_str2, "ah"), ==, "to+++remove");
		printf("\033[0;32m %s() successfully passed test #2 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_strtrim(strtrim_str3, "mia"), ==, "++++++moremore");
		printf("\033[0;32m %s() successfully passed test #3 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_strtrim(strtrim_str4, ""), ==, "");
		printf("\033[0;32m %s() successfully passed test #4 \033[0m\n", __func__);
		usleep(10000);

		g_assert_cmpstr(ft_strtrim("", "a"), ==, "");
		printf("\033[0;32m %s() successfully passed test #5 \033[0m\n", __func__);
		usleep(80000);
}
