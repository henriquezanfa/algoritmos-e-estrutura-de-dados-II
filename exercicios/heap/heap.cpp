#include "heap.h"
#include "internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ATENCAO!!! ATENCAO!!! ATENCAO!!!
// ATENCAO!!! ATENCAO!!! ATENCAO!!!
// ATENCAO!!! ATENCAO!!! ATENCAO!!!
// --- CONSIDERE O INDICE ZERO (A[0]) A QUANTIDADE DE ELEMENTOS
// --- CONSIDERE QUE O VETOR VAI DE 1 ATE N (E NAO DE 0 ATE N-1)
// --- CONSIDERE QUE O VETOOR JA TEM UM TAMANHO SUFICIENTEMENTE GRANDE PARA A INSERCAO

int max_heapfy_count = 0;

void swap(long *a, long *b) {
    long aux = *a;
    *a = *b;
    *b = aux;
}

void MaxHeapify(tipoChave A[], int i)
{
    max_heapfy_count++;
    int e = 2*i;
    int d = 2*i + 1;
    int maior = i;

    if(e <= A[0] && A[e] > A[maior]) 
        maior = e;

    if(d <= A[0] && A[d] > A[maior]) 
        maior = d;

    if(maior != i) {
        swap(&A[i], &A[maior]);
        MaxHeapify(A, maior);
    }
}

void BuildMaxHeap(tipoChave A[])
{
    int start = (A[0]/2);
    for(int i = start; i > 0; i--) {
        MaxHeapify(A, i);
    }
}

void HeapSort(tipoChave A[])
{
    // IMPLEMENTAR
    // DICA: Como a funcao MaxHeapify nao tem o argumento tamanho (como nos slides),
    //       armazene o tamanho atual (t = A[0]), decremente A[0] antes de chamar
    //       MaxHeapify, entao restaure o valor A[0] = t no final.
    BuildMaxHeap(A);
    
    int tamanho = A[0];

    for(int i = tamanho; i > 0; i--){
        swap(&A[1], &A[i]);
        A[0] = A[0] - 1;
        MaxHeapify(A, 1);
    }

    A[0] = tamanho;
}

tipoChave HeapMaximum(tipoChave A[])
{
    return A[1];
}

tipoChave HeapExtractMax(tipoChave A[])
{
    if(A[0] < 1)
	    return 0;

    int max = A[1];

    A[1] = A[A[0] - 1];
    MaxHeapify(A, 1);
    return max;
}

void HeapIncreaseKey(tipoChave A[], int i, tipoChave key)
{
    // IMPLEMENTAR
    // OBS.: Nao precisa tratar o caso da chave alterada for menor que a chave atual!
    A[i] = key;
    while(i > 1 && A[i/2] < A[i]) {
        swap(&A[i], &A[i/2]);
        i = i/2;
    }
}

void MaxHeapInsert(tipoChave A[], tipoChave key)
{
    // IMPLEMENTAR
    // OBS.: Nao esquecer de aumentar a quantidade de elementos, ou seja, A[0]++

    A[0] = A[0] + 1;
    A[A[0]] = -9999;
    HeapIncreaseKey(A, A[0], key);

}


int main(int argc, char *argv[]) {
    tipoChave *A = NULL;
    int        n = 0;

    char comando[64];
    while(true) {
        scanf("%s", comando);

        if (strcmp(comando, "CRIAR") == 0) {
            scanf("%d", &n);
            if (A != NULL)
                free(A);
            A = (tipoChave*) malloc((n+1) * sizeof(tipoChave));
            A[0] = 0;
        }
        else if (strcmp(comando, "VALORES") == 0) {
            scanf("%ld", &A[0]);
            for (int i = 1; i <= A[0]; i++) {
                scanf("%ld", &A[i]);
            }
        }
        else if (strcmp(comando, "MAXHEAPIFY") == 0) {
            int i;
            scanf("%d", &i);
            MaxHeapify(A, i);
        }
        else if (strcmp(comando, "BUILDMAXHEAP") == 0) {
            max_heapfy_count = 0;
            BuildMaxHeap(A);
            if (max_heapfy_count < A[0] / 2)
                printf("ERRO: Vc precisa utilzar a funcao MaxHeapify\n");
        }
        else if (strcmp(comando, "HEAPSORT") == 0) {
            max_heapfy_count = 0;
            HeapSort(A);
            if (max_heapfy_count < A[0])
                printf("ERRO: Vc precisa utilzar a funcao MaxHeapify\n");
        }
        else if (strcmp(comando, "MAXIMUM") == 0) {
            printf("Max = %ld\n", HeapMaximum(A));
        }
        else if (strcmp(comando, "EXTRACT") == 0) {
            printf("ExtractMax = %ld\n", HeapExtractMax(A));
        }
        else if (strcmp(comando, "INCREASE") == 0) {
            int i;
            tipoChave k;
            scanf("%d %ld", &i, &k);
            HeapIncreaseKey(A, i, k);
        }
        else if (strcmp(comando, "INSERT") == 0) {
            tipoChave k;
            scanf("%ld", &k);
            MaxHeapInsert(A, k);
        }

        else if (strcmp(comando, "IMPRIMIR") == 0) {
        	printf ("Vetor Heap (n=%ld): ", A[0]);
        	for (int i = 1; i <= A[0]; i++) {
        		printf("%ld ", A[i]);
        	}
        	printf ("\n");
        }
        else if (strcmp(comando, "FIM") == 0) {
            free(A);
            A = NULL;
            break;
        } else {
            printf("ERRO INTERNO!!!\n");
            break;
        }
    }

    return 0;
}
