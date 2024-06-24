#include <stdio.h>
#include <string.h>
#include "produtos.h"
#include "servicos.h"
#include "animal.h"
// Estruturas




typedef struct {
    char nome[20];
    char tipo;
    float valor;
    int id_animal;
    int quantia;
} ItemCarrinho;

typedef struct {
    char nome[20];
    float peso;
    char dono[50];
} Animal;





// Variáveis globais




ItemCarrinho carrinho[100];
int contador_de_itens_no_carrinho = 0;



// Funções relacionadas ao carrinho
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
