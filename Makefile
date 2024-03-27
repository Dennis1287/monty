
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -D_POSIX_C_SOURCE=200809L
SRC = main.c opcodes_1.c opcodes_2.c
OBJ = $(SRC:.c=.o)
EXEC = monty

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re

