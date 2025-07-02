CFILES = ft_putchar.c \
	ft_putnbrbase.c \
	ft_printf.c	\
	ft_putxp.c


NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

OFILES = $(CFILES:.c=.o)

all : $(NAME)

$(NAME) : $(OFILES)
	ar -rcs $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

