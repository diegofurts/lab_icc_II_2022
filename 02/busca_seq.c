#include <stdio.h>

int busca(int* vet, int n, int q) {

	for (int i=0; i < n; i++) {
		if (vet[i] == q)
			return i;
	}

	return -1;

}

int main() {

	int n, nq, q;

	scanf("%d ", &n);

	int vet[n];
	for (int i = 0; i < n; i++)
		scanf("%d ", &vet[i]);

	scanf("%d ", &nq);
	for (int i = 0; i < nq; i++) {
		scanf("%d ", &q);
		printf("%d\n", busca(vet, n, q));
	}

}