NAME := philo

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pthread
RM		:= rm -f

SRC_DIR := src
SRCS	:= $(SRC_DIR)/main.c
OBJ_DIR := obj
OBJ		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

HEADER := -I ./includes

NC		:= \033[0m
YELLOW	:= \033[1;33m
GREEN	:= \033[1;32m
BLUE	:= \033[1;34m
RED		:= \033[1;31m
NL		:= \n

MSG_COMP_SRC := $(BLUE)======= Compilando arquivos fonte =======$(NC)
MSG_OBJ_DONE := $(GREEN)======= Arquivos objeto gerados! =======$(NC)
MSG_LINK     := $(YELLOW)======= Linkando executável $(NAME) =======$(NC)
MSG_EXE_DONE := $(GREEN)======= Executável $(NAME) gerado! =======$(NC)
MSG_CLEAN    := $(RED)======= Removendo arquivos objeto =======$(NC)
MSG_FCLEAN   := $(RED)======= Removendo executável =======$(NC)

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e  "${NL}${MSG_LINK}${NL}"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo -e  "${NL}${MSG_EXE_DONE}${NL}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo -e  "${NL}${MSG_COMP_SRC}${NL}"
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
	@echo -e  "${NL}${MSG_OBJ_DONE}${NL}"

clean:
	@echo -e  "${NL}${MSG_CLEAN}${NL}"
	rm -rf ${OBJ_DIR}

fclean: clean
	@echo -e  "${NL}${MSG_FCLEAN}${NL}"
	$(RM) $(NAME)
	@echo -e "${NL}"

re: fclean all

.PHONY: all clean fclean re
