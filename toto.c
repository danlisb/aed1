#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inserir números na árvore binária e no final dizer se é AVL ou não

typedef struct _node
{
    struct *direita;
    struct *esquerda;
} Node;

void RSD()
{
    ((*direita)->(*esquerda));
}

void RSE()
{
    ((*esquerda)->(*direita));
}

void FB(*Node)
{
    if ( (*(esquerda)) - (*(direita)) < -1 || (*(esquerda)) - (*(direita)) > 1 )
        Balancear(); // não está balanceada
    return 0;        // balanceada, ok
}

void inserir(*Node)
{
    malloc(sizeof(Node));
}

int main()
{
    while(1) {
        char escolha;
        int FB;

        printf("Olá, digite os números que deseja adicionar na árvore binária ou digite 's' para sair\n");
        scanf("%c", &escolha);

        switch (escolha)
        {
        case 's' || "S":
            return 0;
            break;
        
        default:
            break;
        }

        if(FB = 0)
        {
            printf("É uma árvore AVL!");
        } 
            printf("Não é uma árvore AVL");
        }
    return 0;
}
