#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "llamada.h"
#include "imput.h"

eLlamada* new_parametros(char* id,char* fecha,char* numero_cliente,char* id_problema,char* solucionado)
{
    eLlamada *nuevaLlamada = new_llamada();

    if(nuevaLlamada != NULL)
    {
        llamada_setId(nuevaLlamada,id);
        llamada_setFecha(nuevaLlamada,fecha);
        llamada_setNumeroCliente(nuevaLlamada,numero_cliente);
        llamada_setIdProblema(nuevaLlamada,id_problema);
        llamada_setSolucionado(nuevaLlamada,solucionado);
    }
    return nuevaLlamada;
}

eLlamada* new_llamada(void)
{
   eLlamada* nuevaLlamada = (eLlamada*)malloc(sizeof(eLlamada));
   return nuevaLlamada;
}

int llamada_setId(eLlamada* this,char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        strncpy(this->id,id,51);
        retorno = 0;
    }
    return retorno;
}

int llamada_setFecha(eLlamada* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL)
    {
        strncpy(this->fecha,fecha,20);
        retorno = 0;
    }
    return retorno;
}

int llamada_setIdProblema(eLlamada* this,char* id_problema)
{
    int retorno = -1;
    if(this != NULL && id_problema != NULL)
    {
        strncpy(this->id_problema,id_problema,20);
        retorno = 0;
    }
    return retorno;
}

int llamada_setNumeroCliente(eLlamada* this,char* numero_cliente)
{
    int retorno = -1;
    if(this != NULL && numero_cliente != NULL)
    {
        strncpy(this->numero_cliente,numero_cliente,20);
        retorno = 0;
    }
    return retorno;
}

int llamada_setSolucionado(eLlamada* this,char* solucionado)
{
    int retorno = -1;
    if(this != NULL && solucionado != NULL)
    {
        strncpy(this->solucionado,solucionado,20);
        retorno = 0;
    }
    return retorno;
}


char llamada_setTipo(char* dominio)
{
    char tipo = dominio[0];

    if(tipo < '0' || tipo > '9')
    {
        tipo = 'A';
    }
    else
    {
        tipo = 'M';
    }
    return tipo;
}

void print_llamada(LinkedList* list)
{
    int len = ll_len(list);
    int i;
    for(i=0;i<len;i++)
    {
        eLlamada* llamada = ll_get(list,i);
        imprimir(llamada);
    }
}

void imprimir(eLlamada* pElement)
{
    char problema_1[] = "No enciende PC";
    char problema_2[] = "No funciona mouse";
    char problema_3[] = "No funciona teclado";
    char problema_4[] = "No hay internet";
    char problema_5[] = "No funciona telefono";
    int opcion = atoi(pElement->id_problema);


    switch(opcion)
    {
    case 1:
        printf("\n%s %s %s %s %s",
            pElement->id,
            pElement->fecha,
            pElement->numero_cliente,
            problema_1,
            pElement->solucionado);
        break;
    case 2:
        printf("\n%s %s %s %s %s",
            pElement->id,
            pElement->fecha,
            pElement->numero_cliente,
            problema_2,
            pElement->solucionado);
        break;
    case 3:
        printf("\n%s %s %s %s %s",
            pElement->id,
            pElement->fecha,
            pElement->numero_cliente,
            problema_3,
            pElement->solucionado);
        break;
    case 4:
        printf("\n%s %s %s %s %s",
            pElement->id,
            pElement->fecha,
            pElement->numero_cliente,
            problema_4,
            pElement->solucionado);
        break;
    case 5:
        printf("\n%s %s %s %s %s",
            pElement->id,
            pElement->fecha,
            pElement->numero_cliente,
            problema_5,
            pElement->solucionado);
        break;
    }


}

int getProblema1(void* pElement)
{
    int retorno = 0;
    int compare =atoi(((eLlamada*)pElement)->id_problema);
    if(compare == 1 )
    {
        retorno = 1;
    }
    return retorno;

}

int getProblema2(void* pElement)
{
    int retorno = 0;
    int compare =atoi(((eLlamada*)pElement)->id_problema);
    if(compare == 2 )
    {
        retorno = 1;
    }
    return retorno;

}

int getProblema3(void* pElement)
{
    int retorno = 0;
    int compare =atoi(((eLlamada*)pElement)->id_problema);
    if(compare == 3 )
    {
        retorno = 1;
    }
    return retorno;

}

int getProblema4(void* pElement)
{
    int retorno = 0;
    int compare =atoi(((eLlamada*)pElement)->id_problema);
    if(compare == 4 )
    {
        retorno = 1;
    }
    return retorno;

}

int getProblema5(void* pElement)
{
    int retorno = 0;
    int compare =atoi(((eLlamada*)pElement)->id_problema);
    if(compare == 5 )
    {
        retorno = 1;
    }
    return retorno;

}

int menu_Principal(void)
{
    int retorno = -1;
    int opcion;
    printf("\n------------MENU PRINCIPAL-----------------");
    printf("\n1.Cargar archivo"
           "\n2.Imprimir llamadas"
           "\n3.Generar archivo de llamadas"
           "\n4.SALIR");
    if(!getInt("\nOpcion: ",1,4,&opcion))
    {
        if(isValidRange(1,4,opcion))
        {
            retorno = opcion;
        }
    }
    return retorno;
}

int menu_problema(void)
{
    int retorno = -1;
    int opcion;
    printf("\n------------MENU PRINCIPAL-----------------");
    printf("\n1.no enciende pc"
           "\n2.no funciona mouse"
           "\n3.no funciona teclado"
           "\n4.no hay internet"
           "\n5.no funciona telefono");
    if(!getInt("\nOpcion: ",1,5,&opcion))
    {
        if(isValidRange(1,5,opcion))
        {
            retorno = opcion;
        }
    }
    return retorno;
}

void parser_LoadFromText(LinkedList *list, char* path)
{
    FILE *pFile;
    char id[20];
    char fecha[51];
    char numero_cliente[20];
    char id_problema[20];
    char solucionado[20];

    int quantityRead;
    pFile = fopen(path,"r");
    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]",id,fecha,numero_cliente,id_problema,solucionado);
        while(!feof(pFile))
        {
            quantityRead = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]",id,fecha,numero_cliente,id_problema,solucionado);
            if(quantityRead == 0)
            {
                break;
            }
            eLlamada *nuevaLlamada = new_parametros(id,fecha,numero_cliente,id_problema,solucionado);
            if(ll_add(list,nuevaLlamada))
            {
                printf("\nError");
                continue;
            }
        }
        if(fclose(pFile))
        {
            printf("\nERROR AL CERRAR EL ARCHIVO");
        }
    }
    else
        printf("\nError al abrir el archivo");
}

void parser_SaveFromText(LinkedList *list, char* path)
{
    FILE *pFile;
    int len = ll_len(list);
    int i;
    int quantityWrite;
    pFile = fopen(path,"w");
    if(pFile != NULL)
    {
        fprintf(pFile,"ID_Llamada,Fecha,Numero_Cliente,ID_Problema,Solucionado\n");
        for(i=0;i<len;i++)
        {
            eLlamada* llamada = ll_get(list,i);
            quantityWrite = fprintf(pFile,"%s,%s,%s,%s,%s\n",
                                    llamada->id,llamada->fecha,
                                    llamada->numero_cliente,
                                    llamada->id_problema,
                                    llamada->solucionado);
            if(quantityWrite == 0)
            {
                break;
            }
        }
        if(fclose(pFile))
        {
            printf("\nERROR AL CERRAR EL ARCHIVO");
        }
    }
    else
        printf("\nError al abrir el archivo");
}
