SOURCES = main.c \
		  memory.c \
		  string_manipulation.c \
		  typec.c

OBJS        = $(SRCS:.c=.o)

LIBFT_FOLDER = ../libft
LIBFT_NAME = libft.a

OBJECTS = $(SOURCES:.c=.o)

NAME = ramen-barmen-libft-tester.a 

CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFT_FOLDER) $(shell pkg-config --cflags glib-2.0)
LDFLAGS = -L$(LIBFT_FOLDER) -lft -lbsd $(shell pkg-config --libs glib-2.0)

all: $(NAME)
	./$(NAME)
       
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJECTS): %.o: %.c
	cc -c $(CFLAGS) $^ -o $@

$(NAME): $(LIBFT_FOLDER)/$(LIBFT_NAME) $(OBJECTS)
	cc -o $(NAME) $(OBJECTS) $(LDFLAGS)

$(LIBFT_FOLDER)/$(LIBFT_NAME): FORCE
	make -C $(LIBFT_FOLDER)
FORCE: 

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_FOLDER) fclean

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_FOLDER) clean

re: fclean all
