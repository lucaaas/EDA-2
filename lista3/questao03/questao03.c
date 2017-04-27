#include <stdio.h>
#include <stdlib.h>

int* build_ordained_vector(int* vector, int middle, int init, int end) {
  int i = init, j = middle;
  int *ordained_vector = (int*) malloc ((end - init) * sizeof (int));
  int iterator_ordained_vector = 0;

  while (i <= middle && j <= end) {
    printf("comparando %d com %d\n", vector[i], vector[j]);
    if (vector[i] < vector[j]) {
      ordained_vector[iterator_ordained_vector++] = vector[i++];
    }
    else {
      ordained_vector[iterator_ordained_vector++] = vector[j++];
    }
  }

  while (i <= middle) {
    ordained_vector[iterator_ordained_vector++] = vector[i++];
  }

  while (j <= end) {
    ordained_vector[iterator_ordained_vector++] = vector[j++];
  }

  return ordained_vector;
}

int* merge_sort(int *vector, int init, int end) {
  int middle = end / 2;
  printf("init = %d, end = %d, middle = %d\n", init, end, middle);

  vector = build_ordained_vector (vector, middle, init, end);
  return vector;
}

void show_vector(int* vector, int size) {
  int i = 0;

  while (i < size) {
    printf("%d ", vector[i++]);
  }
}

int main() {
  int vector[] = {3,8,10,2,9};

  int *vectora = merge_sort (vector, 0, 4);

  show_vector(vectora, 5);
  return 0;
}
