// Daniel Lisboa
// Lista 3 - Exercício 25
#include <stdio.h>

int main() {
    int soma = 0;
    for (int i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            soma = soma + i;
        }
    }
    printf("%i\n", soma); 
   return 0;
}