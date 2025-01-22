NAME = pipex

SRCS = pipex.c utils.c
SRCS_BONUS = pipex_bonus.c utils.c	
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
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

bonus:
	make -C libft all
	$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o $(NAME)

re_bonus: fclean bonus

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck --trace-children=yes ./$(NAME)

.PHONY: all clean fclean re
