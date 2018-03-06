#include <stdio.h>
#include <stdlib.h>
#include "selection_sort.h"

int main()
{
    int vetor[101];

    Selection_Sort(&vetor[0]);

    printf("vetor foi ordenado.\n\n");
    return 0;
}

