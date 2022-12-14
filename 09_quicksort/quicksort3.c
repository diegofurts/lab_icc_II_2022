#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100000

// mediana de três aleatórios
// reaver ifs (algo errado  não está certo)
void escolhe_pivo(int *v, int ini, int fim) {
	
	int aux;

	if (ini >= fim-1) //nem precisa
		return;

	srand(time(0));

	int a = rand()%(fim-ini) + ini;
	int b = rand()%(fim-ini) + ini;
	int c = rand()%(fim-ini) + ini;


	if (v[a] < v[b]) {

		if (v[a] < v[c]) {
			if (v[b] < v[c]) { // a < b < c
				aux = v[b];
				v[b] = v[ini];
				v[ini] = aux;
			} else { // a < c < b
				aux = v[c];
				v[c] = v[ini];
				v[ini] = aux;
			}
		} else { // c < a < b
			aux = v[c];
			v[c] = v[ini];
			v[ini] = aux;
		}

	} else { // b < a

		if (v[a] < v[c]) { // b < a < c
			aux = v[a];
			v[a] = v[ini];
			v[ini] = aux;
		} else { // c < a e b < a

			if (v[b] < v[c]) { // b < c < a
				aux = v[c];
				v[c] = v[ini];
				v[ini] = aux;
			} else { // c < b < a
				aux = v[b];
				v[b] = v[ini];
				v[ini] = aux;
			}

		}

	}

	return;

}

int particao(int *v, int ini, int fim) {

	escolhe_pivo(v, ini, fim);
	int pivo = v[ini];

	int i = ini+1;
	int j = fim;
	int aux;

	while (i <= j) {

		while(i <= j && v[i] <= pivo) {
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
	//printf("%d\n", pos_pivo);
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