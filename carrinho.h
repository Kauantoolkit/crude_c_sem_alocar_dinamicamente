#ifndef CARRINHO_H_INCLUDED
#define CARRINHO_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include "animal.h"
#include "produtos.h"
#include "servicos.h"

typedef struct {
    char nome[20];
    char tipo;
    float valor;
    int id_animal;
    int quantia;
    float subtotal;
} ItemCarrinho;

                                    //isso vai ser uma dor de cabeça massa



//typedef struct {
    //ItemCarrinho carrinho[100];
    
//} carrinho_por_cliente;



extern ItemCarrinho carrinho[100];
int extern contador_de_itens_no_carrinho;





void listar_itens_combinados();
void adicionar_ao_carrinho();
void listar_carrinho();
void remover_do_carrinho();
void finalizar_compra();





#endif // ANIMAL_H_INCLUDED
