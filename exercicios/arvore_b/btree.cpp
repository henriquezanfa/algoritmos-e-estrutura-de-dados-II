
#include <stdlib.h>
#include "btree.h"

bTree btCriar(const unsigned char ordem)
{
    bTree b;
    // IMPLEMENTAR!
    // DICA 1: Crie uma funcao auxiliar
    // DICA 2: Alem do no, nao esqueca de alocar a lista de chaves e filhos, de acordo com a ordem:
    //           A lista de chaves tem o tamanho da ordem (um a mais, utilizado como auxiliar)
    //           A lista de filhos tem o tamanho da ordem + 1 (um a mais, utilizado como auxiliar)
    // DICA 3: Nao esqueca de inicializar todos atributos (ver btree.h)
    return b;
}

void btDestruir(bTree b)
{
    // IMPLEMENTAR!
    // DICA 1: Destrua primeiro os filhos
    // DICA 2: Nao esqueca de desalocar a lista de chaves e filhos de cada noh
}

void btInserir(bTree b, int chave)
{
    // IMPLEMENTAR!
    // DICA 1: Crie funcoes auxiliares
    // DICA 2: Seguir o material de aula
}

int btBuscar(bTree b, int chave)
{
    // IMPLEMENTAR!
    // Retornar true se a chave nao existe false se a chave nao existe
    return 0;
}

int btAltura(bTree b)
{
    // IMPLEMENTAR!
    // DICA: Como todos os nos folhas estao no mesmo nivel em uma arvore B, busque qualquer noh folha contando a sua profundidade
    return 0;
}

int btContaNos(bTree b)
{
    // IMPLEMENTAR!
    // DICA: Implemente de modo recursivo
    return 0;
}

int btContaChaves(bTree t)
{
    // IMPLEMENTAR!
    // DICA: Muito similar a funcao btContaNos
    return 0;
}
