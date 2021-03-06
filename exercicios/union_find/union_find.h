#ifndef UF_H
#define UF_H

#include <stdlib.h>

struct Aresta {
    int origem, destino, peso;
};
typedef struct Aresta aresta;
 
struct Grafo {
    int V; // Numero de vertices
    int E; // Numero de arestas
    
    // O grafo eh representado por um vetor de arestas
    aresta* VetorDeArestas; 
};
typedef struct Grafo grafo;

struct Subset {
    int pai;  // Representante do grupo
    int rank; // Altura do grupo, utilizado para uniao ponderada
};
typedef struct Subset subset;


// Funcoes para criacao dos grafos
grafo* criarGrafo(int V, int E);
void destruirGrafo(grafo *g);

// funcoes Uion-Find
subset *Make_Subset(int tamanho);
void Destroy_Subset(subset *s);
void Make_Set(subset subconjuntos[], int i);
int Find_Set(subset subconjuntos[], int i);
void Union(subset subconjuntos[], int x, int y);

// Funcoes especificas de grafos que utilizam Union-Find
bool TemCiclo( grafo* g );
int QuantidadeComponentesConexas( grafo* g );
int MaiorComponenteConexa( grafo* g );
int SomaPesoArestasDaArvoreGeradoraMinima( grafo* g );

#endif
