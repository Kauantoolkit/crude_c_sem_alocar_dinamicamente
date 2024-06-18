#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_ANIMAIS 100

typedef struct {
    char nome[20];
    float valor;
} Produto;

typedef struct {
    char nome[20];
    float peso;
    char tipo[20];
    char dono_nome[20];
    char dono_telefone[20];
    char dono_endereco[50];
} Animal;

Produto produtos[MAX_PRODUTOS];
int contador_de_produtos = 0;

Animal animais[MAX_ANIMAIS];
int contador_de_animais = 0;

// Funções de Produto
void cadastro_produto() {
    if (contador_de_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    printf("Nome do produto: ");
    scanf(" %s", produtos[contador_de_produtos].nome);
    printf("Valor do produto: ");
    scanf(" %f", &produtos[contador_de_produtos].valor);
    contador_de_produtos += 1;
    printf("Produto cadastrado com sucesso!\n");
}

void listar_produtos() {
    printf("Lista de produtos:\n");
    printf("NOME / VALOR\n");
    for (int i = 0; i < contador_de_produtos; i++) {
        printf("%s / %.2f [%i]\n", produtos[i].nome, produtos[i].valor, i);
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
        contador_de_produtos -= 1;
        printf("Produto excluido com sucesso!\n");
    } else {
        printf("\nNenhum produto cadastrado\n");
    }
}

// Funções de Animal
void cadastro_animal() {
    if (contador_de_animais >= MAX_ANIMAIS) {
        printf("Limite de animais atingido!\n");
        return;
    }

    printf("Nome do animal: ");
    scanf(" %s", animais[contador_de_animais].nome);
    printf("Peso do animal: ");
    scanf(" %f", &animais[contador_de_animais].peso);
    printf("Tipo do animal: ");
    scanf(" %s", animais[contador_de_animais].tipo);
    printf("Nome do dono: ");
    scanf(" %s", animais[contador_de_animais].dono_nome);
    printf("Telefone do dono: ");
    scanf(" %s", animais[contador_de_animais].dono_telefone);
    printf("Endereco do dono: ");
    scanf(" %s", animais[contador_de_animais].dono_endereco);

    contador_de_animais += 1;
    printf("Animal cadastrado com sucesso!\n");
}

void listar_animais() {
    printf("Lista de animais:\n");
    printf("NOME / PESO / TIPO / DONO\n");
    for (int i = 0; i < contador_de_animais; i++) {
        printf("%s / %.2f / %s / %s [%i]\n", animais[i].nome, animais[i].peso, animais[i].tipo, animais[i].dono_nome, i);
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
        scanf(" %s", animais[indice].nome);
        printf("Peso atual: %.2f\n", animais[indice].peso);
        printf("Novo peso: ");
        scanf(" %f", &animais[indice].peso);
        printf("Tipo atual: %s\n", animais[indice].tipo);
        printf("Novo tipo: ");
        scanf(" %s", animais[indice].tipo);
        printf("Nome atual do dono: %s\n", animais[indice].dono_nome);
        printf("Novo nome do dono: ");
        scanf(" %s", animais[indice].dono_nome);
        printf("Telefone atual do dono: %s\n", animais[indice].dono_telefone);
        printf("Novo telefone do dono: ");
        scanf(" %s", animais[indice].dono_telefone);
        printf("Endereco atual do dono: %s\n", animais[indice].dono_endereco);
        printf("Novo endereco do dono: ");
        scanf(" %s", animais[indice].dono_endereco);
        
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
        contador_de_animais -= 1;
        printf("Animal excluido com sucesso!\n");
    } else {
        printf("\nNenhum animal cadastrado\n");
    }
}

// Menu de Registro
void menu_registro() {
    char escolha = 0;
    printf("Produto: \033[32m[1]\033[m\n");
    printf("Animal: \033[32m[2]\033[m\n");
    scanf(" %c", &escolha);

    if (escolha == '1') {
        printf("Menu de registros de produto\n");
        printf("Novo produto: [1]\n");
        printf("Editar produto: [2]\n");
        printf("Excluir produto: [3]\n");
        scanf(" %c", &escolha);

        if (escolha == '1') {
            cadastro_produto();
        } else if (escolha == '2') {
            editar_produto();
        } else if (escolha == '3') {
            excluir_produto();
        } else {
            printf("Opcao invalida! Retornando ao menu de registro.\n");
        }
    } else if (escolha == '2') {
        printf("Menu de registros de animal\n");
        printf("Novo animal: [1]\n");
        printf("Editar animal: [2]\n");
        printf("Excluir animal: [3]\n");
        scanf(" %c", &escolha);

        if (escolha == '1') {
            cadastro_animal();
        } else if (escolha == '2') {
            editar_animal();
        } else if (escolha == '3') {
            excluir_animal();
        } else {
            printf("Opcao invalida! Retornando ao menu de registro.\n");
        }
    } else {
        printf("Opcao invalida! Retornando ao menu principal.\n");
    }
}

// Menu Principal
int main() {
    char escolha_menu;

    while (1) {
        printf("\n\033[31mMenu:\033[m");
        printf("\nComprar\033[32m[1]\033[m");
        printf("\nRegistros\033[32m[2]\033[m");
        printf("\n\033[35mSAIR\033[32m[3]\033[m\n");

        scanf(" %c", &escolha_menu);

        if (escolha_menu == '1') {
            printf("Voce escolheu a opcao de Compra (a ser implementado).\n");
        } else if (escolha_menu == '2') {
            printf("Voce escolheu a edicao de registros\n");
            menu_registro();
        } else if (escolha_menu == '3') {
            printf("Saindo...\n");
            break;
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}
