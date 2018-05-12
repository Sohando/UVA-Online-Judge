#include<bits/stdc++.h>
using namespace std;
vector<int> v[105];
bool vis[105];
int lev[105];

double sum=0.0;

void bfs(int s) {

    //vis.clear();
    //lev.clear();

    for(int i=0;i<105;i++) {
        vis[i] = false;
        lev[i] = 0;
    }

    queue <int> Q;
    Q.push(s);
    vis[s] = true;

    lev[s] = 0;

    while(!Q.empty()) {

        int u = Q.front();
        Q.pop();

        for(int i=0;i<v[u].size();i++) {

            if(!vis[v[u][i]]) {
                Q.push(v[u][i]);
                vis[v[u][i]] = true;
                lev[v[u][i]] = lev[u]+1;

                sum += lev[v[u][i]];
            }
        }
    }
}

int main()
{
    int x,y,n,m,cases=1;
    set<int> st;

    while(scanf("%d %d",&x,&y)==2 && x!=0 && y!=0) {
        
        st.clear();
        //v.clear();

        for(int i=0;i<105;i++) {
            v[i].clear();
        }
        
        
        st.insert(x);
        st.insert(y);

        v[x].push_back(y);

        while(scanf("%d %d",&n,&m)==2 && n!=0 && m!=0) {

            st.insert(n);
            st.insert(m);

            v[n].push_back(m);
        }

        sum=0.0;
        for(auto it=st.begin();it!=st.end();it++) {

            bfs(*it);
        }
        double sz = st.size();
        double sol = sum / ( sz*(sz-1) );
        printf("Case %d: average length between pages = %.3f clicks\n",cases++,sol);
    }

    return 0;
}
