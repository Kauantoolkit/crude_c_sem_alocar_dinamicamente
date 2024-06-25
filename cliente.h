#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define MAX_CLIENTES 100

#include <stdio.h> 
#include "animal.h"
#include "carrinho.h"


typedef struct {
    char nome[50];
    char endereco[100];
    char telefone[15];
    Animal animais_do_cliente[20];   //falta implementar
    ItemCarrinho carrinho_do_cliente[100];  //falta implementar


} Cliente;

extern Cliente clientes[MAX_CLIENTES];
extern int contador_de_clientes;

void cadastro_cliente();
void listar_clientes();
void editar_cliente();
void excluir_cliente();





#endif // CLIENTE_H_INCLUDED
