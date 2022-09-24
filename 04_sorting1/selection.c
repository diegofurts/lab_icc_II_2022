#include <stdio.h>

void selection_sort(int *v, int n) {

	int i, j, aux, menor, menor_idx;

	for (i = 0; i < n; i++) {
		menor = v[i];
		menor_idx = i;
	
		for (j = i+1; j < n; j++) {

			if (v[j] < menor) {
				menor = v[j];
				menor_idx = j;
			}

		}

		aux = v[i];
		v[i] = v[menor_idx];
		v[menor_idx] = aux;

	}
}

int main() {

	int n = 1000000;
	int v[n];

	for (int i = 0; i < n; i++)
		scanf("%d ", &v[i]);

	selection_sort(v, n);

	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");

}