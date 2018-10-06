#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t, n;
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &n);
		
		int Arr[n];
		for(int i=0; i<n; i++) {
			scanf("%d", &Arr[i]);
		}
		
		int ans = -INT_MAX;
		int maxv = ans;
		for(int i=0; i<n-1; i++) {
			maxv = max(Arr[i], maxv);
			ans = max(maxv-Arr[i+1], ans);
		}
		
		printf("%d\n", ans);
	}
	return 0;
}
