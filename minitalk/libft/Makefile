NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -fPIE

RM = rm -f

SRC =	ft_atoi.c \
		ft_printf.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_puthex.c \
		ft_putptr.c \
		ft_putchar.c \

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re