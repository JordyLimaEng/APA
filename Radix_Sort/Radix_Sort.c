/*ALUNO: JORDY ALLYSON DE SOUSA LIMA
  MATRICULA: 11426758*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ELEMENTOS 101
#define RANGE 10000


int V_Max(int a[], int NUM_Vetor){
   int i, max= a[0];
   for (i=0; i<NUM_Vetor; i++)
   {
  if (a[i]>max)
  {
     max=a[i];
  }
   }
   return(max);
}


void radixSort(int v[], int NUM_Vetor) {
    int i;
    int *v_aux;
    int maior = V_Max(v,NUM_Vetor);
    int exp = 1;

    v_aux = (int *)calloc(NUM_Vetor, sizeof(int));

    while (maior/exp > 0) {
        int bucket[RANGE] = { 0 };
      for (i = 0; i < NUM_Vetor; i++)
          bucket[(v[i] / exp) % 10]++;
      for (i = 1; i < 10; i++)
          bucket[i] += bucket[i - 1];
      for (i = NUM_Vetor - 1; i >= 0; i--)
          v_aux[--bucket[(v[i] / exp) % 10]] = v[i];
      for (i = 0; i < NUM_Vetor; i++)
          v[i] = v_aux[i];
      exp *= 10;
    }


}

int main(){
  int x;
  int vetor[ELEMENTOS];
  FILE *arq;
  int range;

  arq = fopen( "couting.txt", "r" );

  int i = 0;
  while (!feof(arq))
    {
      fscanf( arq, "%d", &x );
      vetor[i] = x;
      i++;
    }
      fclose(arq);

      radixSort(vetor,ELEMENTOS);

      for(i = 0; i < ELEMENTOS;i++){
        printf("%d\n", vetor[i]);

      }


}
