/**
	population [0,1,2,3]
	0 -> " ";
	1 -> ".";
	2 -> "x";
	3 -> "W"; 
**/
#include <bits/stdc++.h>
using namespace std;

map <char, int> Mp;

void solve() {
	Mp['.'] = 1; Mp['x'] = 2; Mp['W'] = 3; Mp[' '] = 0;
	int n, a = 0;
	int A[11];

	cin >> n;

	while(n--) {

		if(a) {
			printf("\n");
		}
		a = 1;
		for(int i = 0; i < 10; ++i) {
			cin >> A[i];
		}

		char temp[55][45];
		for(int i = 0; i < 50; ++i) {
			for(int j = 0; j < 40; ++j) {
				temp[i][j] = ' ';
				//cout << Mp[temp[i][j]];
			}
			//cout << endl;
		}

		temp[0][19] = '.';
		for(int i = 0; i < 40; ++i) {
			if(i == 19) {
				printf(".");
			}
			else {
				printf(" ");
			}
		}
		cout << endl;

		for(int i = 1; i < 50; ++i) {
			for(int j = 0; j < 40; ++j) {
				// if(j == 0 || j == 39) {
				// 	printf(" ");
				// }
				// else {
					int ans = Mp[temp[i-1][j]]+ Mp[temp[i-1][j-1]] + Mp[temp[i-1][j+1]];
					ans = A[ans];
					if(ans == 0) {
						printf(" ");
						temp[i][j] = ' ';
					}
					else if(ans == 1) {
						printf(".");
						temp[i][j] = '.';
					}
					else if(ans == 2) {
						printf("x");
						temp[i][j] = 'x';
					}
					else {
						printf("W");
						temp[i][j] = 'W';
					}
				// }
			}
			printf("\n");
		}
		// printf("\n");
	}
	return;
}
int main() {
	
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
