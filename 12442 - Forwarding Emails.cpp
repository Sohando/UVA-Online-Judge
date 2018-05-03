#include<bits/stdc++.h>
using namespace std;

vector<int> v(50005);
int visited[50005];
int dp[50005];

int dfs(int s)
{
    if(visited[s]) return 0;
    visited[s] = 1;
    
    int _naf = dfs(v[s]);
    
    visited[s] = false;
    return dp[s] = _naf+1;
}

int main()
{
    int how,test,cases=1,x,y;
    scanf("%d",&test);

    while(test--) {
        v.clear();

        scanf("%d",&how);

        for(int i=1;i<=how;i++) {
            scanf("%d %d",&x,&y);
            v[x]=y;
            visited[i]=0;
            dp[i]=0;
        }

        for(int i=1;i<=how;i++) {
            if(!dp[i]) {
                dfs(i);
            }
        }

        int ans=0,mai=0;
        for(int it=1;it<=how;it++) {
            if(dp[it] > mai) {
                mai = dp[it];
                ans = it;
            }
        }

        printf("Case %d: %d\n",cases++,ans);

    }

    return 0;
}
