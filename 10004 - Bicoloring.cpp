#include<bits/stdc++.h>
using namespace std;

vector <int> adj[1000];
int visited[1000];
int colour[1000];

int BFS(int source)
{
    queue <int> q;
    q.push(source);
    visited[source] = 1;
    colour[source] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i=0;i<adj[u].size();i++) {
            if(!visited[adj[u][i]]) {

                visited[adj[u][i]] = 1;

                if(colour[u]==1) {
                    colour[adj[u][i]] = 2;
                }
                else {
                    colour[adj[u][i]] = 1;
                }

                q.push(adj[u][i]);
            }
            else if(colour[adj[u][i]]==colour[u]) {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int node,edge,x,y;

    while(cin >> node,node) {

        for(int i=0;i<node;i++) {
            adj[i].clear();
            visited[i] = 0;
            colour[i] = 0;
        }

        cin >> edge;

        for(int i=0;i<edge;i++) {
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        if(BFS(0)) {
            cout << "BICOLORABLE." << endl;
        }
        else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}
