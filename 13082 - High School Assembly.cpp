#include <stdio.h>
#include<limits.h>
#include<algorithm>

int main() {
	int t;
	scanf("%d", &t);
	
	int n, cas = 1, i;
	while(t--) {
		printf("Case %d: ", cas++);
		scanf("%d",&n);
		int H[n], mn = INT_MAX;
		
		for(i=0; i<n; i++) {
			scanf("%d", &H[i]);
			mn = std::min(mn, H[i]);
		}
		
		int N[n], T[n];
		for(i=0; i<n; i++) {
			N[i] = abs(mn - H[i]);
			T[i] = N[i];
		}
		
		std::sort(T, T+n);
		int j = 0;
		for(i=0; i<n; i++) {
			if(T[j] == N[i]) {
				j++;
			}
		}
		
		printf("%d\n", n-j);
	}
	return 0;
}
