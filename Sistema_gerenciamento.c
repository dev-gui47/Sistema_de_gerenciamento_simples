#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CADASTRO 5  // definindo maximo de cadastros de territorios
#define MAX_STRING 100 // definindo tamanho maximo de strings = caracteres

struct territorio {  // estrutura de dados para armazenar informacoes dos territorios
    char nome[50];
    char cor[20];  
    int quantidade;
};

void limparBufferEntrada() {  // funcao para limpar o buffer de entrada do teclado
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // descarta caracteres ate encontrar nova linha ou EOF
}

int main() {  // funcao principal
    struct territorio territorios[MAX_CADASTRO];  // array para armazenar os territorios cadastrados
    int totalcadastros = 0;
    int opcao;


    do {  // loop do menu principal
        printf("Menu de Opcoes:\n");
        printf("1. Cadastrar territorio\n");
        printf("2. lista de territorios\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o buffer do teclado


        switch (opcao) {  // estrutura de decisao para tratar as opcoes do menu
            case 1:
                printf("=== Cadastro do territorio === \n");

                if (totalcadastros < MAX_CADASTRO) {  // verifica se ainda ha espaco para cadastrar mais territorios
                    printf("Nome: ");
                    fgets(territorios[totalcadastros].nome, sizeof(territorios[totalcadastros].nome), stdin);  // le o nome do territorio
                    territorios[totalcadastros].nome[strcspn(territorios[totalcadastros].nome, "\n")] = 0; // Remove newline

                    printf("Cor: ");
                    fgets(territorios[totalcadastros].cor, sizeof(territorios[totalcadastros].cor), stdin);
                    territorios[totalcadastros].cor[strcspn(territorios[totalcadastros].cor, "\n")] = 0; // Remove newline

                    printf("Quantidade de tropas: ");
                    scanf("%d", &territorios[totalcadastros].quantidade);  // le a quantidade de tropas
                    limparBufferEntrada(); // Limpa o buffer do teclado
                    
                    totalcadastros++;
                    
                    printf("\n territorio cadastrado com sucesso!\n");
                } else {
                    printf("Limite de cadastros atingido.\n");
                }
                break; // break = acabar o 'if' e fim do case 1
                    
            case 2:
                printf("\n-----Territorios cadastrados-----\n\n");

                if (totalcadastros == 0) {
                    printf("Nenhum territorio cadastrado.\n\n");
                } else {
                    for (int i = 0; i < totalcadastros; i++) {
                        printf("----------------------------------\n");
                        printf("Territorio %d:\n", i + 1);
                        printf("Nome: %s\n", territorios[i].nome);
                        printf("Cor: %s\n", territorios[i].cor);
                        printf("Quantidade de tropas: %d\n", territorios[i].quantidade);
                    }
                    printf("----------------------------------\n");
                }
                printf("Pressione Enter para voltar para o menu...");
                getchar(); // Espera o usuário pressionar Enter
                break;

            case 0:
                printf("Saindo do programa.\n");
                break;

            default: // caso de opcao invalida
                printf("Opcao invalida. Tente novamente.\n");
                printf("\nPressione Enter para voltar para continuar...");
                getchar(); // Espera o usuário pressionar Enter
                break;
            }

        } while (opcao != 0); // continua o loop ate o usuario escolher sair

    return 0; // indica que o programa terminou com sucesso
}

