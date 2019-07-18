typedef struct
{
    char id[20];
    char fecha[20];
    char numero_cliente[20];
    char id_problema[20];
    char solucionado[20];

}eLlamada;



/**
  *\brief crea una variable del tipo de dato eLlamada y carga todos los valores validados.
  *\return el puntero a la variable del tipo de dato eLlamada.
**/
eLlamada* new_parametros(char* id,char* fecha,char* numero_cliente,char* id_problema,char* solucionado);

 /**
   *\brief Crea una variable del tipo eLlamada y le asigna memoria dinamica:
   *\return El puntero a dicha variable.
**/
eLlamada* new_llamada(void);

/**
  *\brief Funciones SET, validan el dato y lo cargan en un campo de la estructura.
  *\param El elemento adonde se guardara el dato validado y el dato que debemos validar y guardar.
  *\return 0 si todo es correcto o -1 en caso de error.
**/
int llamada_setId(eLlamada* this,char* id);
int llamada_setFecha(eLlamada* this,char* fecha);
int llamada_setNumeroCliente(eLlamada* this,char* numero_cliente);
int llamada_setSolucionado(eLlamada* this,char* solucionado);
int llamada_setIdProblema(eLlamada* this,char* id_problema);

/**
  *\brief Imprime un menu en pantalla tomando una opcion por teclado
  *\return la opcion si es correcta o -1 si es incorrecta.
**/
int menu_Principal(void);
int menu_problema(void);
void imprimir(eLlamada* pElement);
void print_llamada(LinkedList* list);

/**
  *\brief dice si el item se debe guardar o no
  *\param el elemento a comparar
  *\return 1 si hay que guardarlo y 0 si no.
**/
int getProblema1(void* pElement);
int getProblema2(void* pElement);
int getProblema3(void* pElement);
int getProblema4(void* pElement);
int getProblema5(void* pElement);
void parser_LoadFromText(LinkedList *list, char* path);
void parser_SaveFromText(LinkedList *list, char* path);

