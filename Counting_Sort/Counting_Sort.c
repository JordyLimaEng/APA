/*ALUNO: JORDY ALLYSON DE SOUSA LIMA
  MATRICULA: 11426758*/
#include <stdio.h>
#include <stdlib.h>

void Imprime_Vetor(int * Vetor, int Tam){

  int atual;
  for(atual = 0; atual < Tam; atual++){
    printf("%d, ", Vetor[atual]);
  }
  printf("\n");
}

int Maior(int * Vetor, int Tam){

  int atual = 0;
  int max = 0;

  for(atual = 0; atual < Tam; atual++){
    if(Vetor[atual] > max){ max = Vetor[atual]; }
  }

  return max;
}

void countingSort(int * Vetor, int Tam){

  int atual = 0;
  int max = Maior(Vetor, Tam);
  int * Vetor_contador = calloc(max, sizeof(int));

  for(atual = 0; atual < Tam; atual ++){
    Vetor_contador[Vetor[atual]]++;
  }

  int num = 0;
  atual = 0;

  while(atual <= Tam){
    while(Vetor_contador[num] > 0){
      Vetor[atual] = num;
      Vetor_contador[num]--;
      atual++;
      if(atual > Tam){ break; }
    }
    num++;
  }
  Imprime_Vetor(Vetor, Tam);
}

int main(){

  int teste1[] = {2, 6, 4, 3, 2, 3, 4, 6, 3, 4, 3, 5, 2, 6};
  int Tam1 = 14;

  countingSort(teste1, Tam1);

  int teste2[] = {5, 6, 7, 8, 5};
  int Tam2 = 5;

  countingSort(teste2, Tam2);

  int teste3[] = {8, 1, 2, 3, 3, 4};
  int Tam3 = 6;

  countingSort(teste3, Tam3);

  return 0;
}
