/* Daniel Lisboa
Lista 9 - Exercício 11 
Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o endereço das posições contendo valores pares. */
#include <stdio.h>
#include <stdlib.h>

int main () {
    int arr[5], i, *par;

    printf("Digite 5 valores: \n");
    for (i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }
    printf("Os valores dos endereços digitados foram: %d, %d, %d, %d, %d.\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

    for(i = 0; i < 5; i++) {
        if (arr[i] % 2 == 0) {
            printf("Endereço com valor par: arr[%d]\n", i);
        }
   }

    return 0;
}
