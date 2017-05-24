/*  Fabiola Malta Fleury 15/0009275
*   Lucas Oliveira Silva 15/0016018
*   This program reads distances from houses, not necessarily in order, to a start point
*   and determines how many cell towers will be needed to cover
*   all the houses, and where they are located.
*/

#include <stdio.h>
#include <stdlib.h>
#define RANGE 4 // cell tower range
#define DIGIT 4 //quantity of digits allowed on distances
#define SMALLEST 0 //smallest decimal, used for counting sort
#define LARGEST 9 //largest decimal, used for couting sort

typedef struct tower{
  int distance;
  struct tower *next_tower;
  struct tower *previous_tower;
}tower;

int size;
void tower_listing(int *vector){
  tower *head = malloc(sizeof(tower));
  tower *tail;
  int quantity = 1;
  head->distance = vector[0] + RANGE;
  head->previous_tower = NULL;
  head->next_tower = NULL;
  tail = head;
  for(int i = 0; i < size; i++){
    if (vector[i] - tail->distance > RANGE){
      quantity++;
      tower *new = malloc(sizeof(tower));
      new->distance = vector[i] + RANGE;
      new->previous_tower = tail;
      new->next_tower = NULL;
      tail->next_tower = new;
      tail = new;
    }
  }
  printf("\n\n\n\n\n");
  printf("Foram necessarias %d torres, posicionadas nas seguintes distancias: ", quantity);
  tower *tower = head;
  for (int i = 0; i < quantity; i++) {
      printf("%d ", tower->distance);
      tower = tower->next_tower;
  }
}

int* populate_aux(int *vector, int *vector_aux, int divisor){
  int i;
  int index;
  for(i = 0; i < size; i++){
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
  sorted_vector = calloc(size,sizeof(int));

  for(i = size-1; i >= 0; i--){
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
  int quantity;
  printf("Digite a quantidade de casas na estrada: ");
  scanf("%d",&quantity);
  int *vector = malloc(sizeof(int)*quantity);

  for(int i = 0; i < quantity; i++){
    printf("\nDigite a distancia da casa %d em relacao ao final oeste da estrada: ", i+1);
    scanf("%d",&vector[i]);
  }
  size = quantity;
  int aux;
  aux = 1;
  for(int i = 0; i < DIGIT; i++){
    vector = counting_sort(vector, aux);
    aux*=10;
  }

  tower_listing(vector);
  printf("\n\n\n");
  return 0;
}
