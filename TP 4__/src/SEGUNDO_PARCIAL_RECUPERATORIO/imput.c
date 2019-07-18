#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imput.h"
#define FALSE 0
#define TRUE 1

int getString(char* msg,int minimo,int maximo,char *resultado)
{
    int retorno = -1;
    char buffer[4096];

    printf(msg);
    if(minimo<maximo && resultado != NULL)
        {
          fgets(buffer,sizeof(buffer),stdin);
          buffer[strlen(buffer)-1] = '\0';
          if(strlen(buffer) >= minimo && strlen(buffer) < maximo)
          {
              strncpy(resultado,buffer,maximo);
              retorno = 0;
          }

        }
        return retorno;
}

int isValidName(char str[])
{
    int retorno = TRUE;
    int i=0;

    while(str[i] != '\0')
    {
        if(str[i] != ' ' &&
          (str[i] < 'a' || str[i] > 'z') &&
          (str[i] < 'A' || str[i] > 'Z'))
        {
            retorno = FALSE;
        }
        i++;
    }
    return retorno;

}


int isValidNumber(char strNumber[])
{
    int retorno = TRUE;
    int i = 0;
    while(strNumber[i] != '\0')
    {
        if(strNumber[i] < '0' || strNumber[i] > '9')
        {
            retorno = FALSE;
        }
        i++;
    }
    return retorno;
}


int isValidRange(int desde,int hasta,int numero)
{
    if(numero >= desde && numero <= hasta)
    {
        return TRUE;
    }
    return FALSE;

}

int isValidDni(char str[])
{
    int retorno = FALSE;
    if(!(str[7] == '\0' || str[7] == NULL))
    {
        retorno = TRUE;
    }
    return retorno;
}

int getInt(char* msg,int minCaracter ,int maxCaracter,int *result)
{
    int retorno = -1;
    char buffer[4096];

    if(!getString(msg,minCaracter,maxCaracter,buffer))
    {
        if(isValidNumber(buffer))
        {
            *result = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}
