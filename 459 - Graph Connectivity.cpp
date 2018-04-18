#include <bits/stdc++.h>
using namespace std;

vector <int> v[100];
bool visited[100];

void dfs(int source)
{
	stack <int>  st;
	st.push(source);

	visited[source] = true;
	while(!st.empty()) {
		int u = st.top();
		st.pop();

		for(int i=0;i<v[u].size();i++) {
			if(!visited[v[u][i]]) {

				st.push(v[u][i]);
				visited[v[u][i]] = true;
			}
		}
	}
}

int main() {

	int test,x,y,g=0;
	char ch;
	string str;

        cin >> test;
		getchar();

		for(int k = 1;k <= test; k++) {

            if(g==1) cout << endl;

			cin >> ch;
            getchar();

			for(int i=0;i<=100;i++) {
				v[i].clear();
				visited[i] = false;
			}

			while(1) {

                if(!getline(cin,str) || str.empty()) break;

				x = str[0] - 'A';
				y = str[1] - 'A';

				v[x].push_back(y);
				v[y].push_back(x);

			}
			int counter = 0;
			for(char i='A';i<=ch;i++) {

				if(!visited[i-'A']) {

					counter++;
					dfs(i-'A');
				}
			}
			cout << counter << endl;
			g=1;
		}

	return 0;
}

