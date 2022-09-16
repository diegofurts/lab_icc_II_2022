#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int busca(int* vet, int ini, int fim, int q) {

	if (ini > fim)
		return -1;

	int meio = (ini+fim)/2;

	if (vet[meio] == q)
		return meio;
	else if (vet[meio] < q) 
		return busca(vet, meio+1, fim, q);
	else
		return busca(vet, ini, meio-1, q);

}

int main() {

	int n, nq, q;

	scanf("%d ", &n);

	int vet[n];
	for (int i = 0; i < n; i++)
		scanf("%d ", &vet[i]);

	qsort(vet, n, sizeof(int), cmpfunc);
	/*for (int i = 0; i < n; i++)
		printf("%d ", vet[i]);*/

	scanf("%d ", &nq);
	for (int i = 0; i < nq; i++) {
		scanf("%d ", &q);
		printf("%d\n", busca(vet, 0, n-1, q));
	}

}