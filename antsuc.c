#include <stdio.h>

int main() {
    //Lista 1 Ex. 31

    int x;

    printf("Digite um número: ");
    scanf("%d", &x);

    printf("O antecessor do número digitado é: %d\n", --x);
    printf("O sucessor do número digitado é: %d\n", x + 2);

    return 0;
}