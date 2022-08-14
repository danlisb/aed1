#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function to implement `strstr()` function
char *Mystrstr(char *X, int sizeX, char *Y)
{
    if (*Y == '\0')
    {
        return X;
    }

    for (int i = 0; i < sizeX; i++)
    {
        if (*(X + i) == *Y)
        {
            char *ptr = Mystrstr(X + i + 1, sizeX, Y + 1);
            return (ptr) ? ptr - 1 : NULL;
        }
    }

    return NULL;
}

void lerStringUsuario(char **string, int *indiceLeitura, int *tamanhoString)
{
    char caractere = 1;
    // static int indiceLeitura = 0;
    // static int tamanhoString = 0;

    while (caractere)
    {
        caractere = getc(stdin);

        if (caractere == EOF || caractere == '\n')
        {
            (*tamanhoString)++;
            *string = (char *)realloc(*string, sizeof(char) * (*tamanhoString));

            (*string)[*indiceLeitura] = '\0';
            (*indiceLeitura)++;

            caractere = 1;
            break;
        }

        if ((*tamanhoString) <= (*indiceLeitura))
        {
            (*tamanhoString)++;
            *string = (char *)realloc(*string, sizeof(char) * (*tamanhoString));
        }

        (*string)[(*indiceLeitura)] = caractere;
        (*indiceLeitura)++;
    }
}

int main()
{
    char *string = NULL;
    int nomesNum = 0;

    int indiceLeitura = 0;
    int tamanhoString = 0;

    char *nome = NULL;

    int indiceLeitura2 = 0;
    int tamanhoString2 = 0;

    while (1)
    {
        printf("Selecione uma opção: \n1)Adicionar nome\n2)Remover nomes\n3)Listar \n4)Sair\n\n");
        int choice;
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
        {
            printf("Digite um nome: ");

            lerStringUsuario(&string, &indiceLeitura, &tamanhoString);

            nomesNum++;
            break;
        }

        case 2:
        {
            char *start, *end;

            printf("Insira o nome que deseja remover: ");

            lerStringUsuario(&nome, &indiceLeitura2, &tamanhoString2);
            start = Mystrstr(string, tamanhoString, nome);

            if (start == NULL)
            {
                printf("\nNão existe esse nome na lista pae\n\n");
                getchar();

                free(nome);
                nome = NULL;
                indiceLeitura2 = 0;
                tamanhoString2 = 0;

                break;
            }

            end = start;

            // Desloca 'end' para o fim do nome
            for (; *end != '\0'; end++)
            {
            }
            if (end - string < tamanhoString)
            {
                end++;
            }

            // printf("\nEnd esta no indice %ld", end - string);

            printf("\n\nNome: %s\nEncontrado: %s\n\n", nome, start);

            tamanhoString -= tamanhoString2;
            indiceLeitura -= tamanhoString2;
            nomesNum--;

            for (int i = 0; i < tamanhoString; i++)
            {
                *(start + i) = *(end + i);
            }

            string = (char *)realloc(string, tamanhoString);

            printf("\nFeito\n");
            getchar();

            free(nome);
            nome = NULL;
            indiceLeitura2 = 0;
            tamanhoString2 = 0;

            break;
        }

        case 3:
        {
            for (int i = 0, j = -1; i < nomesNum; i++)
            {
                printf("%d - ", i + 1);
                j++;

                for (; string[j] != '\0'; j++)
                {
                    printf("%c", string[j]);
                }
                printf("\n");
            }

            getchar();
            break;
        }

        case 4:
        {
            free(string);
            exit(0);
            break;
        }

        default:
            break;
        }

        system("clear");
    }
    return 0;
}