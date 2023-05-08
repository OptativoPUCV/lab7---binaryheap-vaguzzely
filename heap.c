#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

//La función heap_top devuelve el dato con la mayor prioridad (el elemento con la raíz del montículo). en la primera casilla del arreglo.
//heap_pop devuelve y elimina el elemento de mayor prioridad del montículo

void* heap_top(Heap* pq)
{
  if (pq->size == 0) 
  {
    return NULL;
  }
  return pq->heapArray->data;
  return NULL;
}


/*El push inserta un nuevo elemento en el montículo en la siguiente posición disponible, es decir, al final del arreglo. Luego, el algoritmo "percola hacia arriba" el elemento insertado para asegurarse de que esté en la posición adecuada para mantener la propiedad del montículo.

Mantener la propiedad del montículo significa que se mantiene la estructura del montículo binario completo, donde cada nodo padre tiene un valor de prioridad mayor o igual que sus hijos. En otras palabras, se asegura que el elemento con la máxima prioridad siempre esté en la raíz del árbol. Al insertar un nuevo elemento, se reorganiza la estructura del montículo para que esta propiedad se mantenga. */
void heap_push(Heap* pq, void* data, int priority)
{
  if(pq->size == pq->capac)
  {
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
  }
  
  heapElem nuevoElem = {data, priority};
  
  int aux = pq->size++; 
  while(aux > 0 && pq->heapArray[(aux - 1) / 2].priority < nuevoElem.priority)
  {
    pq->heapArray[aux] = pq->heapArray[(aux - 1) / 2];
    aux = (aux - 1) / 2; // se actualiza el índice del hijo
  }
  pq->heapArray[aux] = nuevoElem;
}

//extraer el elemento con mayor prioridad del heap
//heap_pop devuelve y elimina el elemento de mayor prioridad del montículo
void heap_pop(Heap* pq)
{
  if(pq->size == 0)
  {
    return NULL;
  }
  

}


/*Esta función crea un nuevo dato de tipo Heap inicializando sus variables. Considere que la capacidad incial es de 3 casillas para el arreglo.
   > Recuerde reservar memoria para el Heap y también para el arreglo `heapArray`.*/
Heap* createHeap()
{
  Heap* colaDePrioridad = (Heap*) malloc(sizeof(Heap));
  colaDePrioridad->size = 0;
  colaDePrioridad->capac = 3;
  colaDePrioridad->heapArray = (heapElem*) malloc(colaDePrioridad->capac * sizeof(heapElem));
  return colaDePrioridad;
}
