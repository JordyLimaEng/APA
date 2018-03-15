/*ALUNO: JORDY ALLYSON DE SOUSA LIMA
  MATRICULA: 11426758*/

#include<stdlib.h>
#include<stdio.h>

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

void troca(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int vetor[], int max, int i)
{
    int maior = i;  // Inicia com maior como a raiz
    int esq = 2*i + 1;  // Esquerda = 2*i + 1
    int dir = 2*i + 2;  // Direita  = 2*i + 2

    // Se o filho da esquerda for maior do que a raiz
    if (esq < max && vetor[esq] > vetor[maior])
        maior = esq;

    // Se o filho da direita for maior do que a raiz
    if (dir < max && vetor[dir] > vetor[maior])
        maior = dir;

    // Se o maior n�o � a raiz
    if (maior != i)
    {
        troca(&vetor[i], &vetor[maior]);

    heapify(vetor, max, maior);
    }
}


void heapSort(int vetor[], int max)
{
    // Constr�i a �rvore e chama recursivamente
    for (int i = max / 2 - 1; i >= 0; i--)
        heapify(vetor, max, i);

    // Tira elemento por elemento da �rvore e chama recursivamente
    for (int i=max-1; i>=0; i--)
    {
        // Raiz atual vai para o final
        troca(&vetor[0], &vetor[i]);

        // chamada recursiva para reduzir a �rvore
        heapify(vetor, i, 0);
    }
}

int main()
{
	int vezes=0, max=0;
	char c, letra = '\n';

	FILE *ler;
//------------------------------------------------------------
//Faz a contagem do n�mero de linhas (ou n�meros) do arquivo de entrada.
    ler = fopen("Arquivo_a_ser_ordenado", "r");
    while(fread(&c, sizeof(char),1, ler)){
	if(c == letra) {vezes++;}
    }
	fclose(ler);

	printf("o arquivo possui %d linhas\n", vezes+1);

	max = vezes+1;//Atribui a contagem de n�meros
                   //m�ximo a vari�vel "max" da contagem
//------------------------------------------------------------

    int vetor[max];

	ler = fopen("Arquivo_a_ser_ordenado", "r");
    for(int i = 0; i<=max ;i++){
        fscanf(ler, "%d/n", &vetor[i]);
    }
	fclose(ler);

	heapSort(&vetor[0],max);

	printf("\nVetor foi ordenado.\n");
	Imprimir_Vetor(&vetor[0], max);
	return 0;
}
