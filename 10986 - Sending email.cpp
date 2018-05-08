#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector< pii > vii;
typedef vector<int> vi;

#define INF 0x3f3f3f3f

vii G[100000];
vi dist;

int dijkastra(int s,int n,int t)
{
    priority_queue< int, vector< pii >, greater< pii > > Q;

    dist.assign(n,INF);
    dist[s] = 0;
    Q.push(make_pair(0,s));

    while(!Q.empty()) {

        int u = Q.top().second;

        Q.pop();

        for(auto &c : G[u]) {
            int node = c.second;
            int cost = c.first;

            if(dist[node]>dist[u]+cost) {

                dist[node] = dist[u] + cost;
                Q.push(make_pair(dist[node],node));
            }
        }
    }

    return dist[t];

}


int main()
{
    //freopen("in.txt","r",stdin);

    int t,n,m,s,d;
    int u,v,c;

    scanf("%d",&t);

    for(int i=1;i<=t;i++) {
        //G = new vii[n+1];

        for(int i=0;i<n;i++) {
            G[i].clear();
        }

        scanf("%d %d %d %d",&n,&m,&s,&d);

        for(int i=0;i<m;i++) {
            scanf("%d %d %d",&u,&v,&c);

            G[u].push_back(make_pair(c,v));
            G[v].push_back(make_pair(c,u));
        }
        int ans = dijkastra(s,n,d);

        if(ans==INF) {
            printf("Case #%d: unreachable\n",i);
        }
        else {
            printf("Case #%d: %d\n",i,ans);
        }

    }
    return 0;
}
