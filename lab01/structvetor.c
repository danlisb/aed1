/*Daniel Lisboa
Lista 6 Exercício 5
Considerando a estrutura
struct Vetor{
    float x;
    float y;
    float z;
};
para representar um vetor no R3, implemente um programa que calcule a soma de dois vetores.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct Vetor {
        float x;
        float y;
        float z;
    };

    struct Vetor vetores;
    vetores.x = 10;
    vetores.y = 20;
    vetores.z = 30;

    printf("A soma do vetor x e y é: %.2f.\n", vetores.x + vetores.y);
    printf("A soma do vetor y e z é: %.2f.\n", vetores.y + vetores.z);
    printf("A soma do vetor x e z é: %.2f.\n", vetores.x + vetores.z);

    return 0;
}