/* Fabiola Malta Fleury 15/0009275
*  Lucas Oliveira Silva 15/0016018
*  This program reads a sequence of streams and say if is possible the shedule
*  between them
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[]) {
  printf("Digite a quantidade de streams: ");
  int amount_streams = 0;
  scanf ("%d", &amount_streams);

  printf("Digite a largura de banda: ");
  int bandwidth = 0;
  scanf("%d", &bandwidth);

  int total_bits = 0, total_time = 0;
  for (int count = 0; count < amount_streams; count++) {
    printf("=====================\n");
    printf("Stream %2d\n", count+1);
    printf("=====================\n");

    printf("Digite a quantidade de bits do stream: ");
    int amount_bits = 0;
    scanf("%d", &amount_bits);
    total_bits += amount_bits;

    printf("Digite o periodo de tempo do stream: ");
    int time_stream = 0;
    scanf("%d", &time_stream);
    total_time += time_stream;;
  }

  if (total_bits <= (bandwidth * total_time)) {
    printf("E possivel fazer o shedule\n");
  }
  else{
    printf("Nao e possivel fazer o shedule\n");
  }

  return 0;
}
