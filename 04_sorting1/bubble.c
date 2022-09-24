#include <stdio.h>

void bubble_sort(int *v, int n) {

	int i, j, aux;
	char mudou;

	for (i = n-1; i > 0; i--) {
	
		// for (j = 0; j < i; j++) {

		// 	if (v[j] > v[j+1]) {
		// 		aux = v[j];
		// 		v[j] = v[j+1];
		// 		v[j+1] = aux;
		// 	}
			
		// }

		mudou = 0;
		for (j = 0; j < i; j++) {

			if (v[j] > v[j+1]) {
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				mudou = 1;
			}
			
		}
		if (!mudou)
			break;

	}
}

int main() {

	int n = 1000000;
	int v[n];
	int a;

	for (int i = 0; i < n; i++)
		scanf("%d ", &v[i]);

	bubble_sort(v, n);

	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");

}