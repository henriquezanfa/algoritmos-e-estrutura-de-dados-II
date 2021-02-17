#include "trie.h"

#include <stdio.h>

// DICA: Estude o arquivo trie.h antes de iniciar a sua implementacao!

no *criarNo(void)
{
    no *node = (no *)malloc(sizeof(no));

    if (node)
    {
        int i;
        node->tipo = 'I';
        for (i = 0; i < TAMANHO_ALFABETO; i++)
            node->filho[i] = NULL;
    }

    return node;
}

void apagarArvore(no *raiz)
{
    int i;
    for (i = 0; i < TAMANHO_ALFABETO; i++)
    {
        if (raiz->filho[i] != NULL)
        {
            apagarArvore(raiz->filho[i]);
            raiz->filho[i] == NULL;
        }
    }

    free(raiz);
}

void adicionarPalavra(char *palavra, no *raiz)
{
    int nivel = 0, indice;
    no *aux = raiz;

    for (nivel = 0; nivel < strlen(palavra); nivel++)
    {
        indice = CHAR_TO_INDEX(palavra[nivel]);
        if (aux->filho[indice] == NULL)
            aux->filho[indice] = criarNo();

        aux = aux->filho[indice];
    }

    aux->tipo = 'P';
}

int buscaPalavra(char *palavra, no *raiz)
{
    int i = 0, indice;

    no *aux = raiz;

    for (i = 0; i < strlen(palavra); i++)
    {
        indice = CHAR_TO_INDEX(palavra[i]);
        if (aux->filho[indice] != NULL)
            aux = aux->filho[indice];
        else
            break;
    }

    if (palavra[i] == '\0' && aux->tipo == 'P')
        return 1;
    else
        return 0;
}

int numeroDeNos(no *r)
{
    int i, numero = 0;

    for (i = 0; i < TAMANHO_ALFABETO; i++)
    {
        if (r->filho[i] != NULL)
        {
            numero += numeroDeNos(r->filho[i]);
        }
    }

    return numero + 1;
}

int numeroDePalavras(no *r)
{
    int i, numero = 0;

    if (r->tipo == 'P')
    {
        numero++;
    }
    for (i = 0; i < TAMANHO_ALFABETO; i++)
    {
        if (r->filho[i] != NULL)
        {
            numero += numeroDePalavras(r->filho[i]);
        }
    }

    return numero;
}

int altura(no *r)
{
    int i, ref = 0;

    if (!r)
        return 0;

    for (i = 0; i < TAMANHO_ALFABETO; i++)
    {
        int numero = altura(r->filho[i]);
        if (numero > ref)
        {
            ref = numero;
            return ref + 1;
        }
    }

    return 1;
}

void removerPalavra(char *palavra, no *raiz)
{
    int i = 0, indice;

    no *aux = raiz;

    for (i = 0; i < strlen(palavra); i++)
    {
        indice = CHAR_TO_INDEX(palavra[i]);
        if (aux->filho[indice] != NULL)
            aux = aux->filho[indice];
        else
            break;
    }

    if (palavra[i] == '\0' && aux->tipo == 'P')
        aux->tipo = 'I';
}

void imprimeRaiz(no *raiz)
{
    int i;

    printf("(%c:", raiz->tipo);
    for (i = 0; i < TAMANHO_ALFABETO; i++)
    {
        if (raiz->filho[i] != NULL)
        {
            printf("%c", (int)'a' + (int)i);
            imprimeRaiz(raiz->filho[i]);
        }
    }

    printf(")");
}

int main()
{
    no *raiz = criarNo();

    adicionarPalavra("pal", raiz);
    adicionarPalavra("pa", raiz);
    adicionarPalavra("pato", raiz);
    adicionarPalavra("pate", raiz);
    adicionarPalavra("pata", raiz);
    // adicionarPalavra("zebra", raiz);
    // adicionarPalavra("abacaxi", raiz);
    // adicionarPalavra("vermelho", raiz);
    // adicionarPalavra("martelo", raiz);

    imprimeRaiz(raiz);

    removerPalavra("pato", raiz);

    imprimeRaiz(raiz);
    // int numeroPalavras = numeroDePalavras(raiz);
    // printf("\nNumero de palavras: %d", numeroPalavras);
    // int numeroNos = numeroDeNos(raiz);
    // printf("\nNumero de nos: %d", numeroNos);

    // int temPalavra = buscaPalavra("arvore", raiz);

    // printf("%d", temPalavra);

    apagarArvore(raiz);

    return 0;
}