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
 *                      o el puntero al espacio reservado.
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
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
    	returnAux= this->size;
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
	Node* pNode=NULL;

	if(this != NULL && nodeIndex >=0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;//me hubico en el primer nodo
		for(int i=0;i<nodeIndex;i++)//itero hasta al anterior al que yo quiero
		{
			pNode = pNode->pNextNode;//accedo al campo netxNode
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
    Node* pNextNode = NULL;
    Node* pAuxNode = NULL;
    if(this != NULL && nodeIndex >=0 && nodeIndex <= ll_len(this))// por si len es 0
    {
    	pNextNode = (Node*) malloc(sizeof(Node));
    	if(pNextNode != NULL)// porque si es null no sigo, si estuviera vacia agregaria tamb el primero tamb
    	{
    		if(nodeIndex == 0)
    		{
    			pNextNode->pNextNode = this->pFirstNode;// me guardo la referecia del primero
    			// si fuera el primero habria un NULL fistNode y estaria bien
    			this->pFirstNode = pNextNode;//ahora appunta al que hice
    		}
    		else
    		{
    			pAuxNode = getNode(this,nodeIndex -1);//guardo el nodo anterior
    			if(pAuxNode != NULL)
    			{
    				pNextNode->pNextNode = pAuxNode->pNextNode;//no pierdo la dire del proximo y si fuera el ultimo seria un null
    				pAuxNode->pNextNode = pNextNode;//Apunto al nuevo nodo
    			}
    		}
    		pNextNode->pElement = pElement;
    		this->size++;
    		returnAux = 0;
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
int ll_add(LinkedList* this, void* pElement)// lo agrego
{
    int returnAux = -1;
    int len = ll_len(this);

    if(this != NULL )
    {
    	returnAux=addNode(this,len,pElement);
    }

    return returnAux;
}
//esta mal la descripcion
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)// obtengo el elemneto(pasajero,etc
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if( this != NULL && index >=0 && index < ll_len(this))//no me paso del largo de la lista
    {
    	pNode = getNode(this,index);//obtengo la direccion de memoria del nodo
    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;// para retornar el elemento
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
    Node* pNode = NULL;

    if( this != NULL && index >=0 && index < ll_len(this))
    {
    	pNode = getNode(this,index);//obtengo la direccion de memoria del nodo
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;//la modifico
    		returnAux =0;
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
    Node* pAuxNode = NULL;
    Node* pAuxNodeDos = NULL;
    if(this != NULL && index >=0 && index < ll_len(this))//
    {
    	pAuxNode = getNode(this,index);//obtenfo el quiero eleminar
    	if(pAuxNode != NULL)// porque si es null no sigo, si estuviera vacia agregaria tamb el primero tamb
    	{
    		if(index == 0)
    		{
    			this->pFirstNode = pAuxNode ->pNextNode;// me guardo la referecia del primero
    		}
    		else
    		{
    			pAuxNodeDos = getNode(this,index -1);//guardo el nodo anterior
    			if(pAuxNodeDos != NULL)
    			{
    				pAuxNodeDos->pNextNode = pAuxNode->pNextNode;// le asigno la direccion del que borra q apuntaba al siguiente
    			}
    		}
    		this->size--;
    		free(pAuxNode);
    		returnAux = 0;
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
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);
    	if(len >0)// si es mayor borro
    	{
    		for(int i=0;i< len;i++)
    		{
    			ll_remove(this,i);
    		}
    		returnAux = 0;
    	}
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
    	if(!ll_clear(this))
    	{
    		free(this);
    		returnAux = 0;
    	}
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
    int len;
    void* pAux = NULL;

    if(this != NULL)
    {
    	len = ll_len(this);
    	for(int i=0;i<len;i++)
    	{
    		pAux = ll_get(this,i);//obtengo el elemento
    		if(pAux == pElement)// y comparo el elemento son iguales lo retorno y rompo
    		{
    			returnAux = i;
    			break;
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
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_len(this) >0)// de esta manera accedo al size para saber q esta cargada
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1;
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
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >=0 && index <= ll_len(this))//recordar q puede ser 0 el index y si es la ulitma lo agrego tamb
    {
    	returnAux = addNode(this,index,pElement);
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
    void* returnAux = NULL;

    if(this != NULL && index >=0 && index < ll_len(this))//estoy eliminando asi que tiene q ser menor y no igual
    {
    	returnAux = ll_get(this,index);//obtengo el elemento antes de borrarlo no me importa si tiene null o no
    	ll_remove(this, index);
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
    	if(ll_indexOf(this,pElement) == -1)
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1;
    	}
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
    int returnAux = -1;
    int len;
    void* pAux = NULL;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;// doy por sentado que encontro
    	len = ll_len(this2);
    	for(int i=0;i<len;i++)
    	{
    		pAux = ll_get(this2,i);
    		if(!ll_contains(this,pAux))// si no lo contiene el elemento devuelve 0
    		{
    			returnAux = 0;//no esta y rompo
    			break;
    		}
    	}
    }
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
    LinkedList* cloneSublist = NULL;
    void* pAux = NULL;

    if(this != NULL && from >=0 && from < ll_len(this) && to > from && to <= ll_len(this))// menor porque no esta incluido el ultimo
    {
    	cloneSublist = ll_newLinkedList();
    	if(cloneSublist != NULL)
    	{
    		for(int i=from;i<to;i++)
    		{
    			pAux = ll_get(this, i);//trae el elemnto
    			ll_add(cloneSublist,pAux);// lo copia a la sub
    		}
    	}
    }
    return cloneSublist;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* clone = NULL;

    if(this != NULL)
    {
    	clone = ll_subList(this,0,ll_len(this));
    }
    return clone;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * retorn <0 si el primero es mayor, 0 si son iguales, y > 0 si el segundo es mayor
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int estaOrdenado;
    int len;
    void* pAuxElement = NULL;
    void* pAuxElement2 =  NULL;

    if(this != NULL && (order == 0 || order == 1) && pFunc != NULL)// el nombre ya es la direccion de memoria es un puntero
    {
    	len = ll_len(this);
    	do
    	{
    		estaOrdenado = 1;
    		len--;
    		for(int i=0;i<len;i++)
    		{
    			pAuxElement = ll_get(this, i);//obtengo la dir de memoria 1
    			pAuxElement2 = ll_get(this, i+1);//obtengo la dir de memoria 2 no pierdo los datos
    			if((pFunc(pAuxElement,pAuxElement2) > 0 && order == 1) ||
    					(pFunc(pAuxElement,pAuxElement2) < 0 && order == 0))
    			{
    				ll_set(this,i,pAuxElement2);
    				ll_set(this,i+1,pAuxElement);
    				estaOrdenado=0;
    			}
    		}

    	}while(estaOrdenado == 0);
    	returnAux = 0;
    }
    return returnAux;

}

