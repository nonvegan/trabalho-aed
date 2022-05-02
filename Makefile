C=gcc
NAME=main
SRC=src/main.c
CFLAGS= -ansi -Wall -Wextra -pedantic
LIBS=

$(NAME): $(SRC)
		$(CC) -o $(NAME) $(SRC) $(FLAGS) $(LIBS) -ggdb

run: $(NAME)
		./$(NAME)
