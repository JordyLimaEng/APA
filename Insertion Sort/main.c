#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"

int main()
{
    int vetor[101];

    Insertion_Sort(&vetor[0]);

    printf("vetor foi ordenado.\n\n");
    return 0;
}

