#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nums[] = {9,6,4,2,3,5,7,0,1}; // editar aqui o vetor 
    int numsSize = 9, tmp; // editar aqui o tamanho do vetor 

    int *vetAux = (int *)malloc(sizeof(int) * (numsSize + 1)); // criacao do vetor auxiliar, aloca-se o tamanho do vetor + 1                                                            
                                                               //(considerando que falta um elemento no vetor nums[])
    memset(vetAux, 0, sizeof(int) * (numsSize + 1)); // coloca 0 no vetor auxiliar usando o memset

    for (int i = 0; i < numsSize + 1; i++) 
    {
        printf("[%d]", vetAux[i]); // printa o vetor auxiliar preenchido com 0
    }
    printf("\n");
 
    for (int i = 0; i < numsSize; i++)
    {
        printf("[%d]", nums[i]); // printa os elementos do vetor nums[]   
    }

    for (int j = 0; j < numsSize; j++)
    {
        tmp = nums[j]; // usamos uma variavel temporaria para armazenar os valores do vetor nums[]
        vetAux[tmp] = 1; // se ele acha o numero correspondente no vetor temporario eh colocado 1 no vetor
    }

    printf("\n");
    for (int i = 0; i < numsSize + 1; i++)
    {
        printf("[%d]", vetAux[i]);
    }
    printf("\n");

    for (int i = 0; i < numsSize + 1; i++)
    {
        if (vetAux[i] == 0) // o elemento que nao tiver 1 tem 0, eh o que falta
        {
            printf("[%d]", i); // printamos o elemento com 0
            break;
        }
    }
    printf("\n");

    free(vetAux); // limpa o lixo colocado
    return 0;
}
