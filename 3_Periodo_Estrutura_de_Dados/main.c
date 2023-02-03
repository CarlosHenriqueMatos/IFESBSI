#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mEsparsa.h"

int main(int argc, char *argv[])
{
	unsigned int dimarq1, dimarq2, lin, col; 
	float valor;

	FILE* arq1 = fopen(argv[1], "rt");
	FILE* arq2 = fopen(argv[2], "rt");

	fscanf(arq1, "%u" , &dimarq1);
	fscanf(arq2, "%u" , &dimarq2);

	Matriz* matriz1 = criaMatriz(dimarq1);
	Matriz* matriz2 = criaMatriz(dimarq2);

	while((fscanf(arq1, "%u;%u;%f" , &lin, &col, &valor)) != EOF)
	{
		matriz1 = insereElemento(matriz1, lin, col,valor);
	}
	fclose(arq1);

	while((fscanf(arq2, "%u;%u;%f" , &lin, &col, &valor)) != EOF)
	{
		matriz2 = insereElemento(matriz2, lin, col,valor);
	}
	fclose(arq2);

	somaMatriz(matriz1, matriz2);
	liberaMatriz(matriz1);
	liberaMatriz(matriz2);

	return 0;
}

