NAME = push_swap

SRCS = push_swap.c handle_error.c handle_free.c init_a_to_b.c init_b_to_a.c sort_stack_with_aux.c sort_three.c ft_split.c stack_init.c stack_utils.c swap.c push.c rev_rotate.c rotate.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
