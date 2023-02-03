#ifndef mEsparsa
#define mEsparsa

typedef struct Celula Cell;
typedef struct MatrizEsparsa Matriz;

void liberaMatriz(Matriz* matriz);
void printMatriz(Matriz* matriz);
void somaMatriz(Matriz* matriz1, Matriz* matriz2);

Matriz* criaMatriz(unsigned int dim);
Matriz* removeElemento(Matriz* matriz,unsigned int lin,unsigned int col);
Matriz* insereElemento(Matriz* matriz,unsigned int lin,unsigned int col,float valor);

#endif