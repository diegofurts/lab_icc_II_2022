#include <stdio.h>

void insertion_sort(int *v, int n) {

	int i, j, aux, menor;

	for (i = 1; i < n; i++) {
		
		// for (j = i-1; j >= 0; j--) {

		// 	if (v[j] > v[j+1]) {
		
		// 		aux = v[j+1];
		// 		v[j+1] = v[j];
		// 		v[j] = aux;

		// 	}

		// }

		j = i-1;
		while (j>=0 && v[j] > v[j+1]) {
	
			aux = v[j+1];
			v[j+1] = v[j];
			v[j] = aux;
			j--;

		}

		

	}
}

int main() {

	int n = 1000000;
	int v[n];
	int a;

	for (int i = 0; i < n; i++)
		scanf("%d ", &v[i]);

	insertion_sort(v, n);

	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");

}