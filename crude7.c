#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_ANIMAIS 100
#define MAX_SERVICOS 100
#define MAX_CARRINHO 100

typedef struct {
    char nome[20];
    float valor;
    char tipo;
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
    char tipo;
} Servico;

typedef struct {
    char nome[20];
    float valor;
    int quantidade;
    char tipo;  
    int id_animal; // ID do animal associado (se aplicável)
} ItemCarrinho;

Produto produtos[MAX_PRODUTOS];
int contador_de_produtos = 0;

Animal animais[MAX_ANIMAIS];
int contador_de_animais = 0;

Servico servicos[MAX_SERVICOS];
int contador_de_servicos = 0;

ItemCarrinho carrinho[MAX_CARRINHO];
int contador_de_itens_no_carrinho = 0;

// Protótipos de funções
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

void finalizar_compra();

// Funções relacionadas a produtos
void cadastro_produto() {
    if (contador_de_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    printf("Nome do produto: ");
    scanf(" %19s", produtos[contador_de_produtos].nome); // Limitando entrada para 19 caracteres
    printf("Valor do produto: ");
    scanf(" %f", &produtos[contador_de_produtos].valor);
    produtos[contador_de_produtos].tipo = 'P'; // Marcando o tipo como Produto
    contador_de_produtos++;
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
        scanf(" %19s", produtos[indice].nome); // Limitando entrada para 19 caracteres
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
        contador_de_produtos--;
        printf("Produto excluido com sucesso!\n");
    } else {
        printf("\nNenhum produto cadastrado\n");
    }
}

