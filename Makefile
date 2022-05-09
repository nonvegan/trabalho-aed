C=cc
NAME=main
SRC=src/main.c src/produto.c src/fornecedor.c src/movimento.c src/aux.c
CFLAGS= -ansi -Wall -Wextra -pedantic
LIBS=

$(NAME): $(SRC)
		$(CC) -o $(NAME) $(SRC) $(FLAGS) $(LIBS) -ggdb

run: $(NAME)
		./$(NAME)
