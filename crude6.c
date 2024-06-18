#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_ANIMAIS 100
#define MAX_SERVICOS 100
#define MAX_CARRINHO 100

// Definição das estruturas de dados
typedef struct {
    char nome[20];
    float valor;
    char tipo; // 'P' para produto, 'S' para serviço
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
    char tipo; // 'P' para produto, 'S' para serviço
} Servico;

typedef struct {
    char nome[20];
    float valor;
    int quantidade;
    char tipo; // 'P' para produto, 'S' para serviço
    int animal_associado; // Índice do animal associado (-1 se não associado)
} ItemCarrinho;

// Variáveis globais
Produto produtos[MAX_PRODUTOS];
int contador_de_produtos = 0;

Animal animais[MAX_ANIMAIS];
int contador_de_animais = 0;

Servico servicos[MAX_SERVICOS];
int contador_de_servicos = 0;

ItemCarrinho carrinho[MAX_CARRINHO];
int contador_de_itens_no_carrinho = 0;

// coloquei as funções aqui pq isso tava um caos absoluto e perdi metade dos meus neuronios
void menuProdutos();
void menuAnimais();
void menuServicos();
void menuCarrinho();

void cadastro_produto();
void listar_produtos();
void editar_produto();
void excluir_produto();

void cadastro_animal();
void listar_animais();
void editar_animal();
void excluir_animal();

void cadastro_servico();
void listar_servicos();
void editar_servico();
void excluir_servico();

void adicionar_ao_carrinho();
void listar_carrinho();
void remover_do_carrinho();

// Funções específicas de Produto
void cadastro_produto() {
    if (contador_de_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    printf("Nome do produto: ");
    scanf(" %s", produtos[contador_de_produtos].nome);
    printf("Valor do produto: ");
    scanf(" %f", &produtos[contador_de_produtos].valor);
    produtos[contador_de_produtos].tipo = 'P'; // Marcando o tipo como Produto
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

// Funções específicas de Animal
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

// Funções específicas de Serviço
void cadastro_servico() {
    if (contador_de_servicos >= MAX_SERVICOS) {
        printf("Limite de servicos atingido!\n");
        return;
    }

    printf("Nome do servico: ");
    scanf(" %s", servicos[contador_de_servicos].nome);
    printf("Valor do servico: ");
    scanf(" %f", &servicos[contador_de_servicos].valor);
    servicos[contador_de_servicos].tipo = 'S'; // Marcando o tipo como Serviço
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

// Funções específicas de Carrinho
void adicionar_ao_carrinho() {
    if (contador_de_itens_no_carrinho >= MAX_CARRINHO) {
        printf("Carrinho cheio!\n");
        return;
    }

    // Verifica se há animais registrados
    if (contador_de_animais == 0) {
        printf("Nenhum animal registrado! Servicos nao podem ser adicionados ao carrinho.\n");
        return;
    }

    printf("Escolha o tipo de item:\n");
    printf("Produto: [P]\n");
    printf("Servico: [S]\n");
    char tipo_item;
    scanf(" %c", &tipo_item);

    if (tipo_item == 'P') {
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
        carrinho[contador_de_itens_no_carrinho].tipo = 'P'; // Produto
        carrinho[contador_de_itens_no_carrinho].animal_associado = -1; // Não associado a um animal
        contador_de_itens_no_carrinho += 1;

        printf("Produto adicionado ao carrinho!\n");
    } else if (tipo_item == 'S') {
        listar_servicos();
        int indice_servico, quantidade;
        printf("Digite o numero do servico que deseja adicionar ao carrinho: ");
        scanf(" %i", &indice_servico);
        if (indice_servico < 0 || indice_servico >= contador_de_servicos) {
            printf("Indice invalido!\n");
            return;
        }

        // Escolher um animal para associar ao servico
        listar_animais();
        int indice_animal;
        printf("Digite o numero do animal para associar ao servico: ");
        scanf(" %i", &indice_animal);
        if (indice_animal < 0 || indice_animal >= contador_de_animais) {
            printf("Indice de animal invalido!\n");
            return;
        }

        printf("Digite a quantidade: ");
        scanf(" %i", &quantidade);

        strcpy(carrinho[contador_de_itens_no_carrinho].nome, servicos[indice_servico].nome);
        carrinho[contador_de_itens_no_carrinho].valor = servicos[indice_servico].valor;
        carrinho[contador_de_itens_no_carrinho].quantidade = quantidade;
        carrinho[contador_de_itens_no_carrinho].tipo = 'S'; // Servico
        carrinho[contador_de_itens_no_carrinho].animal_associado = indice_animal; // Associando ao animal escolhido
        contador_de_itens_no_carrinho += 1;

        printf("Servico adicionado ao carrinho!\n");
    } else {
        printf("Tipo de item invalido!\n");
    }
}

void listar_carrinho() {
    if (contador_de_itens_no_carrinho == 0) {
        printf("Carrinho vazio!\n");
        return;
    }

    printf("Carrinho de compras:\n");
    printf("ITEM / VALOR UNITARIO / QUANTIDADE / SUBTOTAL\n");
    for (int i = 0; i < contador_de_itens_no_carrinho; i++) {
        float subtotal = carrinho[i].valor * carrinho[i].quantidade;
        printf("%s / %.2f / %i / %.2f\n", carrinho[i].nome, carrinho[i].valor, carrinho[i].quantidade, subtotal);
    }
}

void remover_do_carrinho() {
    if (contador_de_itens_no_carrinho > 0) {
        listar_carrinho();
        int indice;
        printf("Digite o numero do item que deseja remover do carrinho: ");
        scanf(" %i", &indice);
        if (indice < 0 || indice >= contador_de_itens_no_carrinho) {
            printf("Indice invalido!\n");
            return;
        }
        for (int i = indice; i < contador_de_itens_no_carrinho - 1; i++) {
            carrinho[i] = carrinho[i + 1];
        }
        contador_de_itens_no_carrinho -= 1;
        printf("Item removido do carrinho com sucesso!\n");
    } else {
        printf("Carrinho vazio!\n");
    }
}

// Menus principais
void menuProdutos() {
    int opcao;

    do {
        printf("\n----- MENU DE PRODUTOS -----\n");
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
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);
}

void menuAnimais() {
    int opcao;

    do {
        printf("\n----- MENU DE ANIMAIS -----\n");
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
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);
}

void menuServicos() {
    int opcao;

    do {
        printf("\n----- MENU DE SERVICOS -----\n");
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
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);
}

void menuCarrinho() {
    int opcao;

    do {
        printf("\n----- MENU DE CARRINHO -----\n");
        printf("1. Adicionar item ao carrinho\n");
        printf("2. Listar itens do carrinho\n");
        printf("3. Remover item do carrinho\n");
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
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);
}

// Função principal
int main() {
    int opcao;

    do {
        printf("\n----- MENU PRINCIPAL -----\n");
        printf("1. Menu de Produtos\n");
        printf("2. Menu de Animais\n");
        printf("3. Menu de Servicos\n");
        printf("4. Menu de Carrinho\n");
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
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
