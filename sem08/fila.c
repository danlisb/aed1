#include <stdio.h>
#include <stdlib.h>

typedef struct _STipoFila
{
    int info;
    struct _STipoFila *pNext;
} STipoFila;

typedef struct
{
    STipoFila *pFirst;
    STipoFila *pLast;
} SFila;

void PUSH(SFila *pFila, int pProd)
{
    STipoFila *pNovo;
    pNovo = (STipoFila *)malloc(sizeof(STipoFila));
    pNovo->info = pProd;
    pNovo->pNext = NULL;

    if (pFila->pLast != NULL)
        pFila->pLast->pNext = pNovo;
    else
        pFila->pFirst = pNovo;

    pFila->pLast = pNovo;
}

int POP(SFila *pFila, int *pInt)
{
    STipoFila *pNodo;

    if (pFila->pFirst == NULL)
    {
        printf("Fila Vazia!\n");
        return 0;
    }
    else
    {
        pNodo = pFila->pFirst;
        *pInt = pFila->pFirst->info;
        pFila->pFirst = pFila->pFirst->pNext;

        if (pFila->pFirst == NULL)
            pFila->pLast = NULL;

        free(pNodo);
        return 1;
    }
}

void imprimeFila(SFila *pFila)
{
    for (STipoFila *p = pFila->pFirst; p != NULL; p = p->pNext)
    {
        printf("%d\n", p->info);
    }
}

int main()
{
    SFila fila;

    fila.pFirst = NULL;
    fila.pLast = NULL;

    PUSH(&fila, 5);
    PUSH(&fila, 6);
    PUSH(&fila, 100);

    imprimeFila(&fila);

    int elemento;
    POP(&fila, &elemento);
    printf("Elemento: %i\n\n", elemento);

    imprimeFila(&fila);

    POP(&fila, &elemento);
    printf("Elemento: %i\n\n", elemento);

    imprimeFila(&fila);
    printf("\n");

    PUSH(&fila, 89);
    imprimeFila(&fila);
}