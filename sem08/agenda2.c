#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearStdinBuffer()
{
    while (getchar() != '\n')
    {
        continue;
    }
}

int main()
{
    // quantidade variáveis declaradas no pBuffer
    void *pBuffer = malloc(10 * sizeof(int) + 11 * sizeof(char) + sizeof(void **));
    // número de pessoas na lista
    int *nroPessoas = (int *)pBuffer;
    // tamanho de cada pessoa
    int *pessoaSize = nroPessoas + 1;

    // ponteiro para o inicio da lista duplamente ligada
    void **listaPessoasStart = (void **)(pessoaSize + 1);

    //  salva o tamanho do deslocamento para acessar cada campo das informações ("vetor")
    int *telShift = (int *)(listaPessoasStart + 1);
    int *nomeShift = telShift + 1;
    int *ptrAnteriorShift = nomeShift + 1;
    int *ptrProxShift = ptrAnteriorShift + 1;

    // outras variáveis de uso geral
    char *choice = (char *)(ptrProxShift + 1);
    int *i = (int *)(choice + 1);
    int *size = i + 1;
    int *num = size + 1;
    char *nomeBusca = (char *)(num + 1); // tamanho 10
    int *encontrou = (int *)(nomeBusca + 10);

    // inicializações de variáveis
    *pessoaSize = 2 * sizeof(int) + 10 * sizeof(char) + 2 * sizeof(void **); // tel+idade +nome + prox+anterior
    *nroPessoas = 0;
    *encontrou = 0;
    *listaPessoasStart = NULL;

    // atribuições dos deslocamentos
    *telShift = sizeof(int);
    *nomeShift = sizeof(int) + *telShift;
    *ptrAnteriorShift = *nomeShift + 10 * sizeof(char);
    *ptrProxShift = *ptrAnteriorShift + sizeof(void **);

    while (1)
    {
        printf("Olá! Digite a sua opção: \n");
        printf("\n1 - Adicionar\n2 - Apagar\n3 - Buscar\n4 - Listar\n5 - Sair\n");
        *choice = getchar();
        clearStdinBuffer();

        switch (*choice)
        {
        case '1': // Adiciona uma pessoa no fim da lista 
        {
            // soma 1 na região que tem o número de pessoas na lista p/ começar pela pessoa "1"
            (*nroPessoas)++;

            // aloca novo elemento na memória
            void *newElement = malloc(*pessoaSize);

            // verifica se foi criado um elemento
            if (newElement == NULL)
            {
                printf("\nErro de alocacao de memoria!\n");
                getchar();
                exit(EXIT_FAILURE);
            }

            // ajusta o tamanho da memória com o deslocamento para salvar o novo número de pessoas
            printf("\nDigite o nome desejado: ");
            scanf("%9[^\n]s", (char *)(newElement + *nomeShift));
            clearStdinBuffer();

            printf("Digite a idade: ");
            scanf("%d", (int *)newElement);
            clearStdinBuffer();

            printf("Digite o numero de telefone (sem DDD): ");
            scanf("%d", (int *)(newElement + *telShift));
            clearStdinBuffer();

            if (*listaPessoasStart) // não executa se a lista for nula (lista vazia)
            {
                // percorre a lista para encontrar onde o novo elemento vai
                void *p = *listaPessoasStart, *pAnterior = NULL;

                while ((p != NULL) && (strcmp((char *)(p + *nomeShift), (char *)(newElement + *nomeShift)) < 1))
                {
                    pAnterior = p;
                    p = *(void **)(p + *ptrProxShift); // p = p->prox
                }

                if (p != NULL)
                {
                    if (pAnterior)
                        *(void **)(pAnterior + *ptrProxShift) = newElement; // só executa se pAnterior não for nulo, para não ocorrer acesso inadereçável
                    else
                        *listaPessoasStart = newElement; // se pAnterior for nulo, é pq está inserindo no início da lista, então altera-se o inicio dela

                    // configura ponteiros de anterior e próximo do novo elemento e dos elementos em volta
                    *(void **)(p + *ptrAnteriorShift) = newElement;
                    *(void **)(newElement + *ptrAnteriorShift) = pAnterior;
                    *(void **)(newElement + *ptrProxShift) = p;
                }
                else
                {
                    // configura ponteiros de anterior e próximo do novo elemento e do elemento anterior(pois ele está no fim da lista nesse else)
                    *(void **)(pAnterior + *ptrProxShift) = newElement;
                    *(void **)(newElement + *ptrAnteriorShift) = pAnterior;
                    *(void **)(newElement + *ptrProxShift) = NULL;
                }
            }
            else
            {
                // anterior e próximo nulos pois aqui a lista é vazia
                *(void **)(newElement + *ptrAnteriorShift) = NULL;
                *(void **)(newElement + *ptrProxShift) = NULL;

                *listaPessoasStart = newElement;
            }
            break;
        }

        case '2': // Apagar
        {
            printf("\nDigite o número da pessoa para apagar: ");
            scanf("%d", num);
            clearStdinBuffer();

            void *p = *listaPessoasStart;
            
            // verifica se a lista está vazia
            if (p == NULL)
            {
                printf("\nOperacao invalida! A lista esta vazia!\n");
                getchar();
                break;
            }
            
            // verifica se o número da pessoa é válido (existe na lista)
            if (*num > *nroPessoas)
            {
                printf("\nNumero invalido!\n");
                getchar();
                break;
            }

            *i = 1;
            for (; p != NULL && *i < *num; p = *(void **)(p + *ptrProxShift))
            {
                (*i)++;
            }

            // encontrou
            if (*i == *num)
            {
                // se ele houver ptr Anterior
                if (*(void **)(p + *ptrAnteriorShift))
                {
                    void *pAnterior = *(void **)(p + *ptrAnteriorShift);
                    *(void **)(pAnterior + *ptrProxShift) = *(void **)(p + *ptrProxShift);
                }
                else // aponta para o próximo
                {
                    *listaPessoasStart = *(void **)(p + *ptrProxShift);
                }
                if (*(void **)(p + *ptrProxShift))
                {
                    void *pProx = *(void **)(p + *ptrProxShift);
                    *(void **)(pProx + *ptrAnteriorShift) = *(void **)(p + *ptrAnteriorShift);
                }
                free(p);
                (*nroPessoas)--;
            }
            else
            {
                printf("\nEste item nao existe!\n");
                getchar();
                break;
            }
            break;
        }

        case '3': // Buscar
        {
            printf("\nDigite o nome da pessoa para buscar: ");
            scanf("%9[^\n]s", nomeBusca);
            clearStdinBuffer();

            void *p = *listaPessoasStart;
            *i = 1;
            for (; p != NULL; p = *(void **)(p + *ptrProxShift))
            {
                if (!strcmp(nomeBusca, (char *)(p + *nomeShift)))
                {
                    printf("\nPessoa %d\n\tNome: %s\n\tIdade: %d\n\tTel: %d\n", *i, (char *)(p + *nomeShift), *(int *)p, *(int *)(p + *telShift));
                    *encontrou = 1;
                    getchar();
                    break;
                }
                (*i)++;
            }
            if (!(*encontrou))
            {
                printf("\nEsse nome não existe na lista!");
                getchar();
            }
            break;
        }

        case '4': // Listar
        {
            // acha a primeira pessoa na memória
            void *p = *listaPessoasStart;
            *i = 1;
            if (p) // faz "p" apontar para o ultimo elemento da lista se ela não for nula
            {
                for (; p != NULL; p = *(void **)(p + *ptrProxShift))
                {
                    printf("\nPessoa %d\n\tNome: %s\n\tIdade: %d\n\tTel: %d\n", *i, (char *)(p + *nomeShift), *(int *)p, *(int *)(p + *telShift));
                    (*i)++;
                }
            }
            getchar();
            break;
        }

        case '5': // Sair
        {
            // faz "p" apontar para o ultimo elemento da lista se ela não for nula
            if (*listaPessoasStart) 
            {
                void *ptr = *listaPessoasStart, *temp;

                for (; ptr != NULL; ptr = temp)
                {
                    temp = *(void **)(ptr + *ptrProxShift);
                    free(ptr);
                }
            }
            free(pBuffer);
            exit(EXIT_SUCCESS);
            break;
        }
        default:
            break;
        }
    }
    return 0;
}