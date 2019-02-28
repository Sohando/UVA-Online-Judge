#include <bits/stdc++.h>
using namespace std;

int parent[50007];

void reset(int n) {
	for(int i=0; i<=n; ++i) {
		parent[i] = i;
	}
}
int root(int x) {
	if(parent[x] == x) {
		return x;
	}
	return parent[x] = root(parent[x]);
}
void unite(int x, int y) {
	parent[root(x)] = root(y);
}
void solve() {
	int n, m;
	int x, y;
	int cas = 1;
	
	while(scanf("%d %d", &n, &m) == 2, (n + m)) {
		// memset(parent, 0, sizeof(parent));
		reset(n);
		for(int i = 0; i < m; ++i) {
			scanf("%d %d", &x, &y);
			unite(x, y);
		}

		set<int>st;
		//m = 0;
		for(int i = 1; i <= n; ++i) {
			parent[i] = root(i);
			st.insert(parent[i]);
			//if(parent[i] == i) {
			//	m++;
			//}
		}

		printf("Case %d: %d\n", cas++, m);
	}
}

int main() {

	solve();
	return 0;
}
