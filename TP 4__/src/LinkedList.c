#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


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
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
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

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    // la lista no puede ser nula, el índice no puede ser negativo ni mayor al tamaño de la lista
    {
         pNode = this->pFirstNode; // asigno la dirección de memoria del nodo cero

         for(i=0;i<nodeIndex;i++) // recorro hasta el índice pasado por parámetro -1
         {
             pNode = pNode->pNextNode; // devuelve la dirección de memoria del índice pasado por parámetro
                                        // que está guardado en la variable pNextNode del nodo anterior
         }
    }

    return pNode;
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

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) // "=" para poder agregarlo al último
    {
        Node* pNodeAux = NULL; // para guardar pNextNode antes de hacer el swap
        Node* pNewNode;
        Node* getNodeR; // para guardar el retorno de la función getNode

        // crear un nodo, asignarle pElement (pasado por parámetro) y NULL/puntero en pNextNode
        // al último nodo asignarle el puntero al nodo nuevo

        pNewNode = (Node*)malloc(sizeof(Node)); // creo el nodo nuevo

        if(pNewNode != NULL) // valido que el nodo nuevo no sea null
        {
            pNewNode->pElement = pElement; // le cargo el elemento al nodo nuevo
            pNewNode->pNextNode = NULL; // capaz no hace falta, pero le asigno NULL de entrada
        }

        if(nodeIndex == 0)
        // el usuario quiere agregar el nodo nuevo en la posición cero
        {
            pNodeAux = this->pFirstNode; // me guardo la dirección de memoria del actual nodo cero

            this->pFirstNode = pNewNode; // asigno la dirección de memoria del nodo nuevo como nodo cero

            pNewNode->pNextNode = pNodeAux; // hago que el nodo nuevo (que ahora es el cero) apunte al ex-nodo-cero

            // incrementar el size
            this->size++;

            returnAux = 0;
        }
        else
        {
            // llamo a getNode y guardo en una variable auxiliar lo que tiene en pNextNode
            // después de guardar eso, asigno en pNextNode la dirección de memoria de la variable nueva

            getNodeR = getNode(this, nodeIndex-1); // voy a buscar el pNextNode del nodo ANTERIOR al que quiero posicionar el nuevo

            if (getNodeR != NULL)
                // getNode me devuelve la dirección de memoria del índice que le pasé -1
            {
                pNodeAux = getNodeR;

                getNodeR->pNextNode = pNewNode; // hago que el nodo ANTERIOR al que quiero apunte al nodo nuevo

                pNewNode->pNextNode = pNodeAux; // hago que el nodo nuevo apunte

                this->size++;

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

    if(this != NULL)
    {
        addNode(this, ll_len(this), pElement);
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
    Node* nodeAux; // para guardar el nodo solicitado

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        nodeAux = getNode(this, index);

        if(nodeAux != NULL)
        {
            returnAux = nodeAux->pElement;
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
int ll_set(LinkedList* this, int index,void* pElement) // get + cambiar elemento
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        if(!addNode(this, index, pElement))
        // le paso los paràmetros a addNote y que haga todo, solo chequeo que esté ok
        {
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
int ll_remove(LinkedList* this,int index) // get
{
    int returnAux = -1;
    Node* nodeRemoved;
    Node* nodePrev;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        if(index==0)
        {
            nodeRemoved = this->pFirstNode; // guardo el puntero al nodo cero actual

            this->pFirstNode = nodeRemoved->pNextNode; // el pNextNode del nodo cero paasa a ser el firstNode

            free(nodeRemoved);

            // incrementar el size
            this->size--;

            returnAux = 0;
        }
        else
        {
           // hacerle get el nodo a eliminar y al anterior
            nodeRemoved = getNode(this, index);

            nodePrev = getNode(this, index - 1);

            if(nodeRemoved != NULL && nodePrev != NULL)
            {
                // al nodo anterior le seteo en pNextNode el pNextNode que tiene el nodo a ser borrado
                nodePrev->pNextNode = nodeRemoved->pNextNode;

                // hacerle free al nodo a eliminar
                free(nodeRemoved);

                this->size--;

                returnAux = 0;
            }
        }

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
int ll_clear(LinkedList* this) // borra todos los nodos
{
    int returnAux = -1;

    if(this != NULL)
    {
        while(this->size != 0) // mientras la lista tenga aunque sea un nodo...
            // otra opción: ll_len(this);
        {
            ll_remove(this, 0); // ...llamo a la función para remover el nodo 0
            // remove decrementa el size cada vez que borra un nodo
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
int ll_deleteLinkedList(LinkedList* this) // clear + free
{
    int returnAux = -1;

    if(this != NULL)
    {
        ll_clear(this); // borra los nodos
        free(this); // libera la linkedlist
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
int ll_indexOf(LinkedList* this, void* pElement) // for + get + if
{
    int returnAux = -1;
    int i;

    if(this != NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            // ll_get devuelve el elemento del índice que quiero
            if(ll_get(this, i) == pElement) // pregunto si el elemento que está en el índice i es igual al pElement pasado por parámetro
            {
                returnAux = i; // retorno el índice del elemento
            }
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
int ll_isEmpty(LinkedList* this) // if size (si es 0 està empoty)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_len(this) == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
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
int ll_push(LinkedList* this, int index, void* pElement) // llamar al add
{
    int returnAux = -1;

    if(this != NULL && index >= 0 &&  index <= ll_len(this))
    {
        if(!addNode(this, index, pElement)) // solo entra cuando la addNode devuelve 0
        {
            returnAux = 0;
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
void* ll_pop(LinkedList* this,int index) // lamar a get, quedarse con el pElement y dps llamar a remove y retornar el elemento
{
    void* returnAux = NULL; // para retornar el pElement
    Node* nodeAux; // para guardar el nodo que contiene el pElement que quiero retornar

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        // llamo a get
        nodeAux = getNode(this, index);

        if(nodeAux != NULL)
        {
            // me quedo con el elemento y retorno el pElement
            returnAux = nodeAux->pElement;

            // remuevo el nodo
            ll_remove(this, index);
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
int ll_contains(LinkedList* this, void* pElement) // le pregunto al indexOf si el elemento existe
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
int ll_containsAll(LinkedList* this,LinkedList* this2) // buscar el negativo: el elemento que no esté contenido
// for + get + if (si el elemento no está retorno false y chau)
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
LinkedList* ll_subList(LinkedList* this,int from,int to) // crea una lista nueva desde hasta
// newLinkedList + for (desde hasta) + get + add
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
LinkedList* ll_clone(LinkedList* this) // llamo al sublist y le paso desde 0 hasta el size
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

