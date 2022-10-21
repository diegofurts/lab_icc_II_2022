#include <stdio.h>

#define TAM 100000

void escolhe_pivo(int *v, int ini, int fim) {
	// vou escolher o primeiro, então não faço nada
}

int particao(int *v, int ini, int fim) {

	escolhe_pivo(v, ini, fim);
	int pivo = v[ini];

	int i = ini+1;
	int j = fim;
	int aux;

	while (i <= j) {

		while(i <= fim && v[i] <= pivo) {
			i++;
		}

		while(v[j] > pivo) {
			j--;
		}

		if (i<j) {
			//troca
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;	
		}

	}

	// jogar o pivô para a frente
	aux = v[ini];
	v[ini] = v[j];
	v[j] = aux;

	return j;

}

void quicksort(int *v, int ini, int fim) {

	// parada
	if (ini >= fim)
		return;

	int pos_pivo = particao(v, ini, fim);
	// printf("%d\n", pos_pivo);
	// recursao
	quicksort(v, ini, pos_pivo-1);
	quicksort(v, pos_pivo+1, fim);

}

int main() {

	int v[TAM];

	for (int i=0; i < TAM; i++)
		v[i] = TAM-i;

	quicksort(v, 0, TAM-1);

	/*for (int i=0; i < TAM; i++)
		printf("%d ", v[i]);
	printf("\n");*/

}