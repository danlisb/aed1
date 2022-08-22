#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

void validaRealloc(void *ponteiro, void *newPonteiro)
{
    if (newPonteiro == NULL)
    {
        printf("\nErro de alocação de memória!!\n");
        getchar();
        free(ponteiro);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char const *argv[])
{
    Pessoa pessoas[10];

    /* Aqui se inicia a declaração das variáveis que serão usadas ao longo do código */

    // Primeira posição de pBuffer será de um ponteiro temporario para validação de reallocs
    void *pBuffer = malloc(sizeof(void *));
    if (pBuffer == NULL)
    {
        printf("\nErro de alocação de memória!!\n");
        getchar();
        exit(EXIT_FAILURE);
    }
    void **tempPtr = (void *)pBuffer;

    // Segunda posição do pBuffer guardará o tamanho dele (para aritmética de ponteiros)
    *tempPtr = realloc(pBuffer, sizeof(int) + sizeof(void *));
    validaRealloc(pBuffer, *tempPtr);
    int *sizePBuffer = (int *)(pBuffer + sizeof(void *));
    *sizePBuffer = sizeof(int) + sizeof(void *);

    // Terceira posição é a da variavel choice
    *tempPtr = realloc(pBuffer, *sizePBuffer + sizeof(char));
    char *choice = (char *)((void *)pBuffer + *sizePBuffer);
    *sizePBuffer += sizeof(char);

    // Quarta posição gurdará o número de nomes salvos no vetor pessoas
    *tempPtr = realloc(pBuffer, *sizePBuffer + sizeof(int));
    validaRealloc(pBuffer, *tempPtr);
    int *numPessoas = (int *)((void *)pBuffer + *sizePBuffer);
    *numPessoas = 0;
    *sizePBuffer += sizeof(int);

    // Quinta posição é a variável de iteração
    *tempPtr = realloc(pBuffer, *sizePBuffer + sizeof(int));
    validaRealloc(pBuffer, *tempPtr);
    int *i = (int *)((void *)pBuffer + *sizePBuffer);
    *sizePBuffer += sizeof(int);

    // Sexta posição são os caracteres de busca
    *tempPtr = realloc(pBuffer, *sizePBuffer + (10 * sizeof(char)));
    validaRealloc(pBuffer, *tempPtr);
    char *nomeBusca = (char *)((void *)pBuffer + *sizePBuffer);
    *sizePBuffer += 10 * sizeof(char);

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
            printf("\nDigite o número da pessoa para apagar: ");
            scanf("%c", choice);
            clearStdinBuffer();

            (*choice) -= '0';

            if (*choice > 10 || *choice < 1)
            {
                printf("\nValor inválido!\n");
                getchar();
                break;
            }

            (*choice)--;
            *i = *choice;

            if (*choice < (*numPessoas - 1))
            {
                while (*i < *numPessoas)
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
