NAME = push_swap

LIBFT = libft/libft.a
SRCS = push_swap.c handle_error.c handle_free.c init_a_to_b.c init_b_to_a.c operations.c sort_stack_with_aux.c \
	sort_three.c sort_ultis.c split.c stack_init.c stack_utils.c swap.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -Wno-unused-function -Wno-unused-parameter
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft all

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
