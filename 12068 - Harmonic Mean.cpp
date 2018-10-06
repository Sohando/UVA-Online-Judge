#include <stdio.h>

long long gcd(long long a, long long b) {
	
	while(b) {
		b ^= a ^= b ^= a %= b;
	}
	
	return a;
}

int main(void) {

	int t, cas = 1, i;
	scanf("%d", &t);
	while(t--) {
		printf("Case %d: ", cas++);
		
		long long n, ans= 1;
		scanf("%lld", &n);
		long long M[n];
		
		for(i=0; i<n; i++) {
			scanf("%lld", &M[i]);
			ans *= M[i];
		}
		
		long long ans2 = 0;
		for(i=0; i<n; i++) {
			ans2 += ans/M[i];
		}
		
		ans *= n;
		long long x = gcd(ans, ans2);
		
		printf("%lld/%lld\n", ans/x, ans2/x);
		
	}
	return 0;
}
