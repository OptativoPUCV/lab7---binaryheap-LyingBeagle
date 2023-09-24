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


void* heap_top(Heap* pq){

    if(pq->size == 0){
        return NULL;
    }

    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

    if(pq->size == pq->capac){
      pq->capac = pq->capac * 2 + 1;
      pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
    }

    heapElem nuevoElemento;
    nuevoElemento.data = data;
    nuevoElemento.priority = priority;
  
    int i = pq->size;
    pq->heapArray[i] = nuevoElemento;
    pq->size++;

  
    while(i != 0 && pq->heapArray[(i-1) / 2].priority < pq->heapArray[i].priority){

        heapElem temp = pq->heapArray[i];
        pq->heapArray[i] = pq->heapArray[(i-1)/2];
        pq->heapArray[(i-1)/2] = temp;
      
        i = (i-1) / 2;
    }

}


void heap_pop(Heap* pq){

    if(pq->size == 0){
        return;
    }

    pq->heapArray[0] = pq->heapArray[pq->size - 1];

    pq->size--;

}

Heap* createHeap(){

  Heap* heap = (Heap*)malloc(sizeof(Heap));

  heap->capac = 3;

  heap->heapArray = (heapElem*)malloc(heap->capac*sizeof(heapElem));

  heap->size = 0;

   return heap;
}
