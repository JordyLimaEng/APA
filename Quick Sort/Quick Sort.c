/*ALUNO: JORDY ALLYSON DE SOUSA LIMA
  MATRICULA: 11426758*/

#include<stdlib.h>
#include<stdio.h>

void troca(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int particao (int vetor[], int menor, int maior)
{
    int pivo = vetor[maior];    // pivô
    int i = (menor - 1);  // Indice do menor elemento

    for (int j = menor; j <= maior- 1; j++)
    {
        // Se o elemento atual é menor que
        // ou igual ao pivô
        if (vetor[j] <= pivo)
        {
            i++;    // Incremento do indice do menor elemento
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[maior]);
    return (i + 1);
}


void quickSort(int vetor[], int menor, int maior)
{
    if (menor < maior)
    {
        /* particaoi é o indice de particionamento, Vetor agora está
           na parte direita */
        int particaoi = particao(vetor, menor, maior);

        quickSort(vetor, menor, particaoi - 1);
        quickSort(vetor, particaoi + 1, maior);
    }
}

void Imprimir_Vetor(int A[], int tam)
{
    int i;
     FILE *ler;
     ler = fopen("Arquivo_a_ser_ordenado.Ordenado.txt", "w");
	for (i = 0; i < tam; i++) {
    fprintf (ler,"%d \n",A[i]);
    }
    fclose(ler);
}


int main()
{
	int vezes=0, max=0;
	char c, letra = '\n';

	FILE *ler;
//------------------------------------------------------------
//Faz a contagem do número de linhas (ou números) do arquivo de entrada.
    ler = fopen("Arquivo_a_ser_ordenado", "r");
    while(fread(&c, sizeof(char),1, ler)){
	if(c == letra) {vezes++;}
    }
	fclose(ler);

	printf("o arquivo possui %d linhas\n", vezes+1);

	max = vezes+1;//Atribui a contagem de números
                   //máximo a variável "max" da contagem
//------------------------------------------------------------

    int vetor[max];

	ler = fopen("Arquivo_a_ser_ordenado", "r");
    for(int i = 0; i<=max ;i++){
        fscanf(ler, "%d/n", &vetor[i]);
    }
	fclose(ler);

	quickSort(&vetor[0], 0, max - 1);

	printf("\nVetor foi ordenado.\n");
	Imprimir_Vetor(&vetor[0], max);
	return 0;
}
