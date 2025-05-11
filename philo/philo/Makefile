NAME := philo

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pthread
RM		:= rm -f

SRC_DIR := src
SRCS	:= $(SRC_DIR)/main.c $(SRC_DIR)/utils.c  $(SRC_DIR)/forks.c $(SRC_DIR)/init.c $(SRC_DIR)/monitor.c $(SRC_DIR)/routine.c $(SRC_DIR)/philosopher.c
OBJ_DIR := obj
OBJ		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

HEADER := -I ./includes


YELLOW	:= \033[1;33m
GREEN	:= \033[1;32m
BLUE	:= \033[1;34m
RED		:= \033[1;31m
RESET	:= \033[0m
NL		:= \n


all: $(NAME)
#	@echo -e "Horário do sistema:"
#	@date
#	@echo -e "Horário do sistema de arquivos (modificação do arquivo main.c):"
#	@stat $(SRC_DIR)/main.c | grep Modify

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo -e "$(NL)$(GREEN)Build completed successfully: $(NAME)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS)  -c $< $(HEADER) -o $@
	@echo -e  "$(YELLOW)Compiling source file:$(RESET) $(notdir $<)"

clean:
	@echo -e "$(NL)$(RED)Removing object files:$(RESET) $(OBJ)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo -e "$(RED)Removing executable:$(RESET) $(NAME)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
