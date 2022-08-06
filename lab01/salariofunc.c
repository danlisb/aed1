#include <stdio.h>

int main() {
    //Lista 1 Ex. 38

    int sal, novoSal;

    printf("Digite o salário do funcionário: ");
    scanf("%d", &sal);

    novoSal = sal * 1.25;

    printf("O novo salário do funcionário é: %d\n", novoSal);

    return 0;
}