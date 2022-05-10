#include "fornecedor.h"

#include <stdio.h>
#include <string.h>

#include "aux.h"

int criar_novo_fornecedor(Fornecedor* fornecedor)
{
    printf("Porfavor insira o nome do fornecedor... ");
    limpar_stdin();
    fgets(fornecedor->nome, 50, stdin);
    fornecedor->nome[strcspn(fornecedor->nome, "\n")] = 0; /* Remover newline */

    return 0;
}

void print_lista_fornecedores(Fornecedor* lista_fornecedores, int size)
{
    int x = 63, i;
    while (x--) {
        printf("%c", '#');
    }
    putchar('\n');
    printf("# %*s | %*s #\n",
            -6, "Código",
            -50, "Nome");

    for (i = 0; i < size; i++) {
        Fornecedor* fornecedor = lista_fornecedores + i;
        printf("# %*u | %*s #\n",
                -6, fornecedor->id,
                -50, fornecedor->nome);
        x = 63;
    }
    while (x--) {
        printf("%c", '#');
    }
    printf("\n");
}
