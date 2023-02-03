#include <stdio.h>
#include <stdlib.h>
#include "mEsparsa.h"

struct Celula
{
	unsigned int lin;
	unsigned int col;
	float valor;
	struct Celula* proxLin;
	struct Celula* proxCol;

};

struct MatrizEsparsa
{
	unsigned int dimensao;
	struct Celula** celLinha;
	struct Celula** celColuna;
	
};

Matriz* criaMatriz(unsigned int dim)
{
	Matriz* matriz = (Matriz*) malloc(sizeof(Matriz));
	matriz->dimensao = dim;
	matriz->celLinha = (Cell**) malloc(dim * sizeof(Cell));
	matriz->celColuna = (Cell**) malloc(dim * sizeof(Cell));

	for(int i = 0; i < dim; i++)
	{
		matriz->celLinha[i] = NULL;
		matriz->celColuna[i] = NULL;
	}
	return matriz;
}

Cell* criaCelula(float valor,unsigned int lin,unsigned int col)
{
	Cell* nova = (Cell*) malloc(sizeof(Cell));
	nova->lin = lin;
	nova->col = col;
	nova->valor = valor;
	nova->proxLin = NULL;
	nova->proxCol = NULL;

	return nova;
}


void liberaCelula(Cell* celula)
{	
	free(celula);
}

Matriz* insereNovaCelula(Matriz* matriz, float valor,unsigned int lin,unsigned int col)
{
	lin--;
	col--;

	Cell* novaCelula = criaCelula(valor, lin, col);
	if(matriz->celLinha[lin] == NULL)
	{
		matriz->celLinha[lin] = novaCelula;
	}

	else
	{
		Cell* celulaAtual = matriz->celLinha[lin];
		Cell* celulaTopo = celulaAtual;
		Cell* celulaEsquerda = celulaAtual;

		while(celulaAtual->proxLin != NULL && celulaAtual->col < col)
		{
			celulaEsquerda = celulaAtual;
			celulaAtual = celulaAtual->proxLin;
		}


		if(celulaAtual->col < col)
		{
			celulaAtual->proxLin = novaCelula;
		}

		
		else if(celulaAtual->col > col)
		{
			if(celulaAtual != celulaEsquerda)
			{
				celulaEsquerda->proxLin = novaCelula;
				novaCelula->proxLin = celulaAtual;
			}

			else
			{
				novaCelula->proxLin = celulaAtual;
			}
		}

		if(novaCelula->col < celulaTopo->col){
			matriz->celLinha[lin] = novaCelula;
		}
		
	}
	if(matriz->celColuna[col] == NULL){
		matriz->celColuna[col] = novaCelula;
	}

	else
	{
		Cell* celulaTopo = matriz->celColuna[col];
		Cell* celulaAtual = celulaTopo;
		Cell* celulaCima = celulaTopo;

		while(celulaAtual->proxCol != NULL && celulaAtual->lin < lin)
		{
			celulaCima = celulaAtual;
			celulaAtual = celulaAtual->proxCol;
		}

		if(celulaAtual->lin < lin){
			celulaAtual->proxCol = novaCelula;
		}

		else if(celulaAtual->lin > lin)
		{
			if(celulaAtual != celulaCima){
				celulaCima->proxCol = novaCelula;
				novaCelula->proxCol = celulaAtual;
			}else{
				novaCelula->proxLin = celulaAtual;
			}
		}

		if(novaCelula->lin < celulaTopo->lin){
			matriz->celColuna[col] = novaCelula;
		}

	}

	return matriz;

}

int celulaExiste(Matriz* matriz,unsigned int lin,unsigned int col)
{
	lin--;
	col--;

	unsigned int i = 0;
	Cell* celulaAtual = matriz->celLinha[lin];
	while(celulaAtual != NULL)
	{
		if(celulaAtual->col == col){
			i = 1;
			break;
		}else{
			celulaAtual = celulaAtual->proxLin;
		}
	}
	return  i;
}

Matriz* insereElemento(Matriz* matriz,unsigned int lin,unsigned int col,float valor)
{

	if(valor == 0){
		matriz = removeElemento(matriz, lin, col);
		return matriz;
	}

	unsigned int existe = celulaExiste(matriz, lin, col);
	if(existe == 1){
		lin--;
		col--;

		Cell* celulaAtual = matriz->celLinha[lin];
		while(celulaAtual->col != col)
		{
			celulaAtual = celulaAtual->proxLin;
		}
		celulaAtual->valor = valor;
		return matriz;
	}


	matriz = insereNovaCelula(matriz, valor, lin, col);
	return matriz;

}


void printMatriz(Matriz* matriz)
{
	Cell* cellAtual;
	unsigned int lin, col;
	float valor;

	for(int i = 0; i < matriz->dimensao; i++)
	{
		cellAtual = matriz->celColuna[i];
		while(cellAtual != NULL)
		{
			lin = cellAtual->lin;
			col = cellAtual->col;
			valor = cellAtual->valor;

			printf("%d;%d;%.2f",lin+1, col+1, valor);
			cellAtual = cellAtual->proxCol;
			printf("\n");
		}
		
	}
}

