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
        printf("Digite o número do produto que deseja editar: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_produtos) {
            printf("Índice inválido!\n");
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
        printf("Digite o número do produto que deseja excluir: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_produtos) {
            printf("Índice inválido!\n");
            return;
        }
        for (int i = indice; i < contador_de_produtos - 1; i++) {
            produtos[i] = produtos[i + 1];
        }
        contador_de_produtos -= 1;
        printf("Produto excluído com sucesso!\n");
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
    printf("Endereço do dono: ");
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
        printf("Digite o número do animal que deseja editar: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_animais) {
            printf("Índice inválido!\n");
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
        printf("Endereço atual do dono: %s\n", animais[indice].dono_endereco);
        printf("Novo endereço do dono: ");
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
        printf("Digite o número do animal que deseja excluir: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_animais) {
            printf("Índice inválido!\n");
            return;
        }
        for (int i = indice; i < contador_de_animais - 1; i++) {
            animais[i] = animais[i + 1];
        }
        contador_de_animais -= 1;
        printf("Animal excluído com sucesso!\n");
    } else {
        printf("\nNenhum animal cadastrado\n");
    }
}

// Funções de Serviço
void cadastro_servico() {
    if (contador_de_servicos >= MAX_SERVICOS) {
        printf("Limite de serviços atingido!\n");
        return;
    }

    printf("Nome do serviço: ");
    scanf(" %s", servicos[contador_de_servicos].nome);
    printf("Valor do serviço: ");
    scanf(" %f", &servicos[contador_de_servicos].valor);
    contador_de_servicos += 1;
    printf("Serviço cadastrado com sucesso!\n");
}

void listar_servicos() {
    printf("Lista de serviços:\n");
    printf("NOME / VALOR\n");
    for (int i = 0; i < contador_de_servicos; i++) {
        printf("%s / %.2f [%i]\n", servicos[i].nome, servicos[i].valor, i);
    }
}

void editar_servico() {
    if (contador_de_servicos > 0) {
        listar_servicos();
        int indice;
        printf("Digite o número do serviço que deseja editar: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_servicos) {
            printf("Índice inválido!\n");
            return;
        }
        printf("Nome atual: %s\n", servicos[indice].nome);
        printf("Novo nome: ");
        scanf(" %s", servicos[indice].nome);
        printf("Valor atual: %.2f\n", servicos[indice].valor);
        printf("Novo valor: ");
        scanf(" %f", &servicos[indice].valor);
        printf("Serviço editado com sucesso!\n");
    } else {
        printf("\nNenhum serviço cadastrado\n");
    }
}

void excluir_servico() {
    if (contador_de_servicos > 0) {
        listar_servicos();
        int indice;
        printf("Digite o número do serviço que deseja excluir: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_servicos) {
            printf("Índice inválido!\n");
            return;
        }
        for (int i = indice; i < contador_de_servicos - 1; i++) {
            servicos[i] = servicos[i + 1];
        }
        contador_de_servicos -= 1;
        printf("Serviço excluído com sucesso!\n");
    } else {
        printf("\nNenhum serviço cadastrado\n");
    }
}

// Funções do Carrinho de Compras
void adicionar_ao_carrinho() {
    if (contador_de_produtos == 0) {
        printf("Nenhum produto disponível para compra.\n");
        return;
    }

    listar_produtos();

    int indice, quantidade;
    printf("Digite o número do produto que deseja adicionar ao carrinho: ");
    scanf("%d", &indice);

    if (indice < 0 || indice >= contador_de_produtos) {
        printf("Índice inválido!\n");
        return;
    }

    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade inválida!\n");
        return;
    }

    // Verificar se o produto já está no carrinho
    for (int i = 0; i < contador_de_itens_no_carrinho; i++) {
        if (strcmp(carrinho[i].nome, produtos[indice].nome) == 0) {
            carrinho[i].quantidade += quantidade;
            printf("Produto %s atualizado no carrinho.\n", produtos[indice].nome);
            return;
        }
    }

    // Adicionar novo item ao carrinho
    strcpy(carrinho[contador_de_itens_no_carrinho].nome, produtos[indice].nome);
    carrinho[contador_de_itens_no_carrinho].valor = produtos[indice].valor;
    carrinho[contador_de_itens_no_carrinho].quantidade = quantidade;
    contador_de_itens_no_carrinho++;

    printf("Produto %s adicionado ao carrinho.\n", produtos[indice].nome);
}

void visualizar_carrinho() {
    if (contador_de_itens_no_carrinho == 0) {
        printf("Carrinho vazio.\n");
        return;
    }

    printf("Carrinho de Compras:\n");
    printf("NOME / VALOR UNITÁRIO / QUANTIDADE / VALOR TOTAL\n");
    float total = 0;
    for (int i = 0; i < contador_de_itens_no_carrinho; i++) {
        float valor_total = carrinho[i].valor * carrinho[i].quantidade;
        total += valor_total;
        printf("%s / %.2f / %d / %.2f\n", carrinho[i].nome, carrinho[i].valor, carrinho[i].quantidade, valor_total);
    }
    printf("Valor total da compra: %.2f\n", total);
}

void finalizar_compra() {
    if (contador_de_itens_no_carrinho == 0) {
        printf("Carrinho vazio. Nada para finalizar.\n");
        return;
    }

    visualizar_carrinho();
    char confirmacao;
    printf("Deseja finalizar a compra? (s/n): ");
    scanf(" %c", &confirmacao);

    if (confirmacao == 's' || confirmacao == 'S') {
        contador_de_itens_no_carrinho = 0;
        printf("Compra finalizada com sucesso!\n");
    } else {
        printf("Compra não finalizada.\n");
    }
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
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

// Menu de Registros
void menu_registro() {
    char escolha;
    while (1) {
        printf("\nMenu de Registros:\n");
        printf("Cadastrar Produto: [1]\n");
        printf("Listar Produtos: [2]\n");
        printf("Editar Produto: [3]\n");
        printf("Excluir Produto: [4]\n");
        printf("Cadastrar Animal: [5]\n");
        printf("Listar Animais: [6]\n");
        printf("Editar Animal: [7]\n");
        printf("Excluir Animal: [8]\n");
        printf("Cadastrar Serviço: [9]\n");
        printf("Listar Serviços: [10]\n");
        printf("Editar Serviço: [11]\n");
        printf("Excluir Serviço: [12]\n");
        printf("Voltar ao menu principal: [13]\n");

        scanf(" %c", &escolha);

        switch (escolha) {
            case '1':
                cadastro_produto();
                break;
            case '2':
                listar_produtos();
                break;
            case '3':
                editar_produto();
                break;
            case '4':
                excluir_produto();
                break;
            case '5':
                cadastro_animal();
                break;
            case '6':
                listar_animais();
                break;
            case '7':
                editar_animal();
                break;
            case '8':
                excluir_animal();
                break;
            case '9':
                cadastro_servico();
                break;
            case '10':
                listar_servicos();
                break;
            case '11':
                editar_servico();
                break;
            case '12':
                excluir_servico();
                break;
            case '13':
                return;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }
}

// Main
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
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
