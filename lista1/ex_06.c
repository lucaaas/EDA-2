#include <stdio.h>

#define MAX 10

int procuraElemento(int vetor[MAX], int numProcurado){
	int meio = 0, inferior = 0, superior = MAX - 1;
	do{
		meio = inferior + ((superior - inferior) * (numProcurado - vetor[inferior]))/(vetor[superior]-vetor[inferior]);

		if(vetor[meio] > numProcurado){
			superior = meio - 1;
		}
		else if(vetor[meio] < numProcurado){
			inferior = meio + 1;
		}
		printf("meio = %d vetor[meio] = %d num proc = %d\n", meio, vetor[meio], numProcurado);
	} while (vetor[meio] != numProcurado && superior >= inferior);

	return meio;
}

int main(){
	int numProcurado = 0;
	int vetor[] = {1,2,3,4,5,6,7,8,9,10};

	printf("Digite o número que deseja procurar: ");
	scanf("%d", &numProcurado);
	printf("num Pro = %d\n", vetor[10]);
	int i = procuraElemento(vetor, numProcurado);

	if(vetor[i] == numProcurado){
		printf("O numero %d foi encontrado na posicao %d\n\n", numProcurado,i);
	}
	else{
		printf("Número não encontrado\n");
	}

	return 0;
}
