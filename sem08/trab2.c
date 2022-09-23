#include <stdio.h>
#include <stdlib.h>
// Fazer um programa que teste se uma sequencia de caracteres fornecida pelo usuario é um palindromo
// ou seja, é uma palavra cuja primeira metade é simétrica à segunda metade.
// AABCCBA - sim
// ADDFDDA - sim
// ABFFBB - não
// o usuário digita uma letra e tecla enter até que ele digite X e enter para terminar a sequencia.
// usar POP e PUSH de pilha e resolva o problema com elas. No vídeo mostrar 4 casos de sim e 4 casos de não.
// pilha -> first in last out (FILO)

typedef struct _STipoPilha
{
    char *pFirst;
    char *info;
    char *pLast;
} STipoPilha;

void PUSH(STipoPilha* pLast, char info) {
    char *p, *pFirst;
    
    if (pLast = NULL) {
        printf("Não há elementos na pilha");
    }
    else {
    pLast -> info = pFirst;
    }
}

int POP(STipoPilha* pFirst, char info) {
    if(pFirst = NULL) {
        printf("Não há elementos na pilha");
    }
    else {

    }
}

void palindromo() {

}

int main() {
        printf("Digite as letras do seu palindromo apertando enter, quando terminar a sequência aperte X+Enter.");
        getchar();
            switch (1) {
                {  
                case '\n':
                    palindromo();
                break;
                }
                case 'X': 
                {
                break;
                return 1;
                }
            }
        }  
