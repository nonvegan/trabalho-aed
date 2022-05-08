#include "produto.h"

#include "aux.h"
#include <stdio.h>
#include <string.h>

int criar_novo_produto(Produto* produto)
{
    printf("Porfavor insira o nome do produto... ");
    limpar_stdin();
    fgets(produto->nome, 50, stdin);
    produto->nome[strcspn(produto->nome, "\n")] = 0; /* Remover newline */

    printf("\nPorfavor insira o preço do produto... ");
    ler_input("%f", &produto->preco_unitario);

    printf("\nPorfavor insira o codigo do fornecedor... ");
    ler_input("%u", &produto->id_fornecedor);

    printf("\nPorfavor insira a quantidade de stock minimo... ");
    ler_input("%d", &produto->quantidade_minima_stock);

    produto->ativo = 1;

    putchar('\n');

    if (0) { /* Validação de input */
        return -1;
    };

    return 0;
}

void print_lista_produtos(Produto* lista_produtos, int size)
{
    int x = 116;
    while (x--) {
        printf("%c", '#');
    }
    putchar('\n');
    printf("# %*s | %*s | %*s | %*s | %*s | %*s #\n",
        -6, "Código",
        -50, "Nome",
        -10, "Fornecedor",
        -14, "Preço Unitário",
        -5, "Stock",
        -10, "Stock Minímo");

    for (int i = 0; i < size; i++) {
        Produto* produto = lista_produtos + i;
        if (produto->ativo)
            printf("# %*u | %*s | %*u | %*.3f€ | %*d | %*d #\n",
                -6,  produto->id,
                -50, produto->nome,
                -10, produto->id_fornecedor,
                -13, produto->preco_unitario,
                -5,  produto->quantidade_stock,
                -12, produto->quantidade_minima_stock);
    }
    x = 116;
    while (x--) {
        printf("%c", '#');
    }
    printf("\n\n");
}
