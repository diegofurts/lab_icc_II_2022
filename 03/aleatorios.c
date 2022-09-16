#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M_RAND 846515
#define MAX_RAND 1000

//n_random = (a+m)%b
int gera_rand(int a, int m, int b) {
    return (a+m)%b;
}
// no C (na stdlib) tem um a função rand() pra fazer isso
// srand() para configurar uma seed
// usar % na saída do rand, i.e., rand()%b

void bubble_sort(int *v, int n) {
    
    int aux;
    
    for (int i=n-1; i > 0; i--) { // fixando os maiores no fim
        for (int j = 0; j < i; j++) { //empurra o agora maior para a frente
            if (v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void printa_v(int *v, int n) {
    
    for (int i=0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    
    int n = 10;
    int r = time(NULL);
    
    int *v = (int *) malloc(n*sizeof(int));
    
    for (int i=0; i < n; i++) {
        r = gera_rand(r, M_RAND, MAX_RAND);
        v[i] = r;
    }
    
    printa_v(v, n);
    //bubble_sort(v, n);
    qsort(v, n, sizeof(int), cmpfunc);
    printa_v(v, n);

    return 0;
}
