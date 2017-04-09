/*  Fabiola Malta Fleury 15/0009275
*   Lucas Oliveira Silva 15/0016018
*   Implementação do radix com counting sort
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000
#define DIGIT 8
#define SMALLEST 0
#define LARGEST 9

int* populate_aux(int *vector, int *vector_aux, int divisor){
  int i;
  int index;
  for(i = 0; i < SIZE; i++){
    index = ((vector[i] / divisor) % 10) - SMALLEST;
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

int* sorting(int *vector, int *vector_aux, int divisor){
  int *sorted_vector;
  int i;
  int index;
  sorted_vector = calloc(SIZE,sizeof(int));

  for(i = SIZE-1; i >= 0; i--){
    index = ((vector[i] / divisor) % 10) - SMALLEST;
    sorted_vector[vector_aux[index]-1] = vector[i];
    vector_aux[index]--;
  }
  return sorted_vector;
}

int* counting_sort(int *vector, int divisor){
  int *vector_aux;
  int i;

    int aux_size = LARGEST - SMALLEST + 1;
    vector_aux = build_aux(vector, aux_size);
    vector_aux = populate_aux(vector, vector_aux, divisor);
    vector_aux = restruct_aux(vector_aux, aux_size);

    vector = sorting(vector, vector_aux, divisor);

    return vector;
}


int main(int argc, char const *argv[]) {
  int *vector;
  int i;

  vector = malloc(sizeof(int)*SIZE);
  srand(time(NULL));
  printf("Vetor inicial: ");
  for(i = 0; i < SIZE; i++){
    vector[i] = rand() % 100000000;

      printf("%d ",vector[i]) ;
  }
  int aux;
  aux = 1;
  for(i = 0; i < DIGIT; i++){
    vector = counting_sort(vector, aux);
    aux*=10;
  }

  printf("\nVetor final: ");
  for(i = 0; i < SIZE; i++){
    printf("%d ",vector[i]) ;
  }
  printf("\n\n\n");
  return 0;
}
