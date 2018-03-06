/*ALUNO: JORDY ALLYSON DE SOUSA LIMA
  MATRICULA: 11426758*/

#include <stdio.h>
#include <stdlib.h>

void Selection_Sort(int *vetor){

    int i, j, temp, min, vezes=0, max=0;
	char c, letra = '\n';

    FILE *ler;
//------------------------------------------------------------
//Faz a contagem do número de linhas (ou números) do arquivo de entrada.
    ler = fopen("couting.txt", "r");

	while(fread(&c, sizeof(char),1, ler)){
	if(c == letra) {vezes++;}
	}
//	printf("o arquivo possui %d linhas", vezes+1);
//------------------------------------------------------------

	max = vezes+1; //Atribui a contagem de números 
                   //máximo a variável "max" da contagem
//------------------------------------------------------------
	ler = fopen("couting.txt", "r");
    for(i=0; i<max; i++){
        fscanf(ler, "%d/n", &vetor[i]); //lê os valores do arquivo
    }


    ler = fopen("coutingOrdenado.txt", "w");
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
