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

void clear_screen() {
		printf("\033[2J\033[H");
}

int	main(void)
{
		clear_screen();
		test_strlen();
		/* test_memcpy(); */
		/* test_memset(); */
		/* test_bzero(); */
		/* test_memmove(); */
		/* test_memcmp(); */
		/* test_memchr(); */
		/* test_classification_functions(); */
		/* test_calloc(); */
		/* test_tolower(); */
		/* test_toupper(); */
		test_strchr();
		test_strrchr();
		test_strlcat();
		test_strlcpy();
		/* test_atoi(); */
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

