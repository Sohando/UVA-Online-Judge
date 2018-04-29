#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,p;
	string s;
	int moot = 0;
	map <string,int> ma;
	
	cin >> n >> m;
	getchar();
	
	while(n--) {
			
		cin >> s >> p;
		ma[s] = p;
	}
	getchar();
	
	int i = 1;
	while(i<=m) {
		moot = 0;
		while(cin >> s) {
			
			if(s=="."){
				++i;
				break;
			}
			else moot += ma[s];
		}
		cout << moot << endl;
	}
	return 0;
}
