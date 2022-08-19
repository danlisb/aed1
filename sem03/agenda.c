#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void clearStdinBuffer()
{
    while (getchar() != '\n')
    {
        continue;
    }
}

int main()
{
    char nome[10];
    int idade;
    int telefone;

    void *pBuffer = malloc(sizeof(int));
    *(int *)pBuffer = 0;

    int pessoaSize = 2 * sizeof(int) + 10 * sizeof(char);

    while (1)
    {
        printf("Olá! Digite a sua opção: \n");
        printf("\n1 - Adicionar\n2 - Apagar\n3 - Buscar\n4 - Listar\n5 - Sair\n");
        char choice = getchar();
        clearStdinBuffer();

        switch (choice)
        {
        case '1': // Adicionar um corno
        {
            // Soma 1 na região que tem o nro de pessoas na lista
            (*(int *)pBuffer)++;

            // Ajusta o tamanho da memória para salvar o novo número de pessoas
            int size = ((*(int *)pBuffer) * pessoaSize) + sizeof(int);
            pBuffer = realloc(pBuffer, size);

            // Cria um ponteiro temporário para acessar o novo endereço da pessoa alocada
            char *ptrNome = pBuffer + sizeof(int) + (pessoaSize * ((*(int *)pBuffer) - 1));
            int *ptrIdade = (int *)((void *)ptrNome + (10 * sizeof(char)));
            int *ptrTelefone = ptrIdade + 1;

            printf("\nDigite o nome desejado: ");
            scanf("%9[^\n]s", ptrNome);
            clearStdinBuffer();

            printf("Digite a idade: ");
            scanf("%d", ptrIdade);
            clearStdinBuffer();

            printf("Digite o numero de telefone (sem DDD): ");
            scanf("%d", ptrTelefone);
            clearStdinBuffer();

            break;
        }

        case '2': // Apagar
        {
            printf("\nDigite o número da pessoa para apagar: ");
            int num;
            scanf("%d", &num);
            clearStdinBuffer();

            void *start = pBuffer + sizeof(int);

            // Move start para o início da região da memória que tem a pessoa a ser apagada
            for (int i = 1; i < num; i++)
            {
                start += pessoaSize;
            }

            int size = ((*(int *)pBuffer) * pessoaSize) + sizeof(int);

            if (((start + pessoaSize) - pBuffer) != size)
            {
                void *end = start + pessoaSize;

                while (end - pBuffer <= size)
                {
                    strcpy((char *)start, (char *)end);

                    int *ptrIdadeStart = (int *)((void *)start + (10 * sizeof(char)));
                    int *ptrTelefoneStart = ptrIdadeStart + 1;

                    int *ptrIdadeEnd = (int *)((void *)end + (10 * sizeof(char)));
                    int *ptrTelefoneEnd = ptrIdadeEnd + 1;

                    *ptrIdadeStart = *ptrIdadeEnd;
                    *ptrTelefoneStart = *ptrTelefoneEnd;

                    start += pessoaSize;
                    end += pessoaSize;
                }
            }

            pBuffer = realloc(pBuffer, size - pessoaSize);
            (*(int *)pBuffer)--;

            break;
        }

        case '3': // Buscar
        {
            printf("\nDigite o nome da pessoa para buscar: ");
            char nomeBusca[10];
            bool encontrou = false;
            scanf("%9[^\n]s", nomeBusca);
            clearStdinBuffer();

            void *ptrPessoa = pBuffer + sizeof(int);
            for (int i = 0; i < *(int *)pBuffer; ptrPessoa += pessoaSize)
            {
                if (!strcmp(nomeBusca, ptrPessoa))
                {
                    printf("\nPessoa %d\n\tNome: %s\n\tIdade: %d\n\tTelefone: %d\n\n", i + 1, (char *)ptrPessoa, *(int *)(ptrPessoa + 10 * sizeof(char)), *(int *)(ptrPessoa + 10 * sizeof(char) + sizeof(int)));
                    encontrou = true;
                    getchar();
                    break;
                }
                i++;
            }

            if (!encontrou)
            {
                printf("\nEsse nome não existe na lista!");
                getchar();
            }

            break;
        }

        case '4': // Listar
        {
            // Acha a primeira pessoa na memória
            void *ptrPessoa = pBuffer + sizeof(int);
            for (int i = 0; i < *(int *)pBuffer; ptrPessoa += pessoaSize)
            {
                printf("\nPessoa %d\n\tNome: %s\n\tIdade: %d\n\tTelefone: %d\n", i + 1, (char *)ptrPessoa, *(int *)(ptrPessoa + 10 * sizeof(char)), *(int *)(ptrPessoa + 10 * sizeof(char) + sizeof(int)));
                i++;
            }

            getchar();
            break;
        }

        case '5':
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
