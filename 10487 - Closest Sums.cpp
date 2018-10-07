#include <bits/stdc++.h>
using namespace std;
long long Sum[10000007];

int main() {

	int n, m, i, j, cas=1;
	while(1) {
            
        scanf("%d", &n);
        if(n==0) break;

		printf("Case %d:\n", cas++);
		long long Arr[n];
		for(i=0; i<n; i++) {
			scanf("%lld", &Arr[i]);
		}

		long long c = 0;
		for(i=0; i<n-1; i++) {
			for(j=i+1; j<n; j++) {
				Sum[c++] = Arr[i] + Arr[j];
			}
		}
		long long q, ans, ans2;
		scanf("%lld", &m);

		for(j=0; j<m; j++) {

			ans = 1e18, ans2 = 0;
			scanf("%lld", &q);

			for(i=0; i<c; i++) {
				if(abs(q-Sum[i]) < ans) {
                       
					ans = abs(q-Sum[i]);
					ans2 = Sum[i];
				}
			}
			
			printf("Closest sum to %lld is %lld.\n",q, ans2);
		}
		
	}
	return 0;
}

