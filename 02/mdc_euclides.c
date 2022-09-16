#include <stdio.h>

long long int mdc(long long int m, 
					long long int n) {
	if (n == 0)
		return m;
	return mdc(n, m % n);
}

int main () {
	
	long long int a, b;
	scanf(" %lld %lld ", &a, &b);

	printf("%lld\n", mdc(a,b));

	return 0;

}