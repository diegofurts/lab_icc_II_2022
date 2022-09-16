#include <stdio.h>

long long int min(long long int x, long long int y) {
	if (x<y)
		return x;
	else
		return y;
}

int main () {
	
	long long int a, b;
	scanf(" %lld %lld ", &a, &b);

	for (long long int i = min(a,b); 
		i >= 1; i--) {
		long long int resto_a = a%i;
		long long int resto_b = b%i;
		if (resto_b==0 && resto_a==0) {
			printf("%lld\n", i);
			return 0;
		}
	}

	return 0;

}