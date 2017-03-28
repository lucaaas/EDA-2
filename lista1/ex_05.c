#include <stdio.h>

#define MAX 10

int main(){
	int numProcurado = 0;
	int vetor[MAX] = {1,2,3,4,5,6,7,8,9,10};

	printf("Digite o número que deseja procurar: ");
	scanf("%d", &numProcurado);

	int inicio = 0, fim = MAX, i = 0, media = 0;
	do{
		media = (fim - inicio)/2;
		i = media + inicio;
		if(vetor[i] > numProcurado){
			fim = i;
		}
		else if(vetor[i] < numProcurado){
			inicio = i;
		}

	} while (vetor[i] != numProcurado && media != 0);

	if(vetor[i] == numProcurado){
		printf("O numero %d foi encontrado na posicao %d\n\n", numProcurado,i);
	} 
	else{
		printf("Número não encontrado\n");
	}

	return 0;
}
