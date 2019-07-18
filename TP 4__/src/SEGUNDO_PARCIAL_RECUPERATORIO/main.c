#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "llamada.h"
#include "imput.h"


int main()
{
    LinkedList *list = ll_newLinkedList();
    LinkedList* listaProblemaExpecifico;
    int opcion;
    int opcion2;
    do
    {
        switch(opcion = menu_Principal())
        {
        case 1:
            parser_LoadFromText(list,"datos.txt");
            break;
        case 2:
            if(ll_len(list))
            {
               print_llamada(list);
            }
            break;
        case 3:
            if(ll_len(list))
            {
                switch(opcion2 = menu_problema())
                {
                case 1:
                    listaProblemaExpecifico = ll_filter(list,getProblema1);
                    break;
                case 2:
                    listaProblemaExpecifico = ll_filter(list,getProblema2);
                    break;
                case 3:
                    listaProblemaExpecifico = ll_filter(list,getProblema3);
                    break;
                case 4:
                    listaProblemaExpecifico = ll_filter(list,getProblema4);
                    break;
                case 5:
                    listaProblemaExpecifico = ll_filter(list,getProblema5);
                    break;
                }
                parser_SaveFromText(listaProblemaExpecifico,"problemaExpecifico.txt");
            }
                break;
        }
    }while(opcion != 4);




    return 0;
}