Matriz* removeElemento(Matriz* matriz,unsigned int lin,unsigned int col)
{
	
	lin--;
	col--;

	
	if(matriz->celLinha[lin] == NULL){
		return matriz;
	}
		

	if(matriz->celColuna[col] == NULL){
		return matriz;
	}
		


	
	Cell* cellTopoLinha = matriz->celLinha[lin];
	Cell* cellTopoColuna = matriz->celColuna[col];

	Cell* cellLinha = cellTopoLinha;
	Cell* cellEsquerdaLinha = cellTopoLinha;

	Cell* cellColuna = cellTopoColuna;
	Cell* cellCimaColuna = cellTopoColuna;

	
	while(cellLinha->col != col)
	{
		cellEsquerdaLinha = cellLinha;
		cellLinha = cellLinha->proxLin;

		if(cellLinha == NULL){
			return matriz;
		}
			

		if(cellLinha->col > col){
			return matriz;
		}
			
	}

	while(cellColuna->lin != lin)
	{
		cellCimaColuna = cellColuna;
		cellColuna = cellColuna->proxCol;
	}

	
	if(cellLinha == cellTopoLinha){
		cellTopoLinha = cellLinha->proxLin;
		matriz->celLinha[lin] = cellTopoLinha;

	}else{

		cellEsquerdaLinha->proxLin = cellLinha->proxLin;
	}

	
	if(cellColuna == cellTopoColuna){

		cellTopoColuna = cellColuna->proxCol;
		matriz->celColuna[col] = cellTopoColuna;
	}
	else{
		
		cellCimaColuna->proxCol = cellColuna->proxCol;
	}

	
	liberaCelula(cellLinha);

	return matriz;

}

void liberaMatriz(Matriz* matriz)/*libera as matrizes*/
{
	Cell* cellDireita;
	Cell* cellEsquerda;
	for(int i = 0; i < matriz->dimensao; i++)
	{
		cellEsquerda = matriz->celLinha[i];
		while(cellEsquerda!= NULL)
		{
			cellDireita = cellEsquerda->proxLin;
			liberaCelula(cellEsquerda);
			cellEsquerda = cellDireita;
		}
	}
	liberaCelula(cellDireita);
}

void somaMatriz(Matriz* matriz1, Matriz* matriz2)/*efetua a operacao de soma com as matrizes*/
{
	unsigned int lin, col, dim;
	float valor;
	Cell* celulaAtualM1;
	Cell* celulaAtualM2;

	dim = matriz1->dimensao;
	printf("%d\n", dim);
	for(int i = 0; i < matriz1->dimensao; i++)
	{
		celulaAtualM1 = matriz1->celLinha[i];
		celulaAtualM2 = matriz2->celLinha[i];

		while(celulaAtualM1 != NULL || celulaAtualM2 != NULL)
		{
			if(celulaAtualM1 != NULL && celulaAtualM2 != NULL)
			{
				
				if(celulaAtualM1->col == celulaAtualM2->col)
				{
					valor = celulaAtualM1->valor + celulaAtualM2->valor;
					if(valor != 0)
					{
						lin = celulaAtualM1->lin;
						col = celulaAtualM1->col;
						printf("%d;%d;%.1f ", lin+1,col+1,valor);
					}
					celulaAtualM1 = celulaAtualM1->proxLin;
					celulaAtualM2 = celulaAtualM2->proxLin;
				}
				
				else if(celulaAtualM1->col < celulaAtualM2->col)
				{
					lin = celulaAtualM1->lin;
					col = celulaAtualM1->col;
					valor = celulaAtualM1->valor;
					printf("%d;%d;%.1f ", lin+1,col+1,valor);
					celulaAtualM1 = celulaAtualM1->proxLin;
				}

				
				else
				{
					lin = celulaAtualM2->lin;
					col = celulaAtualM2->col;
					valor = celulaAtualM2->valor;
					printf("%d;%d;%.1f ", lin+1,col+1,valor);
					celulaAtualM2 = celulaAtualM2->proxLin;
				}
				
			}

			
			else if(celulaAtualM1 != NULL)
			{
				lin = celulaAtualM1->lin;
				col = celulaAtualM1->col;
				valor = celulaAtualM1->valor;
				printf("%d;%d;%.1f ", lin+1,col+1,valor);
				celulaAtualM1 = celulaAtualM1->proxLin;
			}

			
			else
			{
				lin = celulaAtualM2->lin;
				col = celulaAtualM2->col;
				valor = celulaAtualM2->valor;
				printf("%d;%d;%.1f ", lin+1,col+1,valor);
				celulaAtualM2 = celulaAtualM2->proxLin;
			}
			printf("\n");
		}
	}
	
}