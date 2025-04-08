# Variáveis
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
AR		:= ar rcs
RM		:= rm -f

# Arquivos e diretórios
NAME		:= libft.a
LIBFT_DIR	:= libft
GNL_DIR		:= get_next_line
PRINTF_DIR	:= ft_printf
OBJ_DIR		:= obj

LIBFT_SRCS 	:= $(wildcard $(LIBFT_DIR)/*.c)
GNL_SRCS	:= $(wildcard $(GNL_DIR)/*.c)
PRINTF_SRCS	:= $(wildcard $(PRINTF_DIR)/*.c)

LIBFT_OBJS = $(patsubst $(LIBFT_DIR)/%.c,$(OBJ_DIR)/libft/%.o,$(LIBFT_SRCS))
GNL_OBJS = $(patsubst $(GNL_DIR)/%.c,$(OBJ_DIR)/get_next_line/%.o,$(GNL_SRCS))
PRINTF_OBJS = $(patsubst $(PRINTF_DIR)/%.c,$(OBJ_DIR)/ft_printf/%.o,$(PRINTF_SRCS))

OBJS = $(LIBFT_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)

# Regras
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/libft/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/libft
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/get_next_line/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/get_next_line
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/ft_printf/%.o: $(PRINTF_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/ft_printf
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
