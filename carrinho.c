#include <stdio.h>
#include "carrinho.h"

ItemCarrinho carrinho[100];
int contador_de_itens_no_carrinho = 0;


void listar_itens_combinados() {
    printf("Lista de produtos e servicos:\n");
    printf("NOME / VALOR / TIPO / QUANTIA\n");
    for (int i = 0; i < contador_de_produtos; i++) {
        printf("%s / %.2f / P [%i]\n", produtos[i].nome, produtos[i].valor,i);
    }
    for (int i = 0; i < contador_de_servicos; i++) {
        printf("%s / %.2f / S [%i]\n", servicos[i].nome, servicos[i].valor, contador_de_produtos + i);
    }
}

void adicionar_ao_carrinho() {
    int escolha_produto_servico;
    listar_itens_combinados();
    printf("Digite o numero do servico ou produto que deseja adicionar: ");
    scanf(" %i", &escolha_produto_servico);

    if (escolha_produto_servico >= 0 && escolha_produto_servico < contador_de_produtos) {
        int quantia = 0;
        printf("insira quantos desse produto");
        scanf(" %i", &quantia);
        if (quantia > 0){
            carrinho[contador_de_itens_no_carrinho].tipo = 'P';
            strcpy(carrinho[contador_de_itens_no_carrinho].nome, produtos[escolha_produto_servico].nome);
            carrinho[contador_de_itens_no_carrinho].valor = produtos[escolha_produto_servico].valor;
            carrinho[contador_de_itens_no_carrinho].id_animal = -1;
            carrinho[contador_de_itens_no_carrinho].quantia = quantia;
            contador_de_itens_no_carrinho++;

            printf("Produto adicionado ao carrinho com sucesso!\n");}
        else{
            printf("quantia invalida");}

    } else if (escolha_produto_servico >= contador_de_produtos && escolha_produto_servico < contador_de_produtos + contador_de_servicos) {
        int id_servico = escolha_produto_servico - contador_de_produtos;



        listar_animais();
        
        printf("Digite o ID do animal que usara o servico: ");
        scanf(" %i", &carrinho[contador_de_itens_no_carrinho].id_animal);



        if (carrinho[contador_de_itens_no_carrinho].id_animal < 0 || carrinho[contador_de_itens_no_carrinho].id_animal >= contador_de_animais) {
            printf("ID de animal invalido. Servico nao associado a nenhum animal.\n");
            carrinho[contador_de_itens_no_carrinho].id_animal = -1;
        } else {
            printf("Servico associado ao animal %s.\n", animais[carrinho[contador_de_itens_no_carrinho].id_animal].nome);
            carrinho[contador_de_itens_no_carrinho].tipo = 'S';
            strcpy(carrinho[contador_de_itens_no_carrinho].nome, servicos[id_servico].nome);
            carrinho[contador_de_itens_no_carrinho].valor = servicos[id_servico].valor;
            carrinho[contador_de_itens_no_carrinho].quantia = 1;
            contador_de_itens_no_carrinho++;
            printf("Servico adicionado ao carrinho com sucesso!\n");
        }
        
        
        

    } else {
        printf("Opcao invalida!\n");
    }
}



void listar_carrinho() {
    if (contador_de_itens_no_carrinho == 0) {
        printf("O carrinho esta vazio.\n");
        return;
    }
    printf("Itens no carrinho:\n");
    for (int i = 0; i < contador_de_itens_no_carrinho; i++) {
        printf("Nome:%s / Valor:%.2f / Tipo:%c / Quantia:%i", carrinho[i].nome, carrinho[i].valor, carrinho[i].tipo, carrinho[i].quantia);
        if (carrinho[i].tipo == 'S' && carrinho[i].id_animal != -1) {
            printf(" / Animal: %s", animais[carrinho[i].id_animal].nome);
        }
        printf(" [%i]\n", i);
    }
}

void remover_do_carrinho() {
    if (contador_de_itens_no_carrinho == 0) {
        printf("O carrinho esta vazio.\n");
        return;
    }
    listar_carrinho();
    int indice;
    printf("Digite o numero do item que deseja remover: ");
    scanf(" %i", &indice);
    if (indice < 0 || indice >= contador_de_itens_no_carrinho) {
        printf("indice invalido!\n");
        return;
    }
    for (int i = indice; i < contador_de_itens_no_carrinho - 1; i++) {
        carrinho[i] = carrinho[i + 1];
    }
    contador_de_itens_no_carrinho--;
    printf("Item removido do carrinho com sucesso!\n");
}

void finalizar_compra() {
    if (contador_de_itens_no_carrinho == 0) {
        printf("O carrinho esta vazio.\n");
        return;
    }
    float total = 0.0;
    printf("Itens comprados:\n");
    for (int i = 0; i < contador_de_itens_no_carrinho; i++) {
        printf("%s / %.2f / %c", carrinho[i].nome, carrinho[i].valor, carrinho[i].tipo);
        if (carrinho[i].tipo == 'S' && carrinho[i].id_animal != -1) {
            printf(" / Animal: %s", animais[carrinho[i].id_animal].nome);
        }
        printf("\n");
        total += carrinho[i].valor;
    }
    printf("Total: %.2f\n", total);
    contador_de_itens_no_carrinho = 0; // Limpa o carrinho
    printf("Compra finalizada com sucesso!\n");
}
