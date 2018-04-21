#include<bits/stdc++.h>
using namespace std;

int node,ttl,reached;
vector <int> v[100000];
int visited[100000];
set <int> si;
int level[100000];

void bfs()
{
    for(int i=0;i<100000;i++) {
    //        v[i].clear();
            visited[i] = 0;
            level[i] = 0;
    }

    queue <int> q;
    q.push(node);
    visited[node] = 1;
    level[node] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(level[u]>ttl-1) {
            return ;
        }
        for(int i=0;i<v[u].size();i++) {
            if(!visited[v[u][i]]) {

                q.push(v[u][i]);
                visited[v[u][i]] = 1;

                level[v[u][i]] = level[u]+1;


                reached++;

            }
        }
    }
}
int main()
{
    int nc,x,y,cases=1;

    while(cin >> nc,nc) {

        for(int i=0;i<100000;i++) {
            v[i].clear();
            //visited[i] = 0;
        }
        for(int i=0;i<nc;i++) {
            cin >> x >> y;

            v[x].push_back(y);
            v[y].push_back(x);

            si.insert(x);
            si.insert(y);
        }

        while(cin >> node >> ttl) {

            if(node==0 && ttl==0) {
                break;
            }

            reached = 1;
            bfs();
            int dif = si.size() - reached;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases++,dif,node,ttl);

        }
        si.clear();

    }

    return 0;
}
