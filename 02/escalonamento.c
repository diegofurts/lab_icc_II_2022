#include <stdio.h>
#include <string.h>

int globalzao[500];

void gerar_solucoes(int n, int* vet, int fixados) {

	if (fixados==n) {
		for (int i = 0; i < n; i++)
			printf("%d ", globalzao[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if(vet[i] == 0) {
			vet[i] = 1;
			globalzao[fixados] = i;
			gerar_solucoes(n, vet, fixados+1);
			vet[i] = 0;
		}
	}

	return;
}

int main() {

	int n = 500;
	int vet[n];

	memset(vet, 0, sizeof(vet));

	gerar_solucoes(n, vet, 0);

}