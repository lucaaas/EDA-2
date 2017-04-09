/*  Fabiola Malta Fleury 15/0009275
*   Lucas Oliveira Silva 15/0016018
*   Implementação do heap sort com 2 vetores
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000000

int left_index(int index){
  return 2 * index;
}

int rigth_index(int index){
  return (2 * index) + 1;
}


int* heapify(int *vector, int current_index){
  int left, rigth;

  left = left_index(current_index);
  rigth = rigth_index(current_index);

  int largest;
  if(left <= vector[0] && vector[left] > vector[current_index]){
    largest = left;
  }
  else{
    largest = current_index;
  }
  if(rigth <= vector[0] && vector[rigth] > vector[largest]){
    largest = rigth;
  }
  if(largest != current_index){
    int swap = vector[current_index];
    vector[current_index] = vector[largest];
    vector[largest] = swap;
    heapify(vector, largest);
  }
  return vector;
}


int* build_heap(int *vector, int size){
  int i;
  for (i = size/2;i > 0; i--){
    vector = heapify(vector, i);
  }
  return vector;
}

int* heap_sort(int *vector, int size){
  int i;
  int *sorted_vector;
  sorted_vector = malloc(sizeof(int)*size);

  for(i = size; i > 0; i--){
    vector = build_heap(vector, vector[0]);
    sorted_vector[i] = vector[1];
    vector[0]--;
    vector[1] = vector[i];
  }
  return sorted_vector;
}

int main(int argc, char const *argv[]) {


  int *vector; // posição zero guarda o tamanho do vetor
  vector = malloc(sizeof(int)*SIZE);
  vector[0] = SIZE-1;
  int i;
  srand(time(NULL));
  for(i = 1; i < SIZE; i++){
    vector[i] = rand() % 100;
  }
  printf("Antes:  ");
  for(i = 1; i < SIZE; i++){
    printf("%d   ",vector[i]);
  }

  vector = heap_sort(vector, vector[0]);

  printf("\nDepois:  ");
  for(i = 1; i < SIZE; i++){
    printf("%d   ",vector[i]);
  }
  printf("\n\n");
  return 0;
}
