#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void limpaBuffer()
{
    while (getchar() != '\n')
    {
        continue;
    }
}

int main()
{
    int *i;
    char escolha;
    float *f;
    double *d;
    int *pBuffer = malloc(*pBuffer, sizeof((int)(*i)) * sizeof((float)(*f)) * sizeof((double)(*d)));

    while (1)
    {
        printf("Escolha se quer adicionar números em formato de int, float ou double, quando quiser parar parar digite 'n' (i/f/d/n)\n");
        getchar(escolha);

        switch (escolha)
        {
        case 'i':
            printf("Digite seu número inteiro: ");
            scanf("%i", i);
            limpaBuffer();

        case 'f':
            printf("Digite seu float: ");
            scanf("%f", f);
            limpaBuffer();

        case 'd':
            printf("Digite seu double: ");
            scanf("%d", d);
            limpaBuffer();

        case 'n':
            printf("Seus números digitados foram: %i\n", *pBuffer);
            break;
        }
    }
    return 0;
}