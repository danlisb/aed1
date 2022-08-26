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

void validaRealloc(void *pBuffer, void *resul)
{
    if (resul == NULL)
    {
        printf("\nErro de alocação de memória!\n");
        getchar();
        free(pBuffer);
        exit(EXIT_FAILURE);
    }
}

void saveType(char tipo, char **tipoBuff, int tamBuff)
{
    void *temp = realloc(*tipoBuff, tamBuff);
    validaRealloc(*tipoBuff, temp);
    *(char *)(temp + tamBuff - sizeof(char)) = tipo;
    *tipoBuff = temp;
}

int main()
{
    char escolha;

    int *pBuffer = NULL, *pTemp;

    char *types = NULL;
    int pBufferSize = 0, typesSize = 0, numCount = 0;

    while (1)
    {
        printf("Escolha se quer adicionar números em formato de int, float ou double, quando quiser parar digite 'n' (i/f/d/n)\n");
        escolha = getchar();
        limpaBuffer();

        switch (escolha)
        {
        case 'i':
            numCount++;
            pTemp = realloc(pBuffer, pBufferSize + sizeof(int));
            validaRealloc(pBuffer, pTemp);
            pBuffer = pTemp;

            printf("Digite seu número inteiro: ");
            scanf("%d", (int *)((void *)pBuffer + pBufferSize));

            pBufferSize += sizeof(int);
            typesSize += sizeof(char);
            saveType('i', &types, typesSize);

            limpaBuffer();
            break;

        case 'f':
            numCount++;
            pTemp = realloc(pBuffer, pBufferSize + sizeof(float));
            validaRealloc(pBuffer, pTemp);
            pBuffer = pTemp;

            printf("Digite seu float: ");
            scanf("%f", (float *)((void *)pBuffer + pBufferSize));

            pBufferSize += sizeof(float);
            typesSize += sizeof(char);
            saveType('f', &types, typesSize);

            limpaBuffer();
            break;

        case 'd':
            numCount++;
            pTemp = realloc(pBuffer, pBufferSize + sizeof(double));
            validaRealloc(pBuffer, pTemp);
            pBuffer = pTemp;

            printf("Digite seu double: ");
            scanf("%lf", (double *)((void *)pBuffer + pBufferSize));

            pBufferSize += sizeof(double);
            typesSize += sizeof(char);
            saveType('d', &types, typesSize);

            limpaBuffer();
            break;

        case 'n':
            printf("Seus números digitados foram: \n\n");
            void *ptr = pBuffer;

            // Exibe todos os números na ordem em que foram digitados
            for (int i = 0; i < numCount; i++)
            {
                switch (types[i])
                {
                case 'i':
                    printf("\t%d", *((int *)ptr));
                    ptr += sizeof(int);
                    break;

                case 'f':
                    printf("\t%.2f", *((float *)ptr));
                    ptr += sizeof(float);
                    break;

                case 'd':
                    printf("\t%.4lf", *((double *)ptr));
                    ptr += sizeof(double);
                    break;
                }

                printf("\n");
            }

            getchar();

            printf("----------------------------------------\n\n");

            // Exibe todos os ints na ordem que foram digitados
            ptr = pBuffer;
            for (int i = 0; i < numCount; i++)
            {
                switch (types[i])
                {
                case 'i':
                    printf("\t%d\n", *((int *)ptr));
                    ptr += sizeof(int);
                    break;

                case 'f':
                    ptr += sizeof(float);
                    break;

                case 'd':
                    ptr += sizeof(double);
                    break;
                }
            }

            // Exibe todos os floats na ordem que foram digitados
            ptr = pBuffer;
            for (int i = 0; i < numCount; i++)
            {
                switch (types[i])
                {
                case 'i':
                    ptr += sizeof(int);
                    break;

                case 'f':
                    printf("\t%.2f\n", *((float *)ptr));
                    ptr += sizeof(float);
                    break;

                case 'd':
                    ptr += sizeof(double);
                    break;
                }
            }

            // Exibe todos os doubles na ordem que foram digitados
            ptr = pBuffer;
            for (int i = 0; i < numCount; i++)
            {
                switch (types[i])
                {
                case 'i':
                    ptr += sizeof(int);
                    break;

                case 'f':
                    ptr += sizeof(float);
                    break;

                case 'd':
                    printf("\t%.4lf\n", *((double *)ptr));
                    ptr += sizeof(double);
                    break;
                }
            }

            free(pBuffer);
            exit(EXIT_SUCCESS);
            break;
        }

        printf("\n\n");
    }
    return 0;
}