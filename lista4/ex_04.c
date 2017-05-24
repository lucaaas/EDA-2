/* Fabiola Malta Fleury 15/0009275
*  Lucas Oliveira Silva 15/0016018
*  This program reads sequence s and then s', returning if s' is a
*  subsequence of s or not.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  /*reading strings and calculating ther length*/
  char sequence[300];
  int n = 0;
  printf("Digite a sequencia s: ");
  if (fgets(sequence, sizeof(sequence), stdin)) {
    n = strlen(sequence);
  }
  printf("\nDigite a sequencia s': ");
  char subsequence[300];
  int m = 0;
  int *k;
  if (fgets(subsequence, sizeof(subsequence), stdin)) {
    m = strlen(subsequence);
    k = malloc (sizeof(int)*m);
  }

  /*checking if subsequence is actually a subsequence of sequence*/
  int i = 0;
  int j = 0;
  while (i <= n && j <= m){
    if (sequence[i] == subsequence[j]){
      k[j] = i;
      i++;
      j++;
    }
    else{
      i++;
    }
  }

  /*returning results*/
  if (j == (m + 1)) {
    printf("\n\n\nA subsequencia: ");
    for (int counter = 0; counter < m; counter++){
      printf("%c", sequence[k[counter]]);
    }
    printf("esta presente na sequencia s.\n");
  } else {
    printf("Nao e uma subsequencia.");
  }
  return 0;
}
