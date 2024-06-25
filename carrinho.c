#include <stdio.h>
#include <string.h>
#include "carrinho.h"

ItemCarrinho carrinho[100];
int contador_de_itens_no_carrinho = 0;

// Prototipos
void listar_itens_combinados();
void adicionar_ao_carrinho();
void listar_carrinho();
void remover_do_carrinho();
void finalizar_compra();
void gerar_ticket(float total, const char* metodo_pagamento, int parcelas);

void listar_itens_combinados() {
    printf("||=============================||\n");
    printf("||Lista de produtos e servicos ||\n");
    printf("||=============================||\n");

    printf("||=====================||\n");
    printf("|| NOME | VALOR | TIPO ||\n");
    printf("||=====================||\n");
    for (int i = 0; i < contador_de_produtos; i++) {
        printf("%s / %.2f / Produto [%i]\n", produtos[i].nome, produtos[i].valor ,i);
    }
    for (int i = 0; i < contador_de_servicos; i++) {
        printf("%s / %.2f / Servico  [%i]\n", servicos[i].nome, servicos[i].valor,contador_de_produtos + i);
    }
}

void adicionar_ao_carrinho() {
    int escolha_produto_servico;
    listar_itens_combinados();
    printf("||============================================================||\n\n");
    printf("||Digite o numero do servico ou produto que deseja adicionar: ");
    scanf(" %i", &escolha_produto_servico);

    if (escolha_produto_servico >= 0 && escolha_produto_servico < contador_de_produtos) {
        int quantia = 0;
        printf("||==============================||\n");
        printf("||insira quantos desse produto: ");
        scanf(" %i", &quantia);
        if (quantia > 0) {
            carrinho[contador_de_itens_no_carrinho].tipo = 'P';
            strcpy(carrinho[contador_de_itens_no_carrinho].nome, produtos[escolha_produto_servico].nome);
            carrinho[contador_de_itens_no_carrinho].valor = produtos[escolha_produto_servico].valor;
            carrinho[contador_de_itens_no_carrinho].id_animal = -1;
            carrinho[contador_de_itens_no_carrinho].quantia = quantia;
            carrinho[contador_de_itens_no_carrinho].subtotal = quantia * carrinho[contador_de_itens_no_carrinho].valor;
            contador_de_itens_no_carrinho++;

            printf("||=============================================||\n");
            printf("|| Produto adicionado ao carrinho com sucesso! ||\n");
            printf("||=============================================||\n");
        } else {
            printf("||==================||\n");
            printf("|| Quantia invalida ||\n");
            printf("||==================||\n");
        }
    } else if (escolha_produto_servico >= contador_de_produtos && escolha_produto_servico < contador_de_produtos + contador_de_servicos) {
        int id_servico = escolha_produto_servico - contador_de_produtos;

        listar_animais();
        printf("||===========================================||\n");
        printf("||Digite o ID do animal que usara o servico: ");
        scanf(" %i", &carrinho[contador_de_itens_no_carrinho].id_animal);

        if (carrinho[contador_de_itens_no_carrinho].id_animal < 0 || carrinho[contador_de_itens_no_carrinho].id_animal >= contador_de_animais) {
            printf("||===============================================================||\n");
            printf("|| ID de animal invalido. Servico nao associado a nenhum animal. ||\n");
            printf("||===============================================================||\n");
            carrinho[contador_de_itens_no_carrinho].id_animal = -1;
        } else {
            printf("Servico associado ao animal %s.\n", animais[carrinho[contador_de_itens_no_carrinho].id_animal].nome);
            carrinho[contador_de_itens_no_carrinho].tipo = 'S';
            strcpy(carrinho[contador_de_itens_no_carrinho].nome, servicos[id_servico].nome);
            carrinho[contador_de_itens_no_carrinho].valor = servicos[id_servico].valor;
            carrinho[contador_de_itens_no_carrinho].quantia = 1;
            carrinho[contador_de_itens_no_carrinho].subtotal = carrinho[contador_de_itens_no_carrinho].valor;
            contador_de_itens_no_carrinho++;
            printf("||=============================================||\n");
            printf("|| Servico adicionado ao carrinho com sucesso! ||\n");
            printf("||=============================================||\n");
        }
    } else {
        printf("||=================||\n");
        printf("|| Opcao invalida! ||\n");
        printf("||=================||\n");
    }
}

void listar_carrinho() {
    if (contador_de_itens_no_carrinho == 0) {
        printf("||========================||\n");
        printf("|| O carrinho esta vazio. ||\n");
        printf("||========================||\n");
        return;
    }
    printf("Itens no carrinho:\n");
    for (int i = 0; i < contador_de_itens_no_carrinho; i++) {
        printf("Nome:%s / Valor:%.2f / Tipo:%c / Quantia:%i/ Subtotal:%.2f", carrinho[i].nome, carrinho[i].valor, carrinho[i].tipo, carrinho[i].quantia, carrinho[i].subtotal);
        if (carrinho[i].tipo == 'S' && carrinho[i].id_animal != -1) {
            printf(" / Animal: %s", animais[carrinho[i].id_animal].nome);
        }
        printf(" [%i]\n", i);
    }
}

