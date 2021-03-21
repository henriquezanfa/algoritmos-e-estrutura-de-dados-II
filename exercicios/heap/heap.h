// ATENCAO: NAO ALTERAR ESTE ARQUIVO !!!
// ATENCAO: NAO ALTERAR ESTE ARQUIVO !!!
// ATENCAO: NAO ALTERAR ESTE ARQUIVO !!!

#ifndef HEAP_H
#define HEAP_H

#define tipoChave long int

#include "internal.h"

void      MaxHeapify     (tipoChave A[], int i);
void      BuildMaxHeap   (tipoChave A[]);
void      HeapSort       (tipoChave A[]);
tipoChave HeapMaximum    (tipoChave A[]);
tipoChave HeapExtractMax (tipoChave A[]);
void      HeapIncreaseKey(tipoChave A[], int  i, tipoChave key);
void      MaxHeapInsert  (tipoChave A[], tipoChave key);

#endif
