#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
/* O que é uma tabela hash?
é utuilizada para tornar o processo de busca mais eficiente, sem que se tenha muitas
inserções e deleções
fonte: https://www.youtube.com/watch?v=N4uQ6oq0VVc&ab_channel=Programeseufuturo
*/



int main()
{
    int option = 1, value , return_var ,table[TAM];
    initialize_table(table);
    while(option != 0)
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\tQual valor deseja inserir? ");
            scanf("%d", &value);
            insertion(table, value);
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