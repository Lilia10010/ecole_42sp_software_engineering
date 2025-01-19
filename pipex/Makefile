NAME = pipex

# files
SRCS = pipex.c pipex.h utils.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

# compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# compilation rules
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# compilation lib
$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

#libft:
#	make -C libft

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck ./$(NAME)

.PHONY: all clean fclean re
