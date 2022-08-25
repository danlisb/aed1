#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int idade;
    float altura;
} Pessoa;

Pessoa *pessoas = NULL;
char choice;
int numPessoas = 0;

void clearStdinBuffer()
{
    while (getchar() != '\n')
    {
        continue;
    }
}

int main()
{
    while (1)
    {
        printf("Deseja adicionar os dados de uma pessoa? (s/n): \n");
        choice = getchar();
        clearStdinBuffer();

        switch (choice)
        {
        case 'S':
        case 's':
            numPessoas++;

            Pessoa *tmp = (Pessoa *)realloc(pessoas, sizeof(Pessoa) * numPessoas);
            if (tmp == NULL)
            {
                printf("\nErro de alocação de memória!\n");
                getchar();
                free(pessoas);
                exit(EXIT_FAILURE);
            }
            pessoas = tmp;

            printf("\nDigite o nome desejado: ");
            scanf("%29[^\n]s", pessoas[numPessoas - 1].nome);
            clearStdinBuffer();

            printf("Digite a idade: ");
            scanf("%d", &pessoas[numPessoas - 1].idade);
            clearStdinBuffer();

            printf("Digite a altura: ");
            scanf("%f", &pessoas[numPessoas - 1].altura);
            clearStdinBuffer();

            break;

        case 'N':
        case 'n':
            for (int i = 0; i < numPessoas; i++)
            {
                printf("Pessoa %d\n\t Nome: %s\n\t Idade: %d \n\t Altura: %.2f\n", i + 1, pessoas[i].nome, pessoas[i].idade, pessoas[i].altura);
            }
            free(pessoas);
            getchar();
            exit(EXIT_SUCCESS);

            break;
        }
    }
}
