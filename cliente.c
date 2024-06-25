#include <stdio.h>
#include <string.h>
#include "animal.h"
#include "cliente.h"

#define MAX_CLIENTES 100








Cliente clientes[MAX_CLIENTES];
int contador_de_clientes = 0;



void cadastro_cliente() {
    if(contador_de_clientes < MAX_CLIENTES){

        printf("||============================||\n");
         printf("|| informe o nome do cliente:\n");

        scanf(" %s", &clientes[contador_de_clientes].nome);

        printf("||================================||\n");
         printf("|| informe o endereco do cliente:\n");
        scanf(" %s", &clientes[contador_de_clientes].endereco);

        printf("||================================||\n");
         printf("|| informe o telefone do cliente:\n");
        scanf(" %s", &clientes[contador_de_clientes].telefone);

        contador_de_clientes++;

        printf("||========================================||\n");
         printf("||  O cliente foi cadastrado com sucesso! ||\n");
         printf("||========================================||\n");

    }else{
          printf("||============================================||\n");
         printf("||  O numero maximo de clientes foi atingido. ||\n");
         printf("||============================================||\n");
    }
}

void listar_clientes() {
    if(contador_de_clientes == 0) {
         printf("||=================================||\n");
         printf("||  Nenhum Cliente foi cadastrado. ||\n");
         printf("||=================================||\n");
    }else{
        printf("||===================||\n");
         printf("|| Lista de clientes ||\n");
         printf("||===================||\n");
        for (int i = 0; i < contador_de_clientes; i++) {
            printf("[%i] Nome: %s, Endereco: %s, Telefone: %s\n", i, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
        }
    }
}

void editar_cliente() {
    if (contador_de_clientes > 0) {
        listar_clientes();
        int indice;
          printf("||===============================================||\n");
         printf("|| Digite o numero do cliente que deseja editar:\n");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_clientes) {
            printf("||==================||\n");
         printf("|| indice invalido! ||\n");
         printf("||==================||\n");
            return;
        }
        printf("Nome atual: %s\n", clientes[indice].nome);
        printf("Novo nome: ");
        scanf(" %49s", clientes[indice].nome); // Limitando entrada para 19 caracteres

        printf("Endereco atual: %s\n", clientes[indice].endereco);
        printf("Novo endereco: ");
        scanf(" %99s", clientes[indice].endereco);

        printf("Telefone atual: %s\n", clientes[indice].telefone);
        printf("Novo telefone: ");
        scanf(" %14s", clientes[indice].telefone);

         printf("||====================================||\n");
         printf("|| O cliente foi editado com sucesso! ||\n");
        printf("||====================================||\n");
    }else{
          printf("||===========================||\n");
         printf("|| Nenhum cliente cadastrado ||\n");
        printf("||===========================||\n");
    }
}

void excluir_cliente() {
    if (contador_de_clientes > 0) {
        listar_clientes();
        int indice;
        printf("||================================================||\n");
         printf("|| Digite o numero do cliente que deseja excluir:");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_clientes) {
            printf("||==================||\n");
         printf("|| indice invalido! ||\n");
         printf("||==================||\n");
            return;
        }
        for (int i = indice; i < contador_de_clientes - 1; i++) {
            clientes[i] = clientes[i + 1];
        }
        contador_de_clientes--;
        printf("||===============================||\n");
         printf("|| Cliente excluido com sucesso! ||\n");
         printf("||===============================||\n");
    } else {
        printf("||===========================||\n");
         printf("|| Nenhum cliente cadastrado ||\n");
        printf("||===========================||\n");
    }
}



    



