#ifndef SERVICOS_H_INCLUDED
#define SERVICOS_H_INCLUDED

#include <stdio.h> 

typedef struct {
    char nome[20];
    float valor;
} Servico;

extern Servico servicos[50];
extern int contador_de_servicos;

void cadastro_servico();

void listar_servicos();

void editar_servico();

void excluir_servico();


#endif // SERVICOS_H_INCLUDED
