#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_ANIMAIS 100
#define MAX_SERVICOS 100
#define MAX_CARRINHO 100

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

typedef struct {
    char nome[20];
    float valor;
} Servico;

typedef struct {
    char nome[20];
    float valor;
    int quantidade;
} ItemCarrinho;

Produto produtos[MAX_PRODUTOS];
int contador_de_produtos = 0;

Animal animais[MAX_ANIMAIS];
int contador_de_animais = 0;

Servico servicos[MAX_SERVICOS];
int contador_de_servicos = 0;

ItemCarrinho carrinho[MAX_CARRINHO];
int contador_de_itens_no_carrinho = 0;

// Funcoes de Produto
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

// Funcoes de Animal
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

// Funcoes de Servico
void cadastro_servico() {
    if (contador_de_servicos >= MAX_SERVICOS) {
        printf("Limite de servicos atingido!\n");
        return;
    }

    printf("Nome do servico: ");
    scanf(" %s", servicos[contador_de_servicos].nome);
    printf("Valor do servico: ");
    scanf(" %f", &servicos[contador_de_servicos].valor);
    contador_de_servicos += 1;
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
        scanf(" %s", servicos[indice].nome);
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
        contador_de_servicos -= 1;
        printf("Servico excluido com sucesso!\n");
    } else {
        printf("\nNenhum servico cadastrado\n");
    }
}

// Funcoes do Carrinho de Compras
void adicionar_ao_carrinho() {
    if (contador_de_itens_no_carrinho >= MAX_CARRINHO) {
        printf("Carrinho cheio!\n");
        return;
    }

    listar_produtos();
    int indice_produto, quantidade;
    printf("Digite o numero do produto que deseja adicionar ao carrinho: ");
    scanf(" %i", &indice_produto);
    if (indice_produto < 0 || indice_produto >= contador_de_produtos) {
        printf("Indice invalido!\n");
        return;
    }
    printf("Digite a quantidade: ");
    scanf(" %i", &quantidade);

    strcpy(carrinho[contador_de_itens_no_carrinho].nome, produtos[indice_produto].nome);
    carrinho[contador_de_itens_no_carrinho].valor = produtos[indice_produto].valor;
    carrinho[contador_de_itens_no_carrinho].quantidade = quantidade;
    contador_de_itens_no_carrinho += 1;

    printf("Produto adicionado ao carrinho!\n");
}

void visualizar_carrinho() {
    printf("Carrinho de compras:\n");
    printf("NOME / VALOR / QUANTIDADE\n");
    float total = 0;
    for (int i = 0; i < contador_de_itens_no_carrinho; i++) {
        printf("%s / %.2f / %i\n", carrinho[i].nome, carrinho[i].valor, carrinho[i].quantidade);
        total += carrinho[i].valor * carrinho[i].quantidade;
    }
    printf("Total: %.2f\n", total);
}

void finalizar_compra() {
    visualizar_carrinho();
    printf("Compra finalizada! Obrigado por comprar conosco.\n");
    contador_de_itens_no_carrinho = 0;  // Esvazia o carrinho
}

// Menu de Compras
void menu_compras() {
    char escolha;
    while (1) {
        printf("\nMenu de Compras:\n");
        printf("Adicionar ao carrinho: [1]\n");
        printf("Visualizar carrinho: [2]\n");
        printf("Finalizar compra: [3]\n");
        printf("Voltar ao menu principal: [4]\n");
        scanf(" %c", &escolha);

        if (escolha == '1') {
            adicionar_ao_carrinho();
        } else if (escolha == '2') {
            visualizar_carrinho();
        } else if (escolha == '3') {
            finalizar_compra();
        } else if (escolha == '4') {
            break;
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }
}

// Menu de Registro
void menu_registro() {
    char escolha = 0;
    printf("Produto: \033[32m[1]\033[m\n");
    printf("Animal: \033[32m[2]\033[m\n");
    printf("Servico: \033[32m[3]\033[m\n");
    scanf(" %c", &escolha);

    if (escolha == '1') {
        printf("Menu de registros de produto\n");
        printf("Novo produto: [1]\n");
        printf("Listar produtos: [2]\n");
        printf("Editar produto: [3]\n");
        printf("Excluir produto: [4]\n");
        scanf(" %c", &escolha);

        if (escolha == '1') {
            cadastro_produto();
        } else if (escolha == '2') {
            listar_produtos();
        } else if (escolha == '3') {
            editar_produto();
        } else if (escolha == '4') {
            excluir_produto();
        } else {
            printf("Opcao invalida! Retornando ao menu de registro.\n");
        }
    } else if (escolha == '2') {
        printf("Menu de registros de animal\n");
        printf("Novo animal: [1]\n");
        printf("Listar animais: [2]\n");
        printf("Editar animal: [3]\n");
        printf("Excluir animal: [4]\n");
        scanf(" %c", &escolha);

        if (escolha == '1') {
            cadastro_animal();
        } else if (escolha == '2') {
            listar_animais();
        } else if (escolha == '3') {
            editar_animal();
        } else if (escolha == '4') {
            excluir_animal();
        } else {
            printf("Opcao invalida! Retornando ao menu de registro.\n");
        }
    } else if (escolha == '3') {
        printf("Menu de registros de servico\n");
        printf("Novo servico: [1]\n");
        printf("Listar servicos: [2]\n");
        printf("Editar servico: [3]\n");
        printf("Excluir servico: [4]\n");
        scanf(" %c", &escolha);

        if (escolha == '1') {
            cadastro_servico();
        } else if (escolha == '2') {
            listar_servicos();
        } else if (escolha == '3') {
            editar_servico();
        } else if (escolha == '4') {
            excluir_servico();
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
            menu_compras();
        } else if (escolha_menu == '2') {
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
