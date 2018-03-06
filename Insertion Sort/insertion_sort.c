#include <stdio.h>
#include <stdlib.h>

void Insertion_Sort(int *vetor){

    int i=0, j=0, temp=0, vezes=0, max=0;
	char c, letra = '\n';

    FILE *ler;
//------------------------------------------------------------
//Faz a contagem do número de linhas (ou números) do arquivo de entrada.
    ler = fopen("couting.txt", "r");

	while(fread(&c, sizeof(char),1, ler)){
	if(c == letra) {vezes++;}
	}
	//printf("o arquivo possui %d linhas", vezes+1);

//------------------------------------------------------------

	max = vezes+1; //Atribui a contagem de números 
                   //máximo a variável "max" da contagem
//------------------------------------------------------------
	ler = fopen("couting.txt", "r");
    for(i=0; i<max; i++){
        fscanf(ler, "%d/n", &vetor[i]); //lê os valores do arquivo
		//printf("\t%d\n", vetor[i]);
    }


    ler = fopen("coutingOrdenado.txt", "w");
/*************************************************************/
//Implementação do método de ordenação
/************************************************************/
int x=0, y=0, aux=0;    

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
