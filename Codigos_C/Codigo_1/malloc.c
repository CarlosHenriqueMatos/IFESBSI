#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int *x;/*ponteiro para um inteiro*/
    int i,tam, *vet;
    int vet_size;

/*Alocacao dinamica de matrizes
matriz -> int* -> 10 27 32
          int* -> 11 75 49
          int* -> 43 82 10
          int* -> 12 47 62
*/
    int **mat, j, quantidade_elementos;
    quantidade_elementos = 5;

    mat = malloc(quantidade_elementos * sizeof(int*));

    for (i = 0; i < 4; i++){
        mat[i] = malloc(quantidade_elementos * sizeof(int));
    }
    srand(time(NULL));
    /*Escrita*/
    for(i = 0; i < quantidade_elementos; i++){
        for(j = 0; j < quantidade_elementos; j++){
            mat[i][j] = rand()%100;
        }
    }

    /*Leitura*/
    for(i = 0; i < quantidade_elementos; i++){
        for(j = 0; j < quantidade_elementos; j++){
            if (j == 0){
                printf("| %2d |", *(*(mat +i) + j));
            }
            else{
                printf(" %2d |",*(*(mat +i) + j));
            }
        }
        printf("\n");
    }
    for(i = 0; i < 5; i++){
        free(mat[i]);
    }
/*Alocacao dinamica de vetores*/
    /*printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);*/
    tam = 5;
    srand(time(NULL));
    
    vet = malloc(tam * sizeof(int));
    if(vet){
        printf("Memoria alocada com sucesso!!\n");
        for(i = 0; i<tam ; i++){
            *(vet+i) = rand() % 100;
        }
        printf("Os valores do vetor são: ");
        for(i=0; i<tam; i++){
            printf("%d ", *(vet + i));
            
        }
        printf("\n");
        free(vet);
    }
    else{
        printf("Erro ao alocar memoria do vetor");
    }

/*Alocacao dinamica de memoria*/
    x = malloc(sizeof(int));

    if(x){
        printf("Memoria alocada com sucesso\n");
        printf("x: %d\n",*x);
        *x = 50;
        printf("x: %d\n", *x);
    }
    else{
        printf("Erro ao alocar memoria\n");
    }

    return 0;
}