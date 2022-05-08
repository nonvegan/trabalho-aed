#ifndef MOV_H_
#define MOV_H_

#include "aux.h"

#define ENTRADA_PRODUTO 0
#define SAIDA_PRODUTO 1

typedef struct {
    unsigned int id;
    unsigned int id_produto;
    unsigned int tipo;
    unsigned int quantidade;
    Data data;
} Movimento;

void print_movimento(Movimento* mov);

#endif /* MOV_H_ */
