#include <stdio.h>
#include <string.h>
#include "produtos.h"
#include "servicos.h"
#include "animal.h"
#include "carrinho.h"


//menus
void menuProdutos() {
    int opcao;

    do {
        printf("\n=== MENU PRODUTOS ===\n");
        printf("1. Cadastrar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Editar produto\n");
        printf("4. Excluir produto\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf(" %i", &opcao);

        switch (opcao) {
            case 1:
                cadastro_produto();
                break;
            case 2:
                listar_produtos();
                break;
            case 3:
                editar_produto();
                break;
            case 4:
                excluir_produto();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuAnimais() {
    int opcao;

    do {
        printf("\n=== MENU ANIMAIS ===\n");
        printf("1. Cadastrar animal\n");
        printf("2. Listar animais\n");
        printf("3. Editar animal\n");
        printf("4. Excluir animal\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf(" %i", &opcao);

        switch (opcao) {
            case 1:
                cadastro_animal();
                break;
            case 2:
                listar_animais();
                break;
            case 3:
                editar_animal();
                break;
            case 4:
                excluir_animal();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuServicos() {
    int opcao;

    do {
        printf("\n=== MENU SERVICOS ===\n");
        printf("1. Cadastrar servico\n");
        printf("2. Listar servicos\n");
        printf("3. Editar servico\n");
        printf("4. Excluir servico\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf(" %i", &opcao);

        switch (opcao) {
            case 1:
                cadastro_servico();
                break;
            case 2:
                listar_servicos();
                break;
            case 3:
                editar_servico();
                break;
            case 4:
                excluir_servico();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuCarrinho() {
    int opcao;

    do {
        printf("\n=== MENU CARRINHO ===\n");
        printf("1. Adicionar ao carrinho\n");
        printf("2. Listar carrinho\n");
        printf("3. Remover do carrinho\n");
        printf("4. Finalizar compra\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf(" %i", &opcao);

        switch (opcao) {
            case 1:
                adicionar_ao_carrinho();
                break;
            case 2:
                listar_carrinho();
                break;
            case 3:
                remover_do_carrinho();
                break;
            case 4:
                finalizar_compra();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}









int main() {
    int opcao;

    do {
        printf("\n=== PETSHOP ===\n");
        printf("1. Menu Produtos\n");
        printf("2. Menu Animais\n");
        printf("3. Menu Servicos\n");
        printf("4. Menu Carrinho\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %i", &opcao);

        switch (opcao) {
            case 1:
                menuProdutos();
                break;
            case 2:
                menuAnimais();
                break;
            case 3:
                menuServicos();
                break;
            case 4:
                menuCarrinho();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
