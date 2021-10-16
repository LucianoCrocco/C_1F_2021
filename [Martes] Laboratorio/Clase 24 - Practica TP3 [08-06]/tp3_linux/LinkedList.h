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
LinkedList* ll_newLinkedList(void);//Crea una linkedlist en memoria.
int ll_len(LinkedList* this);//Lenght de mi linkedlist
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);//Añade un elemento a mi lista linkedlist
void* ll_get(LinkedList* this, int index);//Me duelve el elemento con el indice que le paso.
int ll_set(LinkedList* this, int index,void* pElement);//Pisa y reemplaza ese dato en el idnex
int ll_remove(LinkedList* this,int index);//Devuelve si pudo borrarlo o no
int ll_clear(LinkedList* this);//Destruye los elementos que contiene esa lista
int ll_deleteLinkedList(LinkedList* this);//Destruye la lista entera con sus elmentos
int ll_indexOf(LinkedList* this, void* pElement);//Recibe la lista, un elemento de la lista y me devuelve el indice
int ll_isEmpty(LinkedList* this);//Recibe la lista, y me dice si la lista esta vacio o no (en su totalidad).
int ll_push(LinkedList* this, int index, void* pElement);//No pisa, pone el valor de pELement en el index ingresado y mueve los valores en el array. No los pisa
void* ll_pop(LinkedList* this,int index);//Devuelve un puntero a void, que se castea con el tipo de dato que deseo eliminar. Se puede utilizar como un cortar, ya que lo saca de la lista y lo devuelve.
int ll_contains(LinkedList* this, void* pElement);//Probarla nosotros, le paso un elemento y me dice si esta contenido en la lista.
int ll_containsAll(LinkedList* this,LinkedList* this2);//Le paso dos listas, me dice si la lista 2 esta contenida en la lista 1
LinkedList* ll_subList(LinkedList* this,int from,int to);//De una lista, me devuelve un pedazo de la misma. Con un desde hasta trabajando con los subindices (index)(El ejemplo es coincidencia). || 1-9-8-6-4 -> De 1 a 4: 9-8-6. El to exluye, el from incluye.
LinkedList* ll_clone(LinkedList* this);//Clona una lista y la guarda en otra lista. Le da los nodos a la lista nueva y no modifica la lista 1. Puede servir para un ordenamiento sin modificar la original. Cambia el orden de los nodos.
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//Como los ejercicios de la guia

//Para utilizar la ll_linkedlist, utilizo el ll_clear, y para utilizar al ll_clear utilizo al ll_remove
