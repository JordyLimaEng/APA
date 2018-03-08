#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"

int main()
{
    int vezes=0, max=0;
	char c, letra = '\n';

    FILE *ler;
//------------------------------------------------------------
//Faz a contagem do número de linhas (ou números) do arquivo de entrada.
    ler = fopen("num.1000.1.in", "r");
    while(fread(&c, sizeof(char),1, ler)){
	if(c == letra) {vezes++;}
	}

	fclose(ler);
	printf("o arquivo possui %d linhas\n", vezes+1);

	max = vezes+1;//Atribui a contagem de números
                   //máximo a variável "max" da contagem
//------------------------------------------------------------
    int vetor[max];

    Insertion_Sort(&vetor[0], max);

    printf("vetor foi ordenado.\n\n");
    return 0;
}

