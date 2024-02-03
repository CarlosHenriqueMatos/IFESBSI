#define TAM 31//contante com valor 
#include <stdio.h>
#include <stdlib.h>

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

    printf("\nIndice gerado: %d\n",id);

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