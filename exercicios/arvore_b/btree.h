#ifndef BTREE_H
#define BTREE_H

struct btNo
{
    bool ehFolha;            // false se nao for uma folha, true se for uma folha.
    unsigned char numChaves; // Quantidade total de chaves no noh
    int *chaves;             // Ponteiro para uma lista com as chaves
    btNo **filhos;           // Ponteiro para uma lista de ponteiros dos nos filhos
};

struct bTree
{
    btNo *raiz;          // Ponteiro para o noh raiz
    unsigned char ordem; // Quantidade máxima de filhos
};

bTree btCriar(const unsigned char ordem);
void btDestruir(bTree t);
int btBuscar(bTree t, int chave);
void btInserir(bTree t, int key);
int btAltura(bTree t);
int btContaNos(bTree t);
int btContaChaves(bTree t);

#endif
