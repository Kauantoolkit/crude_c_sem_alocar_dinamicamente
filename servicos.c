#include "servicos.h"

Servico servicos[50];
int contador_de_servicos = 0;

void cadastro_servico() {
    printf("Nome do servico: ");
    scanf(" %19s", servicos[contador_de_servicos].nome);
    printf("Valor do servico: ");
    scanf(" %f", &servicos[contador_de_servicos].valor);
    contador_de_servicos++;
    printf("Servico cadastrado com sucesso!\n");
}

void listar_servicos() {
    printf("Lista de servicos:\n");
    printf("NOME / VALOR\n");
    for (int i = 0; i < contador_de_servicos; i++) {
        printf("%s / %.2f [%i]\n", servicos[i].nome, servicos[i].valor, i);
    }
}

void editar_servico() {
    if (contador_de_servicos > 0) {
        listar_servicos();
        int indice;
        printf("Digite o numero do servico que deseja editar: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_servicos) {
            printf("Indice invalido!\n");
            return;
        }
        printf("Nome atual: %s\n", servicos[indice].nome);
        printf("Novo nome: ");
        scanf(" %19s", servicos[indice].nome); // Limitando entrada para 19 caracteres
        printf("Valor atual: %.2f\n", servicos[indice].valor);
        printf("Novo valor: ");
        scanf(" %f", &servicos[indice].valor);
        printf("Servico editado com sucesso!\n");
    } else {
        printf("\nNenhum servico cadastrado\n");
    }
}

void excluir_servico() {
    if (contador_de_servicos > 0) {
        listar_servicos();
        int indice;
        printf("Digite o numero do servico que deseja excluir: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_servicos) {
            printf("Indice invalido!\n");
            return;
        }
        for (int i = indice; i < contador_de_servicos - 1; i++) {
            servicos[i] = servicos[i + 1];
        }
        contador_de_servicos--;
        printf("Servico excluido com sucesso!\n");
    } else {
        printf("\nNenhum servico cadastrado\n");
    }
}

