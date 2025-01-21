NAME = pipex
# NAME_BONUS = pipex_bonus

# files
SRCS = pipex.c utils.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

# compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# compilation rules
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# compilation lib
$(LIBFT):
	make -C libft all

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck --trace-children=yes ./$(NAME)

.PHONY: all clean fclean re
