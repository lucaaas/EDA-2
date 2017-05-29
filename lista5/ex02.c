#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*  Fabiola Malta Fleury 15/0009275
*   Lucas Oliveira Silva 15/0016018 */

#define LENGTH_VECTOR 10
#define MAX_VALUE 100

// Method to create a random vector
int* create_vector(){
  int *vector = (int *) malloc (LENGTH_VECTOR * sizeof(int));
  int i = 0;

  srand((unsigned)time(NULL));
  for (i = 0; i < LENGTH_VECTOR; i++) {
    int number = rand() % MAX_VALUE;
    vector[i] = number;
  }

  return vector;
}

// method to show a vector
void show_vector(int* vector, int length_vector) {
  int i = 0;

  while (i < length_vector) {
    printf("%d ", vector[i++]);
  }
}

// method to merge two vectors
int* build_ordained_vector(int* vector, int middle, int init, int end) {
  int i = init, j = middle+1;
  int *ordained_vector = (int*) malloc (sizeof (vector));
  int iterator_vector = init;

  while (i <= middle && j <= end) {
    if (vector[i] < vector[j]) {
      ordained_vector[iterator_vector++] = vector[i++];
    }
    else {
      ordained_vector[iterator_vector++] = vector[j++];
    }
  }

  while (i <= middle) {
    ordained_vector[iterator_vector++] = vector[i++];
  }

  while (j <= end) {
    ordained_vector[iterator_vector++] = vector[j++];
  }

  for (iterator_vector = init; iterator_vector <= end; iterator_vector++) {
    vector[iterator_vector] = ordained_vector[iterator_vector];
  }

  return vector;
}

// method that implement merge sort
int* merge_sort(int *vector, int init, int end) {

  if (init < end) {
    int middle = (init + end) / 2;
    vector = merge_sort (vector, init, middle);
    vector = merge_sort (vector, middle+1, end);
    vector = build_ordained_vector (vector, middle, init, end);
  }

  return vector;
}

// method to divide a vector
int* split_vector (int* vector, int init, int end) {
  int half_vector = LENGTH_VECTOR/2;
  int *vector_aux = (int*) malloc (half_vector * sizeof(int));

  int iterator_aux = 0;
  for (int iterator = init; iterator < end; iterator++){
    vector_aux[iterator_aux] = vector[iterator];
    iterator_aux++;
  }

  return vector_aux;
}

// method to count inversions that ocurrs when i<j and vector[i] > vector[2*j]
int count_inversions (int* vector, int length_vector) {
  int amount_inversions = 0;

  for (int i = 0; i < length_vector; i++) {
    for (int j = 2*i; j < length_vector; j+=2) {
      if (vector[i] > vector[j]) {
        amount_inversions++;
      }
      else{
        // do nothing
      }
    }
  }

  return amount_inversions;
}

int main() {
  int *vector = create_vector();
  int half_vector = LENGTH_VECTOR/2;
  printf("\nVetor: ");
  show_vector(vector, LENGTH_VECTOR);

  int *vectorA = NULL;
  vectorA = split_vector (vector, 0, half_vector);
  int amount_inversions_A = count_inversions (vectorA, half_vector);
  vectorA = merge_sort (vectorA, 0, half_vector);

  int *vectorB = NULL;
  vectorB = split_vector (vector, half_vector, LENGTH_VECTOR);
  int amount_inversions_B = count_inversions (vectorB, half_vector);
  vectorB = merge_sort (vectorB, 0, half_vector);

  vector = merge_sort (vector, 0, LENGTH_VECTOR);
  int amount_inversions_vector = count_inversions (vector, LENGTH_VECTOR);

  int total_inverstions = amount_inversions_A + amount_inversions_B + amount_inversions_vector;

  printf("\nTotal de inversoes: %d\n", total_inverstions);
  return 0;
}
