#include <cstdio>
#include "union_find.h"

grafo* criarGrafo(int V, int E) {
    grafo* g = (grafo*) malloc( sizeof(grafo) );
    g->V = V;
    g->E = E;
    g->VetorDeArestas = (aresta*) malloc(g->E * sizeof(aresta) );
    return g;
}

void destruirGrafo(grafo *g) {
    free(g->VetorDeArestas);
    free(g);
}

subset *Make_Subset(int tamanho) {
    subset *subconjuntos = (subset*) malloc(tamanho * sizeof(subset));
    for (int i=0; i<tamanho; i++) {
        Make_Set(subconjuntos, i);
    }
    return subconjuntos;
}

void Destroy_Subset(subset *s) {
    free(s);
}

void Make_Set(subset subconjuntos[], int i) {
    subconjuntos[i].pai = i;
    subconjuntos[i].rank = 0;
}

// Funcao que procura o representante (pai) do elemento i com compressao de caminho.
int Find_Set(subset subconjuntos[], int i) {
    if(i != subconjuntos[i].pai) 
        subconjuntos[i].pai = Find_Set(subconjuntos, subconjuntos[i].pai);
    
    return subconjuntos[i].pai;
}

// Funcao que junta os conjuntos de x e y com uniao ponderada.
void Union(subset subconjuntos[], int x, int y) {
    x = Find_Set(subconjuntos, x);
    y = Find_Set(subconjuntos, y);

    if (subconjuntos[x].rank > subconjuntos[y].rank) {
        subconjuntos[y].pai = x;
    } else {
        subconjuntos[x].pai = y;
        if (subconjuntos[y].rank == subconjuntos[x].rank)
            subconjuntos[y].rank++;
    }
}

// Funcao utilizada para verificar se o grafo tem ou nao ciclo
bool TemCiclo( grafo* g ) {
    bool tem_ciclo = false;
    subset *s = Make_Subset(g->V);
    // DICA: Faca um laco de 0 ate g->E unindo os vertices.
    //       Caso os verticies ja pertencerem ao memso componente conexo (usar Find_Set),
    //       significa que o grafo tem um ciclo.
    for(int i = 0; i < g->E; i ++) {
        int rx = Find_Set(s, g->VetorDeArestas[i].origem);
        int ry = Find_Set(s, g->VetorDeArestas[i].destino);
        if (rx == ry) {
            tem_ciclo = true;
            break;
        }
    }
    Destroy_Subset(s);
    return tem_ciclo;
}

int QuantidadeComponentesConexas( grafo* g ) {
    // IMPLEMENTAR !!!
    // IMPLEMENTAR !!!
    // IMPLEMENTAR !!!
    subset *s = Make_Subset(g->V);
    for(int i=0; i<g->E; i++) {
        int rx = Find_Set(s, g->VetorDeArestas[i].origem);
        int ry = Find_Set(s, g->VetorDeArestas[i].destino);
        if (rx!=ry)
        	Union(s, rx, ry);
    }
	int nc=0;
    // DICA: Quando o elemento i for o mesmo que o pai[i] (se representante), significa que representa um componente conexo.
    //       Basta contar a quantidade de vertices nesta situacao...
    Destroy_Subset(s);
    return nc;
}


int MaiorComponenteConexa( grafo* g ) {
    // IMPLEMENTAR !!!
    // IMPLEMENTAR !!!
    // IMPLEMENTAR !!!
    // DICA: Inicio similar a funcao anterior, mas eh preciso contar quantos vertices tem cada
    //       componente conexo para descobrir qual eh de maior quantidade.
    //       Tente criar um vetor auxiliar (tamanho g->V), percorrer todos os vertices e
    //       incrementar o no representante (pai) para cada vertice. Assim, basta buscar a maior contagem.
    return 0;
}

int SomaPesoArestasDaArvoreGeradoraMinima( grafo* g ) {
    // IMPLEMENTAR !!!
    // IMPLEMENTAR !!!
    // IMPLEMENTAR !!!
    // DICA: Use o algoritmo de Kruskal (disponivel no slide):
    //       Ordene as arestas por peso e crie um contador que soma todos os pesos
    //       utilizados na formacao da Arvore Geradora Minima.
    return 0;
}


int main() {

    // subset *b = Make_Subset(11);
    
    // // // printf("%d \n", a[0].pai);
    // // Union(b, 0, 1);
    // // Union(b, 0, 2);
    // // Union(b, 2, 3);
    // // Union(b, 6, 5);
    // // Union(b, 6, 4);
    // // Union(b, 8, 9);
    // // Union(b, 3, 8);
    // // Union(b, 0, 9);
    // // Union(b,)
    // Union(b, 0, 1);
    // printf("%d  -> %d, %d\n", 0, b[0].pai, b[0].rank);
    // printf("%d  -> %d, %d\n\n", 1, b[1].pai, b[1].rank);
    // Union(b, 0, 2);
    // printf("%d  -> %d, %d\n", 0, b[0].pai, b[0].rank);
    // printf("%d  -> %d, %d\n\n", 2, b[2].pai, b[2].rank);
    // Union(b, 2, 3);
    // printf("%d  -> %d, %d\n", 2, b[2].pai, b[2].rank);
    // printf("%d  -> %d, %d\n\n", 3, b[3].pai, b[3].rank);
    // Union(b, 6, 5);
    // printf("%d  -> %d, %d\n", 6, b[6].pai, b[6].rank);
    // printf("%d  -> %d, %d\n\n", 5, b[5].pai, b[5].rank);
    // Union(b, 6, 4);
    // printf("%d  -> %d, %d\n", 6, b[6].pai, b[6].rank);
    // printf("%d  -> %d, %d\n\n", 4, b[4].pai, b[4].rank);
    // Union(b, 8, 9);
    // printf("%d  -> %d, %d\n", 8, b[8].pai, b[8].rank);
    // printf("%d  -> %d, %d\n\n", 9, b[9].pai, b[9].rank);
    // Union(b, 3, 8);
    // printf("%d  -> %d, %d\n", 3, b[3].pai, b[3].rank);
    // printf("%d  -> %d, %d\n\n", 8, b[8].pai, b[8].rank);
    // Union(b, 0, 9);
    // printf("%d  -> %d, %d\n", 0, b[0].pai, b[0].rank);
    // printf("%d  -> %d, %d\n\n", 9, b[9].pai, b[9].rank);


    // for(int i = 0; i < 11; i ++) {
    //     printf("%d  -> %d, %d\n", i, b[i].pai, b[i].rank);
    // }

    // printf("%d\n", Find_Set(b, 2));

    int vetor_auxiliar[4] = { 0 };
    vetor_auxiliar[2]++;

    for(int i = 0; i < 4; i ++) {
        printf("%d", vetor_auxiliar[i]);
    }


    
}