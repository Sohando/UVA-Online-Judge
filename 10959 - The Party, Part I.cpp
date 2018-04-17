#include<bits/stdc++.h>
using namespace std;
vector <int> vect[500000];
int level[1007];
int visited[1007];

void BFS(int source) {
	
   memset(level,0,sizeof(level));
   memset(visited,0,sizeof(visited));

    queue <int> Q;
    Q.push(source);
    visited[source] = 1;
    level[source] = 0;

    while(!Q.empty()) {

        int u = Q.front();
        Q.pop();

        for(int i=0;i<vect[u].size();i++) {

            if(visited[vect[u][i]]==0) {

                Q.push(vect[u][i]);
                visited[vect[u][i]] = 1;
                level[vect[u][i]] = level[u]+1;
            }
        }
    }

}
int main() {

    int test,p,d,x,y,l=0;

    cin >> test;

    while(test--) {
        
        if(l==1) cout << endl;
        
        cin >> p >> d;
        
        for(int i=0;i<p;i++) {
        	vect[i].clear();
        }

        while(d--) {
            cin >> x >> y;

            vect[x].push_back(y);
            vect[y].push_back(x);
        }

        BFS(0);

        for(int i=1;i<p;i++) {
            cout << level[i] << endl;
        }
        
        l = 1;
    }

    return 0;
}
