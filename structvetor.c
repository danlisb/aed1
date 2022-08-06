#include <stdio.h>

int main(){
    //Lista 6 Ex. 5

    struct Vetor {
        float x;
        float y;
        float z;
    };

    Vetor.x = 10;
    Vetor.y = 20;
    Vetor.z = 30;
    
    void somaVetores() {
        printf("A soma do vetor x e y é: %.2f.", Vetor.x + Vetor.y);
        printf("A soma do vetor y e z é: %.2f.", Vetor.y + Vetor.z);
        printf("A soma do vetor x e z é: %.2f.", Vetor.x + Vetor.z);
    };

    somaVetores();

    return 0;
}