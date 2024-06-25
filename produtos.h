#ifndef PRODUTOS_H_INCLUDED
#define PRODUTOS_H_INCLUDED

#include <stdio.h> 

typedef struct {
    char nome[100];
    float valor;
} Produto;

extern Produto produtos[50]; 
extern int contador_de_produtos;

void cadastro_produto();
void listar_produtos();
void editar_produto();
void excluir_produto();

#endif // PRODUTOS_H_INCLUDED
