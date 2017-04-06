/*  Fabiola Malta Fleury 15/0009275
*   Lucas Oliveira
*   Implementação do heap sort normal
*/
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  int *vector; // posição zero guarda o tamanho do vetor
  return 0;
}

int[] heapify(int vector[], int current_index){
  int left_index, rigth_index;

  left_index = left_index(current_index);
  rigth_index = rigth_index(current_index);

  int largest;
  if(left_index <= vector[0] && vector[left_index] > vector[current_index]){
    largest = left_index;
  }
  else{
    largest = current_index;
  }
  if(rigth_index <= vector[0] && vector[rigth_index] > vector[largest]){
    largest = rigth_index;
  }
  if(largest != current_index){
    int swap = vector[current_index];
    vector[current_index] = vector[largest];
    vector[largest] = swap;
    heapify(vector, largest);
  }
  return vector;
}


void build_heap(int vector[]){

}

void heap_sort(int vector[]){

}

void extract_max(int vector[]){

}

int left_index(int index){
  return 2 * index;
}

int rigth_index(int index){
  return (2 * index) + 1;
}

int parent_index(int index){
  return (index/2);
}
