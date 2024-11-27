NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c \
	ft_putptr_fd.c ft_putstr_fd.c ft_putunsigned_int_fd.c ft_putnbr_hex_fd.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

#VERIFICAR
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re