
#include "produtos.h"

Produto produtos[50]; // Definição da variável global
int contador_de_produtos = 0; // Definição da variável global

void cadastro_produto() {
    printf("Nome do produto: ");
    scanf(" %19s", produtos[contador_de_produtos].nome);
    printf("Valor do produto: ");
    scanf(" %f", &produtos[contador_de_produtos].valor);
    contador_de_produtos++;
    printf("Produto cadastrado com sucesso!\n");
}



void listar_produtos() {
    printf("Lista de produtos:\n");
    printf("\nNOME / VALOR\n");
    for (int i = 0; i < contador_de_produtos; i++) {
        printf("[%i] %s:  %.2f \n",i, produtos[i].nome, produtos[i].valor);
    }
}



void editar_produto() {
    if (contador_de_produtos > 0) {
        listar_produtos();
        int indice;
        printf("Digite o numero do produto que deseja editar: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_produtos) {
            printf("Indice invalido!\n");
            return;
        }
        printf("Nome atual: %s\n", produtos[indice].nome);
        printf("Novo nome: ");
        scanf(" %s", produtos[indice].nome); 
        printf("Valor atual: %.2f\n", produtos[indice].valor);
        printf("Novo valor: ");
        scanf(" %f", &produtos[indice].valor);
        printf("Produto editado com sucesso!\n");
    } else {
        printf("\nNenhum produto cadastrado\n");
    }
}

void excluir_produto() {
    if (contador_de_produtos > 0) {
        listar_produtos();
        int indice;
        printf("Digite o numero do produto que deseja excluir: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_produtos) {
            printf("Indice invalido!\n");
            return;
        }
        for (int i = indice; i < contador_de_produtos - 1; i++) {
            produtos[i] = produtos[i + 1];
        }
        contador_de_produtos--;
        printf("Produto excluido com sucesso!\n");
    } else {
        printf("\nNenhum produto cadastrado\n");
    }
}
