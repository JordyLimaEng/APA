/*ALUNO: JORDY ALLYSON DE SOUSA LIMA
  MATRICULA: 11426758*/

#include <stdio.h>
#include <stdlib.h>

void Insertion_Sort(int *vetor, int max){

    int i=0, j=0;

    FILE *ler;

	ler = fopen("Arquivo_a_ser_ordenado", "r");
    for(i=0; i<max; i++){
        fscanf(ler, "%d/n", &vetor[i]); //lê os valores do arquivo
		//printf("\t%d\n", vetor[i]);
    }


    ler = fopen("Arquivo_a_ser_ordenado.Ordenado.txt", "w");
/*************************************************************/
//Implementação do método de ordenação
/************************************************************/
int aux=0;

    for (i = 1; i < max; i++) {
            j = i;
            while (j > 0 && vetor[j - 1] > vetor[j]) {
                  aux = vetor[j];
                  vetor[j] = vetor[j - 1];
                  vetor[j - 1] = aux;
                  j--;
            }
}

for (i = 0; i < max; i++) {
    fprintf (ler,"%d \n",vetor[i]);
}
    fclose(ler);
}
/*************************************************************/
