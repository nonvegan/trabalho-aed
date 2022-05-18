#ifndef PROD_H_
#define PROD_H_

#include "fornecedor.h"

typedef struct {
    int id;
    int id_fornecedor;
    char nome[50];
    float preco_unitario;
    int quantidade_stock;
    int quantidade_minima_stock;
    int removido;
} Produto;

int criar_novo_produto(Produto* produto, const int contador_fornecedores);

int editar_produto(Produto* produto, const int contador_fornecedores);

void print_lista_produtos(Produto* lista_produtos, int size, Fornecedor* lista_fornecedores);

void print_lista_produtos_fornecedor(Produto* lista_produtos, int size,
                                     Fornecedor* lista_fornecedores, int id_fornecedor);

void print_lista_produtos_falta_stock(Produto* lista_produtos, int size, Fornecedor* lista_fornecedores);

#endif /* PROD_H_ */
