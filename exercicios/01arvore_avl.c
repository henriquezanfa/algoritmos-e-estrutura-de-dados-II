#include <stdio.h>
#include <stdlib.h>

struct cel
{
    int chave;
    struct cel *esq;
    struct cel *dir;
    int altura;
};

typedef struct cel no;

int altura(no *r)
{
    if (r == NULL)
        return 0;
    else
        return r->altura;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

no *criarNo(int k)
{
    no *novoElemento = (no *)malloc(sizeof(no));
    novoElemento->chave = k;
    novoElemento->esq = novoElemento->dir = NULL;
    novoElemento->altura = 1;
    return novoElemento;
}

no *rotacaoADireita(no *y)
{
    no *x = y->esq;
    no *T2 = x->dir;

    // rotacao
    x->dir = y;
    y->esq = T2;

    // atualizacao de altura
    y->altura = 1 + max(altura(y->esq), altura(y->dir));
    x->altura = 1 + max(altura(x->esq), altura(x->dir));

    return x;
}

no *rotacaoAEsquerda(no *x)
{
    no *y = x->esq;
    no *T2 = y->dir;

    // rotacao
    y->dir = x;
    x->esq = T2;

    // atualizacao de altura
    x->altura = 1 + max(altura(x->esq), altura(x->dir));
    y->altura = 1 + max(altura(y->esq), altura(y->dir));

    return y;
}

int fatorDeBalanceamento(no *r)
{
    if (r == NULL)
        return 0;
    else
        return altura(r->esq) - altura(r->dir);
}

no *inserirChave(no *r, int k)
{

    // insercao na ABB -- versao recursiva
    if (r == NULL)
        return criarNo(k);

    if (k == r->chave)
        return r;
    else
    {
        if (k < r->chave)
            r->esq = inserirChave(r->esq, k);
        else
            r->dir = inserirChave(r->dir, k);
    }

    // atualizacao da altura do no antecessor
    r->altura = 1 + max(altura(r->esq), altura(r->dir));

    // fator de balanceamento
    int fb = fatorDeBalanceamento(r);

    // ----------------------------------------------------------
    // se o no estiver desbalanceado, entao temos 4 alternativas

    // Caso LL:
    if (fb > 1 && k < r->esq->chave)
    {
        return rotacaoADireita(r);
    }

    // Caso RR:
    if (fb < -1 && k > r->dir->chave)
    {
        return rotacaoAEsquerda(r);
    }

    // Caso LR:
    if (fb > 1 && k > r->esq->chave)
    {
        r->esq = rotacaoAEsquerda(r->esq);
        return rotacaoADireita(r);
    }

    // Caso RL:
    if (fb < -1 && k < r->dir->chave)
    {
        r->dir = rotacaoADireita(r->dir);
        return rotacaoAEsquerda(r);
    }

    return r;
}

void erd(no *r)
{
    if (r != NULL)
    {
        erd(r->esq);
        erd(r->dir);
    }
}

void erdFB(no *r)
{
    if (r != NULL)
    {
        erdFB(r->esq);
        erdFB(r->dir);
    }
}

void zerar(no *arvore)
{
    if (arvore != null)
    {
        zerar(arvore->esq);
        zerar(arvore->dir);

        free(arvore)
    }
}

void imprime(no *arvore)
{
    printf("(");
    if (arvore != NULL)
    {
        printf("%d", arvore->chave);
        if (arvore->esq != NULL || arvore->dir != NULL)
        {
            imprime(arvore->esq);
            imprime(arvore->dir);
        }
    }
    printf(")");
}

// ------------------------------------------------
int main(int argc, char *argv[])
{
    int i, k, n;
    no *arvore = NULL;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        arvore = inserirChave(arvore, k);
    }
    imprime(arvore);
    zerar(arvore);
}
