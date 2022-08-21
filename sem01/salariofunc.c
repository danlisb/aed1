// Daniel Lisboa
// Lista 1 - Exercício 38
#include <stdio.h>

int main() {
    int sal, novoSal;

    printf("Digite o salário do funcionário: ");
    scanf("%d", &sal);

    novoSal = sal * 1.25;

    printf("O novo salário do funcionário é: %d\n", novoSal);

    return 0;
}