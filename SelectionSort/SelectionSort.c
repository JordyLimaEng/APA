#include <stdio.h>
#include <stdlib.h>

void Arquivo_Crescente(int *vetor);



int main()
{
    int vetor[102];

    Arquivo_Crescente(&vetor[0]);

    system("Pause");
    printf("vetor foi ordenado.\n\n");
    return 0;
}

Arquivo_Crescente(int *vetor){

    int i, j, temp;

    FILE *ler;

    ler = fopen("Arquivo.txt", "r");

    for(i=0; i<101; i++){
        fscanf(ler, "%d/n", &vetor[i]); //ler os valores do arquivo
    }

    ler = fopen("ordemC.txt", "w");

    for(i=0; i<101; i++){
        for(j=i+1; j<101; j++){

            if(vetor[i]>vetor[j]){
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }

        }
    fprintf(ler, "%d\n", vetor[i]);
    }
    fclose(ler);

}
