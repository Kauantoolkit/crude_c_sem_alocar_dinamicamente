#include <stdio.h>
#include "animal.h"


Animal animais[50];
int contador_de_animais = 0;

void cadastro_animal() {
    printf("Nome do animal: ");
    scanf(" %19s", animais[contador_de_animais].nome);
    printf("Peso do animal: ");
    scanf(" %f", &animais[contador_de_animais].peso);
    printf("Nome do dono: ");
    scanf(" %49s", animais[contador_de_animais].dono);
    contador_de_animais++;
    printf("Animal cadastrado com sucesso!\n");
}

void listar_animais() {
    printf("Lista de animais:\n");
    printf("NOME / PESO / DONO\n");
    for (int i = 0; i < contador_de_animais; i++) {
        printf("%s / %.2f / %s [%i]\n", animais[i].nome, animais[i].peso, animais[i].dono, i);
    }
}

void editar_animal() {
    if (contador_de_animais > 0) {
        listar_animais();
        int indice;
        printf("Digite o numero do animal que deseja editar: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_animais) {
            printf("Indice invalido!\n");
            return;
        }
        printf("Nome atual: %s\n", animais[indice].nome);
        printf("Novo nome: ");
        scanf(" %19s", animais[indice].nome); // Limitando entrada para 19 caracteres
        printf("Peso atual: %.2f\n", animais[indice].peso);
        printf("Novo peso: ");
        scanf(" %f", &animais[indice].peso);
        printf("Dono atual: %s\n", animais[indice].dono);
        printf("Novo dono: ");
        scanf(" %49s", animais[indice].dono); // Limitando entrada para 49 caracteres
        printf("Animal editado com sucesso!\n");
    } else {
        printf("\nNenhum animal cadastrado\n");
    }
}

void excluir_animal() {
    if (contador_de_animais > 0) {
        listar_animais();
        int indice;
        printf("Digite o numero do animal que deseja excluir: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_animais) {
            printf("Indice invalido!\n");
            return;
        }
        for (int i = indice; i < contador_de_animais - 1; i++) {
            animais[i] = animais[i + 1];
        }
        contador_de_animais--;
        printf("Animal excluido com sucesso!\n");
    } else {
        printf("\nNenhum animal cadastrado\n");
    }
}


