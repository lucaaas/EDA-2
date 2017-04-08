/*  Fabiola Malta Fleury 15/0009275
*   Lucas Oliveira Silva 15/0016018
*   Implementação do heap sort normal
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

int left_index(int index){
  return 2 * index;
}

int rigth_index(int index){
  return (2 * index) + 1;
}

int parent_index(int index){
  return (index/2);
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

  vector = build_heap(vector, size);

  for(i = size; i > 1; i--){
    int swap = vector[1];
    vector[1] = vector [i];
    vector[i] = swap;
    vector[0]--;
    heapify(vector, 1);
  }
  return vector;
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

  clock_t begin = clock();
  vector = heap_sort(vector, vector[0]);
  clock_t end = clock();

  printf("\nDepois:  ");
  for(i = 1; i < SIZE; i++){
    printf("%d   ",vector[i]);
  }
  printf("\n\n");

  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("Time spent: %.8lf", time_spent);
  return 0;
}
