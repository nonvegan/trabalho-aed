#ifndef FORN_H_
#define FORN_H_

typedef struct {
    int id;
    char nome[50];
} Fornecedor;

int criar_novo_fornecedor(Fornecedor* fornecedor);

void print_lista_fornecedores(Fornecedor* lista_fornecedores, int size);


#endif /* FORN_H_ */
