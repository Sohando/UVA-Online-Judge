#include<bits/stdc++.h>
using namespace std;

vector <int> v[101];
int visited[101];

stack <int> ans;

void dfs(int source) {

    stack <int> si;
    si.push(source);
    visited[source] = 1;

    while(!si.empty()) {
        int u = si.top();
        si.pop();

        for(int i=0;i<v[u].size();i++) {
            if(!visited[v[u][i]]) {

                dfs(v[u][i]);
            }
        }
        ans.push(u);
    }
}
int main()
{
    int n,m;
    int x,y;

    while(cin >> n >> m) {
        if(n==0 && m==0 ) break;
        for(int i=0;i<101;i++) {
            v[i].clear();
            visited[i]=0;
        }

        while(m--){

            cin >> x >> y;
            v[x].push_back(y);
        }
        for(int i=1;i<=n;i++) {

            if(!visited[i]) {
                dfs(i);
            }
        }
        while(!ans.empty()) {

            cout << ans.top();
            ans.pop();
            if(!ans.empty()) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
