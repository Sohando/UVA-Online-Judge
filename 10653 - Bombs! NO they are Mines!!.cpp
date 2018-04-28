#include<bits/stdc++.h>
using namespace std;

char arr[1001][1001];
int row,col;
bool visited[1001][1001];
int level[1001][1001];


void bfs(int i, int j,int k,int l) {

    queue < pair<int,int> > q;

    pair<int,int> temp = make_pair(i,j);

    q.push(temp);
    visited[i][j] = true;
    level[i][j] = 0;

    while(!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;

        q.pop();

        if( u+1<=row && !visited[u+1][v] && arr[u+1][v]=='.') {
            q.push(make_pair(u+1,v));
            level[u+1][v] = level[u][v] + 1;
            visited[u+1][v] = true;

        }

        if( v+1<=col && !visited[u][v+1] && arr[u][v+1]=='.') {
            q.push(make_pair(u,v+1));
            level[u][v+1] = level[u][v] + 1;
            visited[u][v+1] = true;
        }

        if( u-1>=0 && !visited[u-1][v] && arr[u-1][v]=='.') {
            q.push(make_pair(u-1,v));
            level[u-1][v] = level[u][v] + 1;
            visited[u-1][v] = true;
        }

        if( v-1>=0 && !visited[u][v-1] && arr[u][v-1]=='.') {
            q.push(make_pair(u,v-1));
            level[u][v-1] = level[u][v] + 1;
            visited[u][v-1] = true;
        }

        if(visited[k][l]) {
            printf("%d\n",level[k][l]);
            return;
        }
    }
}

int main()
{

   int rows,a,b,x,y,w,u,num;

    while(scanf("%d %d",&row,&col)==2) {
        if(row==0 && col==0) break;

        for(int i=0;i<=row;i++) {
            for(int j=0;j<=col;j++) {
                arr[i][j] = '.';
                visited[i][j] = false;
                level[i][j] = 0;
            }
        }

        scanf("%d",&rows);
        while(rows--) {

            scanf("%d %d",&w,&u);
            while(u--) {
                scanf("%d",&num);
                arr[w][num] = '*';
           }

        }

        scanf("%d %d",&a,&b);
        scanf("%d %d",&x,&y);


        bfs(a,b,x,y);
    }

    return 0;
}
