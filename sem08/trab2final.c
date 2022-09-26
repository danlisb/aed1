#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fazer um programa que teste se uma sequencia de caracteres fornecida pelo usuario é um palindromo
// ou seja, é uma palavra cuja primeira metade é simétrica à segunda metade.
// AABCCBAA - sim
// ADDFDDA - sim
// ABBA - sim
// ANA - sim
// ABFFBB - não
// AASDAASD - não
// REAERA - não
// TOTO - não
// o usuário digita uma letra e tecla enter até que ele digite X e enter para terminar a sequencia.
// usar POP e PUSH de pilha e resolva o problema com elas. No vídeo mostrar 4 casos de sim e 4 casos de não.
// pilha -> last in first out (LIFO)

// criação da struct Pilha que contém um ponteiro char data que são as informações
// e int top para mostrar o topo da pilha e size usado para o seu tamanho
typedef struct _Pilha
{
    char *data;
    int top;
    int size;
} Pilha;

// criação do PUSH (adiciona elemento sempre no topo da pilha)
void PUSH(Pilha *pilha, char temp)
{   // abre espaço para adicionar um elemento na pilha e o organiza com o realloc 
    pilha->data = (char *)realloc(pilha->data, sizeof(char) * (pilha->size + 1)); 
    pilha->size++; // atualiza tamanho da pilha

    pilha->data[pilha->top] = temp;
    pilha->top++;
}

// criação do POP (retira sempre o último elemento adicionado da pilha)
char POP(Pilha *pilha)
{
    // verifica se há elementos na pilha, caso não tenha o programa retorna uma mensagem ao usuário
    if (pilha == NULL || pilha->top == 0)
    {
        printf("Não há elementos na pilha.");
        return 0;
    }
    else
    {
        char c = pilha->data[pilha->top - 1];

        if (pilha->size - 1 != 0) // caso tenha elementos na pilha ele é deletado e reorganizado
        {
            pilha->data = (char *)realloc(pilha->data, sizeof(char) * (pilha->size - 1));
        }
        else // se não, liberamos a memória e reinicializamos a informação da pilha
        {
            free(pilha->data);
            pilha->data = NULL;
        }

        pilha->size--; // atualiza tamanho da pilha
        pilha->top--;

        return c; // retorna a pilha com o elemento deletado
    }
}

void imprimirPilha(Pilha *pilha)
{ // imprime todos elementos da pilha com o laço for
    for (int i = 0; i < pilha->size; i++)
    {
        printf("\n%c", pilha->data[i]);
    }
    printf("\n");
}

void deletarPilha(Pilha **pilha)
{ // função que deleta a pilha e libera memória
    if ((*pilha)->data != NULL)
        free((*pilha)->data);

    if (*pilha != NULL)
    {
        free(*pilha);
        *pilha = NULL;
    }
}

Pilha *criaPilha()
{ // função que aloca memória dinamicamente para criar a pilha e inicia as variáveis da struct Pilha
    Pilha *novaPilha = (Pilha *)malloc(sizeof(Pilha));

    novaPilha->top = 0;
    novaPilha->data = NULL;
    novaPilha->size = 0;

    return novaPilha;
}

bool verificaPalindromo(Pilha *pilha)
{
    // uma pilha auxiliar que é metade do tamanho da principal é criada
    Pilha *pilhaAux = criaPilha();

    pilhaAux->size = pilha->size / 2;
    pilhaAux->top = pilha->top / 2;
    pilhaAux->data = (char *)malloc(sizeof(char) * pilhaAux->size);

    // copia-se os elementos da pilha principal para a pilha auxiliar
    for (int i = 0; i < pilhaAux->size; i++)
    {
        pilhaAux->data[i] = POP(pilha);
    }

    // se sobrar um elemento a mais na pilha principal ele é removido com o POP
    if (pilha->size - pilhaAux->size == 1)
        POP(pilha);

    // verifica elemento a elemento nas pilhas se são iguais
    // se encontrar um par que seja diferente ele já não considerará um palíndromo
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
    // deleta a pilha auxiliar
    deletarPilha(&pilhaAux);

    return palindromo;
}

int main()
{
    // cria-se um ponteiro pilha do tipo Pilha da nossa struct que chama a função criaPilha
    Pilha *pilha = criaPilha();

    while (1)
    {
        // laço principal do programa solicitando ao usuário que digite as letras
        printf("Digite as letras do seu palindromo apertando enter, quando terminar a sequência aperte X + Enter: ");
        char letra = getchar();
        getchar(); // limpa buffer de entrada

        // se não for pressionado X pelo usuário fazemos o PUSH das letras inseridas  
        if (letra != 'x' && letra != 'X')
        {
            PUSH(pilha, letra);
        }
        else
        {
            imprimirPilha(pilha);

            //verifica se é palindromo ou não e nos retorna a resposta
            if (verificaPalindromo(pilha))
                printf("\nÉ um palindromo.\n");
            else
                printf("\nNão é um palindromo.\n");

            // deleta a pilha
            deletarPilha(&pilha);

            exit(0);
        }
    }
}
