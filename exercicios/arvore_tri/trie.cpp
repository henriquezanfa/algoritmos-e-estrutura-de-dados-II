#include "trie.h"

// DICA: Estude o arquivo trie.h antes de iniciar a sua implementacao!

no *criarNo(void)
{
    // IMPLEMENTAR !!!
    // Dica: Aloca um no, atribua o tipo como 'I' e todos os filhos como NULL.
    return NULL;
}

void apagarArvore(no *raiz)
{
    // IMPLEMENTAR !!!
    // Dica 1: Desaloque todos os nos filhos e depois desaloca o no atual.
    // Dica 2: Usar recursao facilita!
}

void adicionarPalavra(char *palavra, no *raiz)
{
    // IMPLEMENTAR !!!
    // Dica 1: Use um laco iterativo de 0 ate strlen(palavra)
    // Dica 2: Criar o no com a funcao criarNo (caso nao existir)
    // Dica 3: Utilize a macro CHAR_TO_INDEX (ver trie.h) para converter o caractere para o indice filho
    // Dica 4: Nao esqueca de mudar o tipo para 'P' no ultimo noh que representa o ultimo caractere
}

int buscaPalavra(char *palavra, no *raiz)
{
    // IMPLEMENTAR !!!
    // Dica 1: Funcao similar ao adicionarPalavra
    // Dica 2: Se o ultimo noh que representa o ultimo caractere for do tipo 'I', a palavra nao existe
    // IMPORTANTE:
    //   retorne 0 se a palavra nao exite
    //   retorne 1 se a palavra existir
    return 0;
}

int numeroDeNos(no *r)
{
    // IMPLEMENTAR !!!
    // Dica: A funcao pode ser muito simples se utilizar recursao
    return 0;
}

int numeroDePalavras(no *r)
{
    // IMPLEMENTAR !!!
    // Dica: Similar a funcao numeroDeNos, mas contabilize apenas os tipos 'P', que representa as palavras
    return 0;
}

int altura(no *r)
{
    // IMPLEMENTAR !!!
    // Dica: A funcao pode ser muito simples se utilizar recursao
    return 0;
}

void removerPalavra(char *palavra, no *raiz)
{
    // IMPLEMENTAR !!!
    // Nota: Esta funcao eh a mais elaborada. Recomendo criar funcoes auxiliares e utilizar recursao
}
