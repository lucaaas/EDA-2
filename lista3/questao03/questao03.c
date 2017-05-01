#include <stdio.h>
#include <stdlib.h>

#define LENGTH_VECTOR 8
#define MAX_VALUE 100

int* create_vector(){
  int *vector = malloc (LENGTH_VECTOR * sizeof(int));
  int i = 0;

  srand((unsigned)time(NULL));
  for (i = 0; i < LENGTH_VECTOR; i++) {
    int number = rand() % MAX_VALUE;
    vector[i] = number;
  }

  return vector;
}

void show_vector(int* vector) {
  int i = 0;

  while (i < LENGTH_VECTOR) {
    printf("%d ", vector[i++]);
  }
}

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

int* merge_sort(int *vector, int init, int end) {

  if (init < end) {
    int middle = (init + end) / 2;
    vector = merge_sort (vector, init, middle);
    vector = merge_sort (vector, middle+1, end);
    vector = build_ordained_vector (vector, middle, init, end);
  }

  return vector;
}



int main() {
  int *vector = create_vector();

  printf("Vetor antes da ordenacao: ");
  show_vector(vector);

  printf("\n\nVetor depois da ordenacao: ");
  vector = merge_sort (vector, 0, LENGTH_VECTOR-1);
  show_vector(vector);

  printf("\n\n\n");

  return 0;
}
