#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
		ios_base::sync_with_stdio(0), cin.tie(0);
		ll n, Arr[30], mul, ans, neg, cas = 1, l, y;
		while(cin >> n) {
				for(int i = 0; i < n; i++) {
						cin >> Arr[i];
				}

				ans = -1;
				for(int i = 0; i < n; i++) {		///	2 6 -4 9
						neg = 0, mul = 1, l = 0, y = 0;
						for(int j = i; j < n; j++) {
								if(Arr[j] < 0) {
										neg++;
										if(neg % 2 == 0) {
												for(int k = l; k <= j; k++) {
														mul *= Arr[k];
												}
												neg = 0, y = 1;
										}
										if(neg == 1) {
												l = j;
										}
								}
								else if(Arr[j] == 0) {
									break;
								}
								else if(neg == 0) {
										y = 1;
										mul *= Arr[j];
								}
						}
						if(y == 1)
							ans = max(ans, mul);
				}
				cout << "Case #"<< cas++ << ": The maximum product is "<< (ans == -1 ? 0 : ans) << "." << endl << endl;
		}
		return 0;
}
