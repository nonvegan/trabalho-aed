C=gcc
NAME=main
SRC=src/main.c src/produto.c src/fornecedor.c src/movimento.c src/auxiliar.c
CFLAGS= -ansi -Wall -Wextra -pedantic -ggdb

$(NAME): $(SRC)
		$(CC) -o $(NAME) $(SRC) $(FLAGS)

run: $(NAME)
		./$(NAME)
