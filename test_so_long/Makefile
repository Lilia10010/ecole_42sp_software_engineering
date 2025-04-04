NAME := so_long

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -I./includes
RM		:= rm -f

SRCS 	:= ./src/main.c
OBJS 	:= $(SRCS:.c=.c)

LIBFT_DIR	:= ./lib/libft

LIBFT := $(LIBFT_DIR)/liball.a

HEADER := -I ./includes -I $(LIBFT_DIR)


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo ${Q}${NL}${PINK}======= Building libft =======${NC}${Q}
	@$(MAKE) -C $(LIBFT)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re