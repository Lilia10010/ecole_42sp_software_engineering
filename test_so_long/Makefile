NAME := so_long

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -I./includes
RM		:= rm -f

SRCS 		:= ./src/main.c
OBJS 		:= $(SRCS:.c=.o)
LIBFT_DIR	:= ./lib/libft
LIBFT 		:= $(LIBFT_DIR)/liball.a
HEADER 		:= -I ./includes -I $(LIBFT_DIR)

# Cores do terminal
NC		:= \033[0m
YELLOW	:= \033[1;33m
GREEN	:= \033[1;32m
BLUE	:= \033[1;34m
RED		:= \033[1;31m
NL		:= \n

# Mensagens
MSG_COMP	:= $(YELLOW)======= Compilando $(NAME) =======$(NC)
MSG_COMPT	:= $(BLUE)======= Inicialiando compilação vrauu =======$(NC)
MSG_LIBFT	:= $(YELLOW)======= Compilando libft =======$(NC)
MSG_CLEAN	:= $(RED)======= Removendo arquivos objeto =======$(NC)
MSG_FCLEAN	:= $(RED)======= Removendo executável =======$(NC)
MSG_SUCCESS	:= $(GREEN)======= Compilação completa! =======$(NC)



all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo -e "${NL}${MSG_COMP}${NL}"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo -e "${NL}${MSG_SUCCESS}${NL}"

%.o: %.c
	@echo -e "${NL}${MSG_COMPT}${NL}"
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo -e "${NL}${MSG_LIBFT}${NL}"
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo -e "${NL}${MSG_CLEAN}${NL}"
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo -e "${NL}${MSG_FCLEAN}${NL}"
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re