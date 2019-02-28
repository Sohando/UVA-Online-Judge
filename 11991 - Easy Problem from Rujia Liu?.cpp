#include<bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	int x, j, k;

	while(scanf("%d %d", &n, &m) == 2) {

		// int A[n+7];
		map<int, vector<int>>mv;

		for(int i=1; i<=n; i++) {
			scanf("%d", &x);
			mv[x].push_back(i);
		}

		while(m--) {
			scanf("%d %d", &j, &k);

			if(mv[k].size() < j) {
				printf("0\n");
			}
			else {
				x = mv[k][j-1];
				printf("%d\n", x);
			}
		}
	}

	return 0;
}
