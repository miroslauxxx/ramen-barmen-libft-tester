#ifndef RAMEN_BARMEN_FT_H
# define RAMEN_BARMEN_FT_H

#include <stdio.h>
#include <ctype.h>
#include "libft.h"
#include <bsd/string.h>
#include <glib.h>
#include <locale.h>
#include <unistd.h>

/*memory*/
void	test_memcpy(void);
void	test_memset(void);
void	test_memmove(void);
void	test_memcmp(void);
void	test_memchr(void);
void    test_bzero(void);
void	test_calloc(void);

/*typec*/
void	test_classification_functions(void);
void	test_toupper(void);
void	test_tolower(void);
void	test_atoi(void);
void	test_itoa(void);

/*string manipulation*/
void	test_strlen(void);
void	test_strchr(void);
void	test_strrchr(void);
void	test_strlcat(void);
void	test_strlcpy(void);
void	test_strnstr(void);
void	test_strncmp(void);
void	test_strdup(void);
void	test_substr(void);
void	test_strjoin(void);
void	test_strtrim(void);

/*linked lists*/

#endif
