#ifndef PROD_H_
#define PROD_H_

typedef struct {
    unsigned int id;
    unsigned int id_fornecedor;
    char nome[50];
    float preco_unitario;
    int quantidade_stock;
    int quantidade_minima_stock;
    int removido;
} Produto;

int criar_novo_produto(Produto* produto);

int editar_produto(Produto* produto);

void print_lista_produtos(Produto* lista_produtos, int size);

#endif /* PROD_H_ */