// Funções relacionadas a animais
void cadastro_animal() {
    if (contador_de_animais >= MAX_ANIMAIS) {
        printf("Limite de animais atingido!\n");
        return;
    }

    printf("Nome do animal: ");
    scanf(" %19s", animais[contador_de_animais].nome); // Limitando entrada para 19 caracteres
    printf("Peso do animal: ");
    scanf(" %f", &animais[contador_de_animais].peso);
    printf("Tipo do animal: ");
    scanf(" %19s", animais[contador_de_animais].tipo); // Limitando entrada para 19 caracteres
    printf("Nome do dono: ");
    scanf(" %19s", animais[contador_de_animais].dono_nome); // Limitando entrada para 19 caracteres
    printf("Telefone do dono: ");
    scanf(" %19s", animais[contador_de_animais].dono_telefone); // Limitando entrada para 19 caracteres
    printf("Endereco do dono: ");
    scanf(" %49s", animais[contador_de_animais].dono_endereco); // Limitando entrada para 49 caracteres

    contador_de_animais++;
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
        scanf(" %19s", animais[indice].nome); // Limitando entrada para 19 caracteres
        printf("Peso atual: %.2f\n", animais[indice].peso);
        printf("Novo peso: ");
        scanf(" %f", &animais[indice].peso);
        printf("Tipo atual: %s\n", animais[indice].tipo);
        printf("Novo tipo: ");
        scanf(" %19s", animais[indice].tipo); // Limitando entrada para 19 caracteres
        printf("Nome atual do dono: %s\n", animais[indice].dono_nome);
        printf("Novo nome do dono: ");
        scanf(" %19s", animais[indice].dono_nome); // Limitando entrada para 19 caracteres
        printf("Telefone atual do dono: %s\n", animais[indice].dono_telefone);
        printf("Novo telefone do dono: ");
        scanf(" %19s", animais[indice].dono_telefone); // Limitando entrada para 19 caracteres
        printf("Endereco atual do dono: %s\n", animais[indice].dono_endereco);
        printf("Novo endereco do dono: ");
        scanf(" %49s", animais[indice].dono_endereco); // Limitando entrada para 49 caracteres

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

// Funções relacionadas a serviços
void cadastro_servico() {
    if (contador_de_servicos >= MAX_SERVICOS) {
        printf("Limite de servicos atingido!\n");
        return;
    }

    printf("Nome do servico: ");
    scanf(" %19s", servicos[contador_de_servicos].nome); // Limitando entrada para 19 caracteres
    printf("Valor do servico: ");
    scanf(" %f", &servicos[contador_de_servicos].valor);
    servicos[contador_de_servicos].tipo = 'S'; // Marcando o tipo como Servico
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

// Funções relacionadas ao carrinho
void adicionar_ao_carrinho() {
    int escolha_produto_servico;
    listar_produtos();
    listar_servicos();
    printf("Digite o numero do servico ou produto que deseja adicionar: ");
    scanf(" %i", &escolha_produto_servico);
    if (escolha_produto_servico >= 0 && escolha_produto_servico < contador_de_produtos) {
        carrinho[contador_de_itens_no_carrinho].tipo = 'P';
        strcpy(carrinho[contador_de_itens_no_carrinho].nome, produtos[escolha_produto_servico].nome);
        carrinho[contador_de_itens_no_carrinho].valor = produtos[escolha_produto_servico].valor;
        carrinho[contador_de_itens_no_carrinho].id_animal = -1; // Não associado a nenhum animal
        contador_de_itens_no_carrinho++;
        printf("Produto adicionado ao carrinho com sucesso!\n");
    } else if (escolha_produto_servico >= contador_de_produtos && escolha_produto_servico < contador_de_produtos + contador_de_servicos) {
        carrinho[contador_de_itens_no_carrinho].tipo = 'S';
        strcpy(carrinho[contador_de_itens_no_carrinho].nome, servicos[escolha_produto_servico - contador_de_produtos].nome);
        carrinho[contador_de_itens_no_carrinho].valor = servicos[escolha_produto_servico - contador_de_produtos].valor;
        carrinho[contador_de_itens_no_carrinho].id_animal = -1; // Não associado a nenhum animal
        contador_de_itens_no_carrinho++;
        printf("Servico adicionado ao carrinho com sucesso!\n");
    } else {
        printf("Opcao invalida!\n");
    }
}

void listar_carrinho() {
    printf("Carrinho de compras:\n");
    printf("NOME / VALOR / TIPO\n");
    for (int i = 0; i < contador_de_itens_no_carrinho; i++) {
        if (carrinho[i].tipo == 'P') {
            printf("%s / %.2f / Produto\n", carrinho[i].nome, carrinho[i].valor);
        } else if (carrinho[i].tipo == 'S') {
            printf("%s / %.2f / Servico\n", carrinho[i].nome, carrinho[i].valor);
        }
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
        contador_de_itens_no_carrinho--;
        printf("Item removido do carrinho com sucesso!\n");
    } else {
        printf("\nNenhum item no carrinho\n");
    }
}

void finalizar_compra() {
    if (contador_de_itens_no_carrinho == 0) {
        printf("Carrinho vazio. Nada a finalizar.\n");
        return;
    }

    printf("Finalizando compra...\n");
    float total_compra = 0.0;
    for (int i = 0; i < contador_de_itens_no_carrinho; i++) {
        total_compra += carrinho[i].valor;
    }
    printf("Total da compra: %.2f\n", total_compra);

    // Associar serviços a animais antes de finalizar a compra
    for (int i = 0; i < contador_de_itens_no_carrinho; i++) {
        if (carrinho[i].tipo == 'S') {
            listar_animais();
            int id_animal;
            printf("Digite o numero do animal para associar o servico '%s' ao carrinho: ", carrinho[i].nome);
            scanf(" %i", &id_animal);
            if (id_animal >= 0 && id_animal < contador_de_animais) {
                carrinho[i].id_animal = id_animal;
                printf("Servico associado ao animal '%s' com sucesso!\n", animais[id_animal].nome);
            } else {
                printf("Opcao invalida. Servico nao associado a nenhum animal.\n");
            }
        }
    }

    // Lógica de venda ou confirmação de compra (depende da aplicação)
    // Aqui você poderia implementar a lógica de venda, como gerar um pedido, registrar a venda, etc.
    // Por exemplo, gravar em um arquivo, banco de dados ou apenas exibir a confirmação da compra.

    // Limpar carrinho após finalização da compra
    contador_de_itens_no_carrinho = 0;
    printf("Compra finalizada com sucesso!\n");
}

// Funções de menu
void menuPrincipal() {
    int opcao;
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Produtos\n");
        printf("2. Animais\n");
        printf("3. Servicos\n");
        printf("4. Carrinho\n");
        printf("5. Finalizar Compra\n");
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
            case 5:
                finalizar_compra();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuProdutos() {
    int opcao;
    do {
        printf("\n=== MENU DE PRODUTOS ===\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Editar Produto\n");
        printf("4. Excluir Produto\n");
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
                printf("Voltando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuAnimais() {
    int opcao;
    do {
        printf("\n=== MENU DE ANIMAIS ===\n");
        printf("1. Cadastrar Animal\n");
        printf("2. Listar Animais\n");
        printf("3. Editar Animal\n");
        printf("4. Excluir Animal\n");
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
                printf("Voltando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuServicos() {
    int opcao;
    do {
        printf("\n=== MENU DE SERVICOS ===\n");
        printf("1. Cadastrar Servico\n");
        printf("2. Listar Servicos\n");
        printf("3. Editar Servico\n");
        printf("4. Excluir Servico\n");
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
                printf("Voltando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuCarrinho() {
    int opcao;
    do {
        printf("\n=== MENU DO CARRINHO ===\n");
        printf("1. Adicionar ao Carrinho\n");
        printf("2. Listar Carrinho\n");
        printf("3. Remover do Carrinho\n");
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
                printf("Voltando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

int main() {
    menuPrincipal();
    return 0;
}
