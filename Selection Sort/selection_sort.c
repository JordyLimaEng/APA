/*ALUNO: JORDY ALLYSON DE SOUSA LIMA
  MATRICULA: 11426758*/

#include <stdio.h>
#include <stdlib.h>

void Selection_Sort(int *vetor, int max){

 int i=0, j=0, min=0, temp=0;

    FILE *ler;

	ler = fopen("Arquivo_a_ser_ordenado", "r");
    for(i=0; i<max; i++){
        fscanf(ler, "%d/n", &vetor[i]); //lê os valores do arquivo
		//printf("\t%d\n", vetor[i]);
    }


    ler = fopen("Arquivo_a_ser_ordenado.Ordenado.txt", "w");
//*************************************************************
//Implementação do método de ordenação

    for(i=0; i<max; i++){
        min = i;

        for(j=i+1; j<max+1; j++){
        if (vetor[j]<vetor[min]){ min = j;}
            }

        if(i != min){
                temp = vetor[i];
                vetor[i] = vetor[min];
                vetor[min] = temp;
            }
//*************************************************************

    fprintf(ler, "%d\n", vetor[i]);
    }
    fclose(ler);
//-------------------------------------------------------------
}
