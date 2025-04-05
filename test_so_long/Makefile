NAME := so_long

CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -I./includes
RM			:= rm -f
MLX_FLAGS	:= -ldl -lglfw -pthread -lm

SRCS 		:= ./src/main.c
LIBFT_DIR	:= ./lib/libft
MLX_DIR		:= lib/MLX42
OBJ_DIR		:= obj
OBJ			:= $(patsubst ./src/%.c, $(OBJ_DIR)/%.o, $(SRCS))

HEADER 		:= -I ./includes -I $(LIBFT_DIR)
LIBFT 		:= $(LIBFT_DIR)/liball.a
MLX			:= $(MLX_DIR)build/libmlx42.a

NC		:= \033[0m
YELLOW	:= \033[1;33m
GREEN	:= \033[1;32m
BLUE	:= \033[1;34m
RED		:= \033[1;31m
NL		:= \n

MSG_COMP	:= $(YELLOW)======= Compilando $(NAME) =======$(NC)
MSG_COMPT	:= $(BLUE)======= Inicialiando compilação vrauu =======$(NC)
MSG_LIBFT	:= $(YELLOW)======= Compilando libft =======$(NC)
MSG_MLX42	:= $(YELLOW)======= Compilando MLX42 =======$(NC)
MSG_CLEAN	:= $(RED)======= Removendo arquivos objeto =======$(NC)
MSG_FCLEAN	:= $(RED)======= Removendo executável =======$(NC)
MSG_SUCCESS	:= $(GREEN)======= Compilação completa! =======$(NC)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo -e "${NL}${MSG_COMP}${NL}"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(MLX_FLAGS)
	@echo -e "${NL}${MSG_SUCCESS}${NL}"

$(OBJ_DIR)/%.o: ./src/%.c
	@mkdir -p $(OBJ_DIR)
	@echo -e "${NL}${MSG_COMPT}${NL}"
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo -e "${NL}${MSG_LIBFT}${NL}"
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@echo -e "${NL}${MSG_MLX42}${NL}"
	@cmake $(MLX_DIR) -B $(MLX_DIR)build && make -C $(MLX_DIR)build -j4

clean:
	@echo -e "${NL}${MSG_CLEAN}${NL}"
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo -e "${NL}${MSG_FCLEAN}${NL}"
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(MLX_DIR)build fclean

re: fclean all

.PHONY: all clean fclean re