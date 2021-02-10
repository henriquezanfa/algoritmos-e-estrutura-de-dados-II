// ATENCAO, NAO ALTERAR ESTE CODIGO !!!
// ATENCAO, NAO ALTERAR ESTE CODIGO !!!
// ATENCAO, NAO ALTERAR ESTE CODIGO !!!

#ifndef TRIE_H
#define TRIE_H

#include <stdlib.h>
#include <string.h>

#define TAMANHO_ALFABETO (27)                // Cada noh tem um vetor de ponteiros para os filhos, um para cada letra.
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') // Conversor de letra para indice. Considerar apenas palavras minusculas.

struct trie_cel
{
    char tipo;                                // 'I': interno / 'P': palavra
    struct trie_cel *filho[TAMANHO_ALFABETO]; // Utilizar a funcao CHAR_TO_INDEX para obter o no filho de cada letra.
};
typedef struct trie_cel no;

// ATENCAO, NAO ALTERAR ESTE CODIGO !!!
// ATENCAO, NAO ALTERAR ESTE CODIGO !!!
// ATENCAO, NAO ALTERAR ESTE CODIGO !!!

no *criarNo(void);
void apagarArvore(no *raiz);
void adicionarPalavra(char *palavra, no *raiz);
int buscaPalavra(char *palavra, no *raiz);
int numeroDeNos(no *r);
int numeroDePalavras(no *r);
int altura(no *r);
void removerPalavra(char *palavra, no *raiz);

#endif

// ATENCAO, NAO ALTERAR ESTE CODIGO !!!
// ATENCAO, NAO ALTERAR ESTE CODIGO !!!
// ATENCAO, NAO ALTERAR ESTE CODIGO !!!
