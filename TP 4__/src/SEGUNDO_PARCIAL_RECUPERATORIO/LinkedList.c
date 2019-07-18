#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList)); /**Creo un puntero del tipo linkedList y reservo memoria **/
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this; /** Valido el puntero, inicializo sus campos y lo retorno **/
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux; /** VALIDO EL PUNTERO A LA LISTA Y RETORNO SIZE QUE ES EQUIVALENTE A LA CANTIDAD DE ELEMENTOS **/
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int cantidadElementos = ll_len(this);
    if(this != NULL && nodeIndex > -1 && nodeIndex < cantidadElementos)
    {
        pNode = this->pFirstNode;  /**DECLARO UNA VARIABLE TIPO NODE, Y LA VOY IGUALANDO A SU SIGUIENTE
                                    HASTA POSICIONARME EN LA INDEX INGRESADA POR PARAMENTRO **/
        while(nodeIndex > 0)
        {
            pNode = pNode->pNextNode;
            nodeIndex--;
        }
    }
    return pNode;   /** RETORNO NODE EN LA POSICION INGRESADA POR PARAMETRO(nodeIndex)**/
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    /**DECLARO TRES VARIABLES DEL TIPO NODO, EN MEDIO DE PREV Y NEXT COLOCAREMOS EL NUEVO NODO **/
    Node* prev;
    Node* next;
    Node* nuevoNodo;

    if( this != NULL)
    {
        if(nodeIndex >= 0 && nodeIndex <= ll_len(this))
        {
            nuevoNodo = (Node*)malloc(sizeof(Node));
            if(nuevoNodo != NULL)
            {
                nuevoNodo->pElement = pElement;
                nuevoNodo->pNextNode = NULL;       /** RESERVO MEMORIA E INICIALIZO EL NUEVO ELEMENTO **/

                if(nodeIndex == 0)                /** SI INDEX ES IGUAL A CERO, SERIA COLOCAR EL NUEVO NODO EN EL PRIMER ELEMENTO**/
                {
                    nuevoNodo->pNextNode = this->pFirstNode;
                    this->pFirstNode = nuevoNodo;
                }
                else                              /**SINO MOVEMOS LOS NODOS LA CANTIDAD DE VECES QUE VALE INDEX,
                                                    IGUALANDO EL NODO ANTERIOR AL SIGUIENTE, Y EL SIGUIENTE A SU SIGUIENTE **/
                {
                    prev = this->pFirstNode;
                    next = prev->pNextNode;

                    while( nodeIndex > 1)
                    {
                        prev  = next;
                        next  = prev->pNextNode;
                        nodeIndex--;
                    }

                    prev->pNextNode = nuevoNodo; /** EL NODO SIGUIENTE AL ANTERIOR AHORA SERA EL NUEVO NODO ,
                                                  Y EL SIGUIENTE DEL NUEVO NODO SERA, EL QUE ANTES ERA EL SIGUIENTE**/
                    nuevoNodo->pNextNode = next;
                }
                this->size++;                    /** AL AÑADIRSE UN NUEVO NODO A LA LISTA, AUMENTAMOS EN 1 LA CANTIDAD DE ELEMENTOS**/
                returnAux = 0;
            }
        }
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node *nuevoNodo = (Node*)malloc(sizeof(Node));
    if(this != NULL && nuevoNodo != NULL && pElement != NULL)
    {
        nuevoNodo->pNextNode = NULL;       /**RESERVO MEMORIA E INICIALIZO EL NUEVO NODO **/
        nuevoNodo->pElement = pElement;
        if(this->pFirstNode == NULL)
        {
            nuevoNodo->pNextNode = this->pFirstNode; /** SI EL PRIMER ELEMENTO ES IGUAL A NULL, COLOCAMOS EL NUEVO NODO
                                                     COMO PRIMER ELEMENTO DE LA LISTA **/
            this->pFirstNode = nuevoNodo;
        }
        else
        {
            Node *auxNode = this->pFirstNode;       /**SINO CREAMOS UN NODO AUXILIAR, RECORREMOS LA LISTA IGUALANDO EL NODO
                                                     A SU SIGUIENTE, CUANDO ESTE SEA NULL, ESTAREMOS PARADOS EN EL ULTIMO ELEMENTO**/
            while(auxNode->pNextNode != NULL)
            {
                auxNode = auxNode->pNextNode;
            }
            auxNode->pNextNode = nuevoNodo;      /**ASIGNAMOS EL PUNTERO DEL NUEVO NODO AL SIGUIENTE DEL AUXILIAR PARA DEJARLO
                                                  EN LA ULTIMA POSICION **/
        }
        this->size++;                            /** AL AÑADIR UN ELEMENTO A LA LISTA, INCREMENTO LA CANTIDAD DE ELEMENTOS**/
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    if(this != NULL && index > -1 && index < ll_len(this))
    {
        Node *temp;
        temp = getNode(this,index); /**UTILIZO GETNODE PARA TRAER EL NODO DE LA INDEX INGRESADA POR PARAMETRO
                                    , LUEGO RETORNO EL ELEMENTO DE DICHO NODO **/
        if(temp != NULL)
        {
            returnAux = temp->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index > -1 && index < ll_len(this))
    {
        Node *auxNode = getNode(this,index); /**USO GETNODE PARA TRAER EL NODO QUE SE ENCUENTRA EN "INDEX"
                                             UNA VEZ ENCONTRADO, COLOCO EN SU ELEMENTO EL NUEVO ELEMENTO INGRESADO POR PARAMETRO**/
        if(auxNode != NULL)
        {
            auxNode->pElement = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int cantidad = ll_len(this);
    if(this != NULL && index < cantidad && index >= 0)
    {
      Node *auxNode = this->pFirstNode;
      Node *auxNode2;
      if(index == 0)
      {
          this->pFirstNode = auxNode->pNextNode; /**SI INDEX ES 0 EL ELEMENTO A BORRAR ES EL PRIMERO,TOMO COMO PRIMERO
                                                 EL SIGUIENTE, Y ELIMINO AL QUE ANTES ERA EL PRIMERO**/
          free(auxNode);

      }
       else
      {
          auxNode2 = getNode(this,index-1);          /**SINO USO GETNODE PARA TRAERME EL ELEMENTO A BORRAR Y SU ANTERIOR,
                                                     EL ANTERIOR LO ENLAZO AL SIGUIENTE DEL ELEMENTO A BORRAR,LUEGO LO ELIMINO**/
          auxNode = getNode(this,index);
          auxNode2->pNextNode = auxNode->pNextNode;
          free(auxNode);

      }
        this->size--;                           /**COMO REMOVIMOS UN ELEMENTO, DISMINUIMOS EN 1 LA CANTIDAD DE ELEMENTOS**/
        returnAux = 0;


    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        /**USO UN NODO AUXILIAR LLAMADO REMOVE, RECORRO LA LISTA ASIGNANDO A REMOVE EL PRIMER ELEMENTO DE LA LISTA,
        EL PRIMER ELEMENTO DE LA LISTA VA A SER EL SIGUIENTE DEL QUE VAMOS A REMOVER, LUEGO ELIMINAMOS REMOVE
        DEJANDO COMO PRIMERO EL QUE ANTES ERA EL SEGUNDO, CUANDO EL PRIMER ELEMENTO SEA NULL ES QUE YA RECORRIMOS LA LISTA**/
        Node *remove;
        while(this->pFirstNode != NULL)
        {
            remove = this->pFirstNode;
            this->pFirstNode = remove->pNextNode;
            free(remove);

        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        Node *remove;
        while(this->pFirstNode != NULL)
        {
            remove = this->pFirstNode;
            this->pFirstNode = remove->pNextNode;
            free(remove);

        }
        free(this);   /**HACEMOS LO MISMO QUE CLEAR, PERO ANTES DE SALIR TAMBIEN ELIMINAMOS LA LISTA**/
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int cantidadElementos;
    if(this != NULL)
    {
        cantidadElementos = this->size; /**UTILIZO LA CANTIDAD DE ELEMENTOS PARA RECORRER LA LISTA **/
        Node *temp;
        while(cantidadElementos > 0)    /**MIENTRAS LA CANTIDAD SEA MAYOR A 0 RECORRO LA LISTA PREGUNTANDO SI EL ELEMENTO
                                         DE DICHO INDEX ES IGUAL AL ELEMENTO QUE SE INGRESO POR PARAMETRO**/
        {
            temp = getNode(this,cantidadElementos-1); /**UTILIZO CON INDEX LA CANTIDAD DE ELEMENTOS -1, YA QUE EL ELEMENTO 1
                                                      ES LA POSICION 0 Y ASI SUCESIVAMENTE**/
            if(temp->pElement == pElement)
            {
                returnAux = cantidadElementos-1;
                break;
            }
            cantidadElementos--;        /**DECREMENTO EN 1 LA CANTIDAD DE ELEMENTOS PARA RECORRER TODA LA LISTA**/
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(this->pFirstNode == NULL)/**SI EL PRIMER ELEMENTO ES IGUAL A NULL, ES PORQUE LA LISTA ESTA VACIA Y LO INDICO CON 1**/
        {
            returnAux = 1;
        }
        else
            returnAux = 0;   /**SINO QUIERE DECIR QUE HAY AL MENOS UN ELEMENTO,POR LO TANTO LO INDICO CON UN 0**/
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if( this != NULL)
    {
        if(index >= 0 && index <= ll_len(this)) /**ESTA VEZ ES MENOR O IGUAL A LA CANTIDAD YA QUE EL ELEMENTO PUEDE SER INSERTADO
                                                EN LA INDEX IGUAL A LA CANTIDAD DE ELEMENTOS**/
        {
            if(addNode(this,index,pElement) != -1) /**USO LA FUNCION ADD NODE QUE AGREGA UN ELEMENTO EN LA INDEX INDICADA **/
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void *returnAux = NULL;

    if(this != NULL)
    {
      Node *remove = getNode(this,index); /**USO LA FUNCION GETNODE PARA TRAER EL ELEMENTO DE LA INDEX INDICADA**/
      if(remove != NULL)
      {
        returnAux = remove->pElement;
        ll_remove(this,index);
      }

    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(ll_indexOf(this,pElement) != -1)/**SI LA FUNCION INDEX OFF RETORNA DISTINTO DE -1 ES PORQUE EL ELEMENTO ESTA EN LA LISTA**/
        {
            returnAux = 1;
        }
        else
            returnAux = 0;  /** SI NO SE ENCUENTRA EN LA LISTA RETORNARA 0**/
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = 1;
    if(this != NULL && this2 != NULL)
    {
        Node *auxNode = this2->pFirstNode; /**RECORRO LA LISTA 2, CUANDO AUXNODE SEA NULL,LLEGAMOS AL FINAL DE LA LISTA**/
        while(auxNode != NULL)
        {
           if(ll_indexOf(this,auxNode->pElement) != -1)/**LE PASAMOS LA LISTA 1 Y EL ELEMENTO DE LA LISTA 2,
                                                       SI LA FUNCION RETORNA DISTINTO DE 0,ES QUE ESE ELEMENTO DE LISTA 2
                                                       SE ENCUENTRA EN LISTA 1**/
            {
            }
            else
                returnAux = 0;                        /**SINO EL ELEMENTO NO SE ENCUENTRA EN LA LISTA Y LA FUNCION SE VUELVE
                                                      FALSA, YA QUE NO TODOS LOS ELEMENTOS DE LISTA 2 ESTAN EN LISTA 1**/
            auxNode = auxNode->pNextNode;
        }

    }
    else
        returnAux = -1;                           /**SI HAY UN ERROR DE PARAMETROS, RETORNAMOS -1**/
    return returnAux;
}


/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i = from;
    if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to < ll_len(this))
    {
        LinkedList* auxList = ll_newLinkedList(); /**CREO UNA NUEVA LISTA, INICIALIZANDOLA CON LA FUNCION NEW LIST**/
        Node *auxNode = getNode(this,from);
        while(i <= to)                      /**ITERA HASTA LLEGAR AL FINAL INDICADO**/
        {
            ll_add(auxList,auxNode->pElement);
            auxNode = auxNode->pNextNode;
            i++;
        }
        cloneArray = auxList;
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
        LinkedList *auxArray = ll_newLinkedList();
        Node *auxNode = this->pFirstNode;   /**RECORRO LA LISTA,CUANDO AUXNODE SEA NULL, LLEGAMOS AL FINAL**/
        while(auxNode != NULL)
        {
            ll_add(auxArray,auxNode->pElement);/**MIENTRAS ITERAMOS VAMOS GUARDANDO LOS ELEMENTOS EN LA LISTA CLONE**/
            auxNode = auxNode->pNextNode;
        }
        cloneArray = auxArray;

    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pAux;
    int i;
    int j;

    if( this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(i=0; i< (ll_len(this)-1) ; i++)
        {
            for(j= i+1; j < ll_len(this); j++)
            {
                if(order == 1 && pFunc(ll_get(this,i), ll_get(this,j)) > 0)
                {
                    pAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAux);
                }
                else if(order == 0 && pFunc(ll_get(this,i), ll_get(this,j)) < 0)
                {
                    pAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAux);
                }
            }
        }

        returnAux = 0;
    }

    return returnAux;

}

int ll_print(LinkedList* this,void (*pFunc)(void*))
{
    int retorno = -1;
    int len;
    int i;

    if(this != NULL && pFunc != NULL)
    {
        len = ll_len(this);
        for(i=0;i<len;i++)
        {
            pFunc(ll_get(this,i));
        }
        retorno = 0;
    }
    return retorno;
}

int ll_map(LinkedList* this,void (*pFunc)(void*))
{
    int retorno = -1;
    int len;
    int i;

    if(this != NULL && pFunc != NULL)
    {
        len = ll_len(this);
        for(i=0;i<len;i++)
        {
            pFunc(ll_get(this,i));
        }
        retorno = 0;int ll_print(LinkedList* this,void (*pFunc)(void*));
int ll_map(LinkedList* this,void (*pFunc)(void*));
LinkedList* ll_filter(LinkedList* this,int (*fn)(void*));
    }
    return retorno;
}

LinkedList* ll_filter(LinkedList* this,int (*fn)(void*))
{
    LinkedList* newList = NULL;
    int len;
    int i;

    if(this != NULL && fn != NULL)
    {
        newList = ll_newLinkedList();
        len = ll_len(this);
        for(i=0;i<len;i++)
        {
           if(fn(ll_get(this,i)))
           {
               ll_add(newList,ll_get(this,i));
           }
        }
    }
    return newList;
}


