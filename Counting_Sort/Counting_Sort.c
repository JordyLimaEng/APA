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
  int * Vetor_contador = calloc(max, sizeof(int)); // Zeros out the array

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

  int test1[] = {2, 6, 4, 3, 2, 3, 4, 6, 3, 4, 3, 5, 2, 6};
  int Tam1 = 14;

  countingSort(test1, Tam1);

  int test2[] = {5, 6, 7, 8, 5};
  int Tam2 = 5;

  countingSort(test2, Tam2);

  int test3[] = {8, 1, 2, 3, 3, 4};
  int Tam3 = 6;

  countingSort(test3, Tam3);

  return 0;
}
