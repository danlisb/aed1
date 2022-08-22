#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[10];
    int idade;
    int telefone;
} Pessoa;

void clearStdinBuffer()
{
    while (getchar() != '\n')
    {
        continue;
    }
}

int main(int argc, char const *argv[])
{
    Pessoa pessoas[10];

    // Alocação das variáveis no buffer
    void *pBuffer = malloc(sizeof(char) + 2 * sizeof(int) + 10 * sizeof(char));
    if (pBuffer == NULL)
    {
        printf("\nErro de alocação de memória!!\n");
        getchar();
        exit(EXIT_FAILURE);
    }

    // Criação e cálculo dos ponteiros
    char *choice = (char *)pBuffer;
    int *numPessoas = (int *)((char *)choice + 1);
    *numPessoas = 0;
    int *i = (int *)numPessoas + 1;
    char *nomeBusca = (char *)((int *)i + 1);

    // Loop principal
    while (1)
    {
        printf("Olá! Digite a sua opção: \n");
        printf("\n1 - Adicionar\n2 - Apagar\n3 - Buscar\n4 - Listar\n5 - Sair\n");

        *choice = getchar();
        clearStdinBuffer();

        switch (*choice)
        {
        case '1': // Adicionar uma pessoa
        {
            if (*numPessoas < 10)
            {
                printf("\nDigite o nome desejado: ");
                scanf("%9[^\n]s", pessoas[*numPessoas].nome);
                clearStdinBuffer();

                printf("Digite a idade: ");
                scanf("%d", &pessoas[*numPessoas].idade);
                clearStdinBuffer();

                printf("Digite o numero de telefone (sem DDD): ");
                scanf("%d", &pessoas[*numPessoas].telefone);
                clearStdinBuffer();

                (*numPessoas)++;
            }
            else
            {
                printf("\nLista cheia!!\n\n");
                getchar();
            }

            break;
        }

        case '2': // Apagar
        {
            if (*numPessoas == 0)
            {
                printf("\nNão há pessoas na agenda!\n");
                getchar();
                break;
            }

            printf("\nDigite o número da pessoa para apagar: ");
            scanf("%c", choice);
            clearStdinBuffer();

            (*choice) -= '0';

            if (*choice > *numPessoas || *choice < 1)
            {
                printf("\nValor inválido!\n");
                getchar();
                break;
            }

            (*choice)--;
            *i = *choice;

            if (*choice < (*numPessoas - 1))
            {
                while (*i < *numPessoas - 1)
                {
                    strcpy(pessoas[*i].nome, pessoas[*i + 1].nome);

                    pessoas[*i].idade = pessoas[*i + 1].idade;
                    pessoas[*i].telefone = pessoas[*i + 1].telefone;

                    (*i)++;
                }
            }

            (*numPessoas)--;
            break;
        }

        case '3': // Buscar
        {
            printf("\nDigite o nome da pessoa para buscar: ");
            scanf("%9[^\n]s", nomeBusca);
            clearStdinBuffer();

            for (*i = 0; *i < *numPessoas; (*i)++)
            {
                if (!strcmp(nomeBusca, pessoas[*i].nome))
                {
                    printf("\nPessoa %d\n\tNome: %s\n\tIdade: %d\n\tTelefone: %d\n", *i + 1, pessoas[*i].nome, pessoas[*i].idade, pessoas[*i].telefone);
                    getchar();
                    break;
                }
            }

            if (*i == *numPessoas)
            {
                printf("\nEsse nome não existe na lista!");
                getchar();
            }

            break;
        }

        case '4': // Listar
        {
            for (*i = 0; *i < *numPessoas; (*i)++)
            {
                printf("\nPessoa %d\n\tNome: %s\n\tIdade: %d\n\tTelefone: %d\n", *i + 1, pessoas[*i].nome, pessoas[*i].idade, pessoas[*i].telefone);
            }

            getchar();
            break;
        }

        case '5': // Sair
        {
            free(pBuffer);
            exit(EXIT_SUCCESS);
            break;
        }

        default:
            break;
        }

        system("clear");
    }
    return 0;
}
