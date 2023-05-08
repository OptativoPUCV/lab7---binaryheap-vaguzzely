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


void* heap_top(Heap* pq)
{
  if (pq->size == 0) 
  {
    return NULL;
  }
  return pq->heapArray->data;
  return NULL;
}



void heap_push(Heap* pq, void* data, int priority)
{
  if(pq->size == pq->capac)
  {
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
  }
  
  heapElem nuevoElem = {data, priority};

  int aux = pq-> size++;
  
  
  
  
  
  
  

}


void heap_pop(Heap* pq){

}

Heap* createHeap()
{
  Heap* colaDePrioridad = (Heap*) malloc(sizeof(Heap));
  colaDePrioridad->size = 0;
  colaDePrioridad->capac = 3;
  colaDePrioridad->heapArray = (heapElem*) malloc(colaDePrioridad->capac * sizeof(heapElem));
  return colaDePrioridad;
}
