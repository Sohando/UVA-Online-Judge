#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int coins[] = {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
ll dp[22][10007];

ll change(int idx, int amount) {
	
	if(idx == 21) {
		if(!amount) return 1;
		return 0;
	}
	if(!amount) return 1;

	if(dp[idx][amount] != -1) {
		return dp[idx][amount];
	}
	
	ll call1 = 0, call2;
	int v = amount - coins[idx];
	
	if(v >= 0) {
		call1 = change(idx, v);
	}
	call2 = change(idx + 1, amount);
	
	return dp[idx][amount] = (call1 + call2);
}

void solve() {
	
	int n;
	memset(dp, -1, sizeof(dp));
	while(scanf("%d", &n) == 1) {
		
		printf("%lld\n", change(0, n));
	}
}
int main() {
	solve();
	return 0;
}
