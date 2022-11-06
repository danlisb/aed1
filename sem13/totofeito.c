#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inserir números na árvore binária e no final dizer se é AVL ou não

// criação dos nós direita e esquerda e o inteiro 'n' que será o número que iremos  inserir na árvore
typedef struct _node
{
    int n;

    struct _node *direita;
    struct _node *esquerda;
} Node;

// função de arrumar os memory leaks usando a sequência de pós-ordem
void freeArv(Node* arv)
{
    if(arv == NULL)
        return;

    freeArv(arv->esquerda);
    freeArv(arv->direita);
    free(arv);
}

// calcula a altura da árvore
int pegaHeight(Node *arv)
{
    // se a árvore não existir a altura dela é -1 (logo, é uma AVL)
    if(arv == NULL)
        return -1;

    // pega a altura dos nós 
    int hDir = pegaHeight(arv->direita);
    int hEsq = pegaHeight(arv->esquerda);

    // utiliza-se o método de dividir a árvore em sub-árvores de direita e esquerda,
    // comparamos qual lado tem a maior altura,
    // e assim somamos 1 para achar a altura total da árvore 
    if(hDir > hEsq)
        return hDir + 1;
    else 
        return hEsq + 1;
}

// função que retorna o fator de balanceamento
int FB(Node *arv)
{ 
    // definição do FB (altura da sub-árvore esquerda - altura da sub-árvore direita)
    return pegaHeight(arv->esquerda) - pegaHeight(arv->direita);
}

// função que checa se a árvore é AVL
int verificaAVL(Node *arvore)
{
    if(arvore)
    {
        // por definição se o FB é < -1 ou > 1 a árvore não é AVL
        int fatorBalanceamento = FB(arvore);

        if(fatorBalanceamento < -1 || fatorBalanceamento > 1)
            return 0;
        else 
            return 1;
    }

    return 1;
}

// função para inserir nodo na árvore
Node *inserir(Node *arvore, int n, int *eAVL)
{
    if(arvore == NULL)
    {
        // usamos malloc para alocar memória no tamanho do Nodo
        Node *novaRaiz = (Node *)malloc(sizeof(Node));

        if(novaRaiz)
        {
            // se a árvore é NULL, então não existem elementos nela ainda, assim, criamos a raíz
            // e por isso aqui declaramos os nós da esquerda e direita como NULL 
            novaRaiz->n = n;
            novaRaiz->direita = novaRaiz->esquerda = NULL;

            return novaRaiz;
        }

        exit(EXIT_FAILURE);
    }

    // caso já exista elementos, verificamos se o número que adicionamos é maior ou menor que os outros elementos da árvore
    // se for menor adicionamos à esquerda, ao contrário, a direita.
    if(n < arvore->n)
        arvore->esquerda = inserir(arvore->esquerda, n, eAVL);
    else if(n > arvore->n)
        arvore->direita = inserir(arvore->direita, n, eAVL);
    
    // eAVL é uma flag que determinará a altura de cada nó do lado direito e esquerdo das sub-árvores, indicando se
    // todos nós passam na restrição de ser uma árvore AVL
    if(!verificaAVL(arvore))
        *eAVL = 0;

    return arvore;
}

// função de imprimir a árvore e a identa com um traço(-) ao imprimir 
void imprimeArv(Node *arv, int tab)
{
    if(arv == NULL)
        return;

    for (int i = 0; i < tab; i++)
        printf("-");

    printf("%d\n", arv->n);

    imprimeArv(arv->esquerda, tab + 1);
    imprimeArv(arv->direita, tab + 1);
}

int main()
{
    Node *arvore = NULL;

    // laço principal do programa
    while(1) {
        int escolha, num, eAVL;

        printf(
            "1- Inserir\n"
            "2- Imprimir árvore\n"
            "0- Sair\n");

        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0:
            freeArv(arvore);
            return 0;
            break;

        case 1:
            printf("Digite o número a inserir: ");
            scanf("%d", &num);

            eAVL = 1;
            arvore = inserir(arvore, num, &eAVL);
            break;

        case 2:
            if(arvore)
            {
                printf("Árvore: \n");
                imprimeArv(arvore, 0);
                if(eAVL)
                    printf("Essa árvore é AVL\n");
                else
                    printf("Essa árvore não é AVL\n");
            }
            else
                printf("Árvore vazia.\n");
            getchar();
            break;
            
        default:
            break;
        }
    }
    return 0;
}
