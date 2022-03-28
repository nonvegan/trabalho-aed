C=gcc
NAME=main
SRC=src/main.c
CFLAGS= -ansi -Wall -Wextra -pedantic
LIBS=
PKGS=

$(NAME): $(SRC)
		$(CC) -o $(NAME) $(SRC) $(FLAGS) $(LIBS) `pkg-config --libs $(PKGS)` -ggdb

run: $(NAME)
		./$(NAME)
