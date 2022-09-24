#include <stdio.h>

void merge(int *v, int ini, int meio, int fim) {

	int i = ini, j = meio + 1, k = 0;
	
	int n = fim - ini + 1;
	int aux[n];

	while( (i <= meio) && (j <= fim)) {

		if(v[i] <= v[j]) {
			aux[k] = v[i];
			i++;
		} else {
			aux[k] = v[j];
			j++;
		}
		k++;

	}

	while (j <= fim) {
		aux[k] = v[j];
		k++;
		j++;
	}

	while (i <= meio) {
		aux[k] = v[i];
		k++;
		i++;
	}

	for (i = 0; i < n; i++) {
		v[ini+i] = aux[i];
	}

}

void merge_sort(int *v, int ini, int fim) {

	if (ini >= fim) // caso base
		return;

	int meio = (ini+fim)/2;
	merge_sort(v, ini, meio);
	merge_sort(v, meio+1, fim);
	merge(v, ini, meio, fim);
}

int main() {

	int n = 1000000;
	int v[n];
	int a;

	for (int i = 0; i < n; i++)
		scanf("%d ", &v[i]);

	merge_sort(v, 0, n-1);

	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");

}