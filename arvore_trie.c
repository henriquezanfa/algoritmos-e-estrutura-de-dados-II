#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TAMANHO_ALFABETO (27)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct trie_cel
{
    /**
     * 'I' => interno
     * 'P' => palavra
    */
    char tipo;

    struct trie_cel *filho[TAMANHO_ALFABETO];
};

typedef struct trie_cel no;

no *criarNo()
{
    int i;
    no *novo = (no *)malloc(sizeof(no));

    if (novo != NULL)
    {
        novo->tipo = 'I';

        for (i = 0; i < TAMANHO_ALFABETO; i++)
            novo->filho[i] = NULL;
    }

    return novo;
}

void adicionarPalavra(char *palavra, no *raiz)
{
    int nivel = 0, indice;
    no *tmp = raiz;

    for (nivel = 0; nivel < strlen(palavra); nivel++)
    {
        indice = CHAR_TO_INDEX(palavra[nivel]);
        if (tmp->filho[indice] == NULL)
            tmp->filho[indice] = criarNo();

        tmp = tmp->filho[indice];
    }

    tmp->tipo = 'P';
}

/*
    1 => se a palavra estiver na árvore
    2 => se a palavra não estiver na árvore
*/
int buscaPalavra(char *palavra, no *raiz)
{
    int i = 0, indice;
    no *tmp = raiz;

    for (i = 0; i < strlen(palavra); i++)
    {
        indice = CHAR_TO_INDEX(palavra[i]);
        if (tmp->filho[i] != NULL)
            tmp = tmp->filho[i];
        else
            break;
    }

    if (palavra[i] == '\0' && tmp->tipo == 'P')
        return 1;
    else
        return 0;
}

int main()
{
    no *raiz = criarNo();
    adicionarPalavra("abc", raiz);

    int palavra = buscaPalavra("abc", raiz);

    printf("Tem palavra: %d", palavra);

    return 0;
}