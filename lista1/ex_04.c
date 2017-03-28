#include <stdio.h>
#include <stdlib.h>
#define INDEX_LENGTH 5
#define VECTOR_LENGTH 40

int main(){
  int vector[VECTOR_LENGTH] = {1, 2, 4, 13, 32, 37, 40, 42, 50, 56, 63, 66, 71, 75, 81, 82,
                    84, 90, 94, 97, 105, 113, 132, 137, 140, 142, 150, 156, 160,
                     163, 166, 171, 175, 181, 182, 184, 190, 194, 197, 208};
  int *index_table = malloc(sizeof(int)*INDEX_LENGTH);
  int search;
  int found = -1, ind;
  int space = 0, aux = 0;
  space = VECTOR_LENGTH/INDEX_LENGTH;
  /*
  * For filling index_table with values from vector using space to determina
  * which members from vector will be selected
  *
  */
  int counter = 0;
  for (counter = 0; counter < VECTOR_LENGTH; counter+=space) {
    index_table[aux] = vector[counter];
    aux++;
  }

  scanf("%d",&search);
  counter = 0;
  while(counter < INDEX_LENGTH){
    if(index_table[counter] > search){
      ind = (counter - 1) * 8;
    }
    counter++;
  }
  counter = ind;

  while (counter < VECTOR_LENGTH) {
    if(vector[counter] == search){
      printf("\nValor encontrado %d na posicao %d!", search, counter);
      found = 0;
    }
    counter++;
  }

  if(found == -1){
    printf("Registro nao encontrado\n");
  }
  return 0;
}
