CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGET = main
SRCS = main.c array_utils.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./your_program [program_arguments]