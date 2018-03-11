/*ALUNO: JORDY ALLYSON DE SOUSA LIMA
  MATRICULA: 11426758*/

#include<stdlib.h>
#include<stdio.h>

void merge(int vetor[], int e, int m, int d)
{
	int i, j, k;
	int n1 = m - e + 1;
	int n2 = d - m;


	int E[n1], D[n2]; //Vetores temporários

    //Copia os valores para os vetores temporarios
	for (i = 0; i < n1; i++)
		E[i] = vetor[e + i];
	for (j = 0; j < n2; j++)
		D[j] = vetor[m + 1+ j];

    //Faz o merge dos vetores de volta a Vetor[Esq...Dir]
	i = 0;
	j = 0;
	k = e;
	while (i < n1 && j < n2)
	{
		if (E[i] <= D[j])
		{
			vetor[k] = E[i];
			i++;
		}
		else
		{
			vetor[k] = D[j];
			j++;
		}
		k++;
	}

    //copia os elementos restantes do Vetor da esq, se há algu.
	while (i < n1)
	{
		vetor[k] = E[i];
		i++;
		k++;
	}
    //copia os elementos restantes do Vetor da dir, se há algu.
	while (j < n2)
	{
		vetor[k] = D[j];
		j++;
		k++;
	}
}

//E e L são os indices da esquerda e direita respectiv.
// do vetor a ser ordenado.
void mergeSort(int vetor[], int E, int D)
{
	if (E < D)
	{

		int M = E+(D-E)/2; // mesmo que dividir o total por 2
                           // mas, evita overflow em grandes vetores

        //ordena os dois primeiros lados...
		mergeSort(vetor, E, M);
		mergeSort(vetor, M+1, D);

		merge(vetor, E, M, D);
	}
}

void Imprimir_Vetor(int A[], int size)
{
    int i;
     FILE *ler;
     ler = fopen("Arquivo_a_ser_ordenado.Ordenado.txt", "w");
	for (i = 0; i < size; i++) {
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

	mergeSort(&vetor[0], 0, max - 1);

	printf("\nVetor foi ordenado.\n");
	Imprimir_Vetor(&vetor[0], max);
	return 0;
}
