/*  Fabiola Malta Fleury 15/0009275
*   Lucas Oliveira
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8
#define DIGIT 3
#define SMALLEST 0
#define LARGEST 9

int* populate_aux(int *vector, int *vector_aux){
  int i;
  int index;
  for(i = 0; i < SIZE; i++){
    index = vector[i] - SMALLEST;
    vector_aux[index]++;
  }
  return vector_aux;
}


int* restruct_aux(int *vector_aux, int aux_size){
  int i;
  for(i = 1; i < aux_size; i++){
    vector_aux[i] += vector_aux [i-1];
  }
  return vector_aux;
}


int* build_aux(int *vector, int aux_size){
  int *aux_vector;

  aux_vector = calloc(aux_size,sizeof(int));
  return aux_vector;
}

int* sorting(int *vector, int *vector_aux){
  int *sorted_vector;
  int i;
  int index;
  sorted_vector = calloc(SIZE,sizeof(int));

  for(i = SIZE-1; i >= 0; i--){
    index = vector[i] - SMALLEST;
    sorted_vector[vector_aux[index]-1] = vector[i];
    vector_aux[index]--;
  }
  return sorted_vector;
}

int* counting_sort(int *vector){
  int *vector_aux;
  int largest = vector[0], SMALLEST = vector[0];
  int i;
    for(i=1; i < SIZE; i++){
      if(vector[i] < SMALLEST){
        SMALLEST = vector[i];
      }
      if(vector[i] > largest){
        largest = vector[i];
      }
    }

    int aux_size = largest - SMALLEST + 1;
    vector_aux = build_aux(vector, aux_size);
    vector_aux = populate_aux(vector, vector_aux);
    vector_aux = restruct_aux(vector_aux, aux_size);

    vector = sorting(vector, vector_aux);

    return vector;
}


int main(int argc, char const *argv[]) {
  int vector[] = {329, 457, 657, 839, 436, 720, 355};
  int i;
  for(i = 0, i < DIGIT, i++){
    vector = counting_sort(vector, i*10);
  }

    //usar a lógica: num % 10, depois divide por 10 e loop disso
  return 0;
}
