#include <bits/stdc++.h>
using namespace std;

void solve() {
	int t;
	scanf("%d", &t);
	int cs = 1;
	
	while(t--) {
		printf("Case #%d\n", cs++);
		int n;
		scanf("%d", &n);
		getchar();
		int arr[n][n];
		int temp[n][n];
		char aa[n][n];
		// string aa;
		
		// for(int i = 0; i < n; ++i) {
		// 	cin >> aa;
		// 	for(int j = 0; j < n; ++j) {
		// 		arr[i][j] = aa[j]-'0';
		// 	}
		// }
		for(int i = 0; i  < n; ++i) {
			for(int j = 0; j < n; ++j) {
				scanf("%c", &aa[i][j]);
			}
			getchar();
		}
		for(int i = 0; i  < n; ++i) {
			for(int j = 0; j < n; ++j) {
				arr[i][j] = aa[i][j] - '0';
			}
			// getchar();
		}

		int m;
		scanf("%d", &m);
		

		string str;
		while(m--) {

			// getline(cin, str);
			getchar();
			cin >> str;

			if(str == "transpose") {
				// transpose(&arr);
				// cout << "Dukci" << endl;
				for(int i = 0; i < n; ++i) {
					for(int j = 0; j < n; ++j) {			
						temp[i][j] = arr[j][i];
					}
				}
				for(int i = 0; i < n; ++i) {
					for(int j = 0; j < n; ++j) {		
						arr[i][j] = temp[i][j];
					}
				}
			}	
			else if(str == "col") {
				int num1 ;//= str[4] - '0';
				int num2 ;//= str[6] - '0';

				cin >> num1 >> num2;
				num2 -= 1, num1 -= 1;
				int temp;
				for(int i = 0; i < n; ++i) {
					temp = arr[i][num1];
					arr[i][num1] = arr[i][num2];
					arr[i][num2] = temp;
				}
			}
			else if(str == "row") {
				
				int num1 ;//= str[4] - '0' - 1;
				int num2 ;//= str[6] - '0' - 1;

				cin >> num1 >> num2;
				num2 -= 1, num1 -= 1;
				int temp;
				for(int i = 0; i < n; ++i) {
					temp = arr[num1][i];
					arr[num1][i] = arr[num2][i];
					arr[num2][i] = temp;
				}
			}
			else if(str == "inc") {
				for(int i = 0; i < n; ++i) {
					for(int j = 0; j < n; ++j) {
						arr[i][j] = (arr[i][j] + 1);
						if(arr[i][j] == 10) arr[i][j] = 0;
					}
				}
			}
			else {
				for(int i = 0; i < n; ++i) {
					for(int j = 0; j < n; ++j) {
						arr[i][j] = (arr[i][j] - 1);
						if(arr[i][j] == -1) arr[i][j] = 9;
					}
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				printf("%d", arr[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
int main() {
	// freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
