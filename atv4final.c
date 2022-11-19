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

    for (int i = 0; i < numsSize + 1; i++) // 
    {
        printf("[%d]", vetAux[i]);
    }
    printf("\n");

    for (int i = 0; i < numsSize; i++)
    {
        printf("[%d]", nums[i]);
    }

    for (int j = 0; j < numsSize; j++)
    {
        tmp = nums[j];
        vetAux[tmp] = 1;
    }

    printf("\n");
    for (int i = 0; i < numsSize + 1; i++)
    {
        printf("[%d]", vetAux[i]);
    }
    printf("\n");

    for (int i = 0; i < numsSize + 1; i++)
    {
        if (vetAux[i] == 0)
        {
            printf("[%d]", i);
            break;
        }
    }
    printf("\n");

    free(vetAux);
    return 0;
}