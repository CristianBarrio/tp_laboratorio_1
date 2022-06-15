/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif


//Publicas

/** Crea un nuevo LinkedList
 *
 * @return retorna el linkedList
 */
LinkedList* ll_newLinkedList(void);

/** Retorna el tamaño del LinkedList
 *
 * @param this LinkedList* puntero al LinkedList
 * @return Retorna -1 si hubo un error, de lo contrario la longitud del array
 */
int ll_len(LinkedList* this);

/**
 *
 * @param this
 * @param nodeIndex
 * @return
 */
Node* test_getNode(LinkedList* this, int nodeIndex);

/**
 *
 * @param this
 * @param nodeIndex
 * @param pElement
 * @return
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/** Agrega un elemento al final del LinkedList
 *
 * @param this LinkedList* puntero al LinkedList
 * @param pElement void* elemento a agregar
 * @return retorna -1 si hubo un error, de lo contrario 0
 */
int ll_add(LinkedList* this, void* pElement);

/** Retorna el punero al elemento en el indice especificado.
 * Si hay un error retorna NULL, de lo contrario el elemento
 *
 * @param this LinkedList* puntero al LinkedList
 * @param index int indice especificado
 */
void* ll_get(LinkedList* this, int index);

/** Inserta un elemento en el indice especificado del LinkedList
 *
 * @param this LinkedList* puntero al LinkedList
 * @param index int indice especificado
 * @param pElement void* puntero al elemento
 * @return retorna -1 si hubo un error, de lo contrario 0
 */
int ll_set(LinkedList* this, int index,void* pElement);

/** Elimina un elemento del LinkedList
 *
 * @param this LinkedList* puntero al LinkedList
 * @param index int indice del elemento
 * @return retorna -1 si hubo un error, de lo contrario 0
 */
int ll_remove(LinkedList* this,int index);

/** Borra todos los elementos del LinkedList
 *
 * @param this LinkedList* puntero al LinkedList
 * @return retorna -1 si hubo un error, de lo contrario 0
 */
int ll_clear(LinkedList* this);

/** Elimina el LinkedList
 *
 * @param this LinkedList* puntero al LinkedList
 * @return retorna -1 si hubo un error, 1 si esta vacio y 0 si contiene elementos
 */
int ll_deleteLinkedList(LinkedList* this);

/** Retorna el indice de la primera aparicion de un elemento en el LinkedList
 *
 * @param this LinkedList* puntero al LinkedList
 * @param pElement void* puntero al elemento especificado
 * @return retorna -1 si hubo un problema, de lo contrario el indice
 */
int ll_indexOf(LinkedList* this, void* pElement);

/** Verifica que el LinkedList contenga elementos
 *
 *
 * @param this LinkedList* puntero al LinkedList
 * @return retorna 0 si contiene elementos y 1 si no los tiene
 */
int ll_isEmpty(LinkedList* this);

/** Desplaza los elementos e inserta en la posicion index
 *
 * @param this LinkedList* puntero al LinkedList
 * @param index int indice especificado
 * @param pElement void* puntero al elemento ubicado en el indice
 * @return retorna -1 si hubo un problema, de lo contrario 0
 */
int ll_push(LinkedList* this, int index, void* pElement);

/** retorna un puntero al elemento que se encuentra en el indice y lo elimina de la lista
 *
 * @param this LinkedList* puntero al LinkedList
 * @param index int indice especificado
 */
void* ll_pop(LinkedList* this,int index);

/** Comprueba si existe el elemento que se le pasa como parametro
 *
 * @param this LinkedList* puntero al LinkedList
 * @param pElement void* puntero al elemento
 * @return retorna -1 si hubo un error, 1 si encuentra el elemento y 0 si no lo encuentra
 */
int ll_contains(LinkedList* this, void* pElement);

/** Comprueba si los elementos pasados son contenidos por el LinkedList
 *
 * @param this LinkedList* puntero al LinkedList
 * @param this2 LinkedList* puntero a los elementos pasados
 * @return retorna -1 si hubo un error o si no se encuentra el elemento, 0 si las listas difieren y 1 si son iguales
 */
int ll_containsAll(LinkedList* this,LinkedList* this2);

/** Retorna un nuevo LinkedList con el subconjunto de elementos
 *
 * @param this LinkedList* puntero al LinkedList
 * @param from int
 * @param to int
 * @return retorna NULL si hubo un error, de lo contrario devuelve el nuevo array
 */
LinkedList* ll_subList(LinkedList* this,int from,int to);

/** Retorna un nuevo LinkedList copia del origianl
 *
 * @param this LinkedList* puntero al LinkedList
 * @return retorna NULL si hubo un error, de lo contrario devuelve el nuevo array
 */
LinkedList* ll_clone(LinkedList* this);

/** Ordena los elementos del array
 *
 * @param this LinkedList* puntero al LinkedList
 * @param pFunc int puntero a la funcion de ordenamiento
 * @param order int determina si el orden es ascendente o descendiente
 * @return retorna -1 si hubo un error, de lo contrario 0
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
