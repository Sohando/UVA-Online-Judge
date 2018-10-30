#include <iostream>
using namespace std;

typedef int ul;
ul bigmod(ul x, ul y, ul n) {
	x %= n;
	ul res = 1;
	while(y > 0) {
		if(y & 1) {
			res = res * x % n;
		}
		x = x * x % n;
		y >>= 1;
	}
	return res;
}
void solve() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ul t, x, y, n;
	
	while(cin >> t, t) {
		
		for(int i = 0; i < t; i++) {
			cin >> x >> y >> n;
			cout << bigmod(x, y, n) << endl;
		}
	}
}
int main() {
	solve();
	return 0;
}
