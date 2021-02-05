#include <stdio.h>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    int a = 1;
    int b = 2;

    printf("Antes: a = %d - b = %d\n", a, b);

    swap(&a, &b);

    printf("Depois: a = %d - b = %d\n", a, b);

    return 0;
}