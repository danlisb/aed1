#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fazer um programa que teste se uma sequencia de caracteres fornecida pelo usuario é um palindromo
// ou seja, é uma palavra cuja primeira metade é simétrica à segunda metade.
// AABCCBAA - sim
// ADDFDDA - sim
// ABFFBB - não
// o usuário digita uma letra e tecla enter até que ele digite X e enter para terminar a sequencia.
// usar POP e PUSH de pilha e resolva o problema com elas. No vídeo mostrar 4 casos de sim e 4 casos de não.
// pilha -> last in first out (LIFO)

typedef struct _Pilha
{
    char *data;
    int top;
    int size;
} Pilha;

void PUSH(Pilha *pilha, char alho)
{
    pilha->data = (char *)realloc(pilha->data, sizeof(char) * (pilha->size + 1));
    pilha->size++; // Atualiza tamanho da pilha

    pilha->data[pilha->top] = alho;
    pilha->top++;
}

char POP(Pilha *pilha)
{
    if (pilha == NULL || pilha->top == 0)
    {
        printf("Não há elementos na pilha.");
        return 0;
    }
    else
    {
        char c = pilha->data[pilha->top - 1];

        if (pilha->size - 1 != 0)
        {
            pilha->data = (char *)realloc(pilha->data, sizeof(char) * (pilha->size - 1));
        }
        else
        {
            free(pilha->data);
            pilha->data = NULL;
        }

        pilha->size--; // Atualiza tamanho da pilha
        pilha->top--;

        return c;
    }
}

void imprimirPilha(Pilha *pilha)
{
    for (int i = 0; i < pilha->size; i++)
    {
        printf("\n%c", pilha->data[i]);
    }
    printf("\n");
}

void deletarPilha(Pilha **pilha)
{
    if ((*pilha)->data != NULL)
        free((*pilha)->data);

    if (*pilha != NULL)
    {
        free(*pilha);
        *pilha = NULL;
    }
}

Pilha *criaPilha()
{
    Pilha *novaPilha = (Pilha *)malloc(sizeof(Pilha));

    novaPilha->top = 0;
    novaPilha->data = NULL;
    novaPilha->size = 0;

    return novaPilha;
}

bool verificaPalindromo(Pilha *pilha)
{
    // Uma pilha auxiliar que é metade do tamanho da principal é criada
    Pilha *pilhaAux = criaPilha();

    pilhaAux->size = pilha->size / 2;
    pilhaAux->top = pilha->top / 2;
    pilhaAux->data = (char *)malloc(sizeof(char) * pilhaAux->size);

    // É copiado os elementos da pilha principal para a pilha auxiliar
    for (int i = 0; i < pilhaAux->size; i++)
    {
        pilhaAux->data[i] = POP(pilha);
    }

    // Se sobrar um elemento a mais na pilha principal ele é removido com o POP
    if (pilha->size - pilhaAux->size == 1)
        POP(pilha);

    // Verifica elemento a elemento nas pilhas se são iguais.
    // Se encontrar um par que seja diferente ele já não considerará um palíndromo
    bool palindromo = true;

    int iterations = pilha->size;
    for (int i = 0; i < iterations; i++)
    {
        if (POP(pilha) != POP(pilhaAux))
        {
            palindromo = false;
            break;
        }
    }

    // Deleta a pilha auxiliar
    deletarPilha(&pilhaAux);

    return palindromo;
}

int main()
{
    Pilha *pilha = criaPilha();

    while (1)
    {
        printf("Digite as letras do seu palindromo apertando enter, quando terminar a sequência aperte X + Enter: ");
        char letra = getchar();
        getchar(); // Limpar buffer de entrada

        if (letra != 'x' && letra != 'X')
        {
            PUSH(pilha, letra);
        }
        else
        {
            imprimirPilha(pilha);

            if (verificaPalindromo(pilha))
                printf("\nÉ um palindromo.\n");
            else
                printf("\nNAO é um palindromo.\n");

            deletarPilha(&pilha);

            exit(0);
        }
    }
}
