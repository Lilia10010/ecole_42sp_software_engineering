NAME = pipex

# directories
SRC_DIR = src
OBJ_DIR = obj
UTILS_DIR = $(SRC_DIR)/utils
INCLUDE_DIR = include
LIBFT_DIR = libft

# files
SRCS = $(SRC_DIR)/pipex.c\
		$(UTILS_DIR)/error.c $(UTILS_DIR)/print_hello.c 
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT = $(LIBFT_DIR)/libft.a

# compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)
RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# compilation rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# compilation lib
$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

#libft:
#	make -C libft

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck ./$(NAME)

.PHONY: all clean fclean re
