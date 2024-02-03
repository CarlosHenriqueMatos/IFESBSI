#include <stdio.h>
#include <stdlib.h>

/* O que é uma tabela hash?
é utuilizada para tornar o processo de busca mais eficiente, sem que se tenha muitas
inserções e deleções
fonte: https://www.youtube.com/watch?v=N4uQ6oq0VVc&ab_channel=Programeseufuturo
*/

#define TAM 31//contante com valor 

void initialize_table(int t[])
{
    int i;
    for(i=0; i<TAM; i++)
    {
        t[i] = 0;
    }
}

int hash_func(int chave)
{
    return chave % TAM;
}

void insertion(int t[],int value)
{
    int id = hash_func(value);
    while(t[id] != 0)
    {
        id = hash_func(id + 1);
    }
    t[id] = value;
}

int search(int t[], int key)
{
    int id = hash_func(key);
    while(t[id] != 0)
    {
        if (t[id] == key)
            return t[id];
        else
            id = hash_func(id + 1);

    }
    return 0;

    
}

void _print(int t[])
{
    int i;
    for(i=0; i < TAM; i++)
    {
        printf("%d = %d\n",i,t[i]);
    }
}

int main()
{
    int option = 1,value , return_var ,table[TAM];

    while(option != 0)
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            break;
        case 2:
            printf("\tQual valor deseja buscar? ");
            scanf("%d", &value);
            return_var = search(table,value);
            if(return_var != 0)
                printf("\tValor encontrado: %d\n", return_var);
            else
                printf("\tValor não encontado!\n");
            break;
        case 3:
            _print(table);
            break;
        default:
            break;
        }
    }
    

    return 0;
}