void remover_do_carrinho() {
    if (contador_de_itens_no_carrinho == 0) {
        printf("||========================||\n");
        printf("|| O carrinho esta vazio. ||\n");
        printf("||========================||\n");
        return;
    }
    listar_carrinho();
    int indice;
    printf("Digite o numero do item que deseja remover: ");
    scanf(" %i", &indice);
    if (indice < 0 || indice >= contador_de_itens_no_carrinho) {
        printf("||==================||\n");
        printf("|| indice invalido! ||\n");
        printf("||==================||\n");
        return;
    }
    for (int i = indice; i < contador_de_itens_no_carrinho - 1; i++) {
        carrinho[i] = carrinho[i + 1];
    }
    contador_de_itens_no_carrinho--;
    printf("||========================================||\n");
    printf("|| Item removido do carrinho com sucesso! ||\n");
    printf("||========================================||\n");
}

void gerar_ticket(float total, const char* metodo_pagamento, int parcelas) {
    FILE* ticket = fopen("ticket.txt", "w");
    if (ticket == NULL) {
        printf("Erro ao criar o arquivo de ticket.\n");
        return;
    }

    fprintf(ticket, "||=============================||\n");
    fprintf(ticket, "||         Ticket de Compra    ||\n");
    fprintf(ticket, "||=============================||\n");

    for (int i = 0; i < contador_de_itens_no_carrinho; i++) {
        fprintf(ticket, "Nome: %s / Valor: %.2f / Tipo: %c / Quantia: %i / Subtotal: %.2f",
                carrinho[i].nome, carrinho[i].valor, carrinho[i].tipo, carrinho[i].quantia, carrinho[i].subtotal);
        if (carrinho[i].tipo == 'S' && carrinho[i].id_animal != -1) {
            fprintf(ticket, " / Animal: %s", animais[carrinho[i].id_animal].nome);
        }
        fprintf(ticket, "\n");
    }
    fprintf(ticket, "Total: %.2f\n", total);
    fprintf(ticket, "Metodo de Pagamento: %s\n", metodo_pagamento);
    if (parcelas > 1) {
        fprintf(ticket, "Parcelas: %d\n", parcelas);
        fprintf(ticket, "Valor por Parcela: %.2f\n", total / parcelas);
    }
    fprintf(ticket, "||=============================||\n");
    fprintf(ticket, "|| Compra finalizada com sucesso! ||\n");
    fprintf(ticket, "||=============================||\n");

    fclose(ticket);
    printf("Ticket de compra gerado com sucesso em 'ticket.txt'.\n");
}

void finalizar_compra() {
    if (contador_de_itens_no_carrinho == 0) {
        printf("||========================||\n");
        printf("|| O carrinho esta vazio. ||\n");
        printf("||========================||\n");
        return;
    }

    float total = 0.0;
    printf("Itens comprados:\n");
    for (int i = 0; i < contador_de_itens_no_carrinho; i++) {
        printf("Nome: %s / Valor: %.2f / Tipo: %c / Quantia: %i / Subtotal: %.2f",
                carrinho[i].nome, carrinho[i].valor, carrinho[i].tipo, carrinho[i].quantia, carrinho[i].subtotal);
        if (carrinho[i].tipo == 'S' && carrinho[i].id_animal != -1) {
            printf(" / Animal: %s", animais[carrinho[i].id_animal].nome);
        }
        printf(" [%i]\n", i);
        total += carrinho[i].subtotal;
    }

    printf("Total: %.2f\n", total);
    
    int metodo_pagamento;
    printf("Selecione o metodo de pagamento:\n");
    printf("1. Dinheiro a vista\n");
    printf("2. Cartao a vista ou parcelado\n");
    printf("Escolha: ");
    scanf("%d", &metodo_pagamento);

    const char* metodo;
    int parcelas = 1;
    if (metodo_pagamento == 1) {
        metodo = "Dinheiro";
    } else if (metodo_pagamento == 2) {
        metodo = "Cartao";
        printf("Deseja parcelar? (1 - Sim / 0 - Nao): ");
        int opcao_parcelamento;
        scanf("%d", &opcao_parcelamento);
        if (opcao_parcelamento == 1) {
            printf("Em quantas vezes deseja parcelar? (1 a 12): ");
            scanf("%d", &parcelas);
            if (parcelas < 1 || parcelas > 12) {
                printf("Numero de parcelas invalido. Pagamento sera a vista.\n");
                parcelas = 1;
            }
        }
    } else {
        printf("Metodo de pagamento invalido.\n");
        return;
    }

    gerar_ticket(total, metodo, parcelas);


    contador_de_itens_no_carrinho = 0;
    printf("||===================================||\n");
    printf("|| Compra finalizada com sucesso!    ||\n");
    printf("||===================================||\n");
}

