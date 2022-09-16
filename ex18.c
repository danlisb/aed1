// Daniel Lisboa
// Lista ED 5 - Exercício 9
// Implemente uma função que calcule a área da superfície e o volume de
// uma esfera de raio R. Essa função deve obedecer ao protótipo:
// void calc_esfera(float R, float *area, float *volume)
// A área da superfície e o volume são dados, respectivamente, por:
// A = 4 * p * R2
// V = 4/3 * p * R3
#include <stdio.h>

void calc_esfera(float R, float *area, float *volume) {
    
    float pi = 3.1415;

    *area = 4 * pi * R * R;
    *volume = (4/3) * pi * R * R * R;
}

int main () {
    float R, area, volume;

    printf("Digite o raio: ");
    scanf("%f", &R);

    calc_esfera(R, &area, &volume);

    printf("A área da superfície é: %.2f\n", area);
    printf("O volume da esfera é: %.2f\n", volume);

    return 0;
}