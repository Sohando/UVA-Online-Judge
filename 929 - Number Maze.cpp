#include<bits/stdc++.h>

using namespace std;
int a[1000][1000];
int dist[1000][1000];
set< pair<int, pair<int,int> > > Q;
pair<int,int> p;

void dijkstra(int n,int m)
{
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            dist[i][j] = INT_MAX;
        }
    }

    dist[0][0] = a[0][0];
    Q.insert(make_pair(a[0][0],make_pair(0,0)));

    while(!Q.empty()) {

        p = Q.begin()->second;
        int i = p.first;
        int j = p.second;
        int c = Q.begin()->first;

        auto it = Q.begin();

        Q.erase(it);

        if(i-1>=0) {

            if(dist[i-1][j] > a[i-1][j] + dist[i][j]) {

                if(Q.find(make_pair(a[i-1][j],make_pair(i-1,j)))!=Q.end()) {
                    Q.erase(Q.find(make_pair(a[i-1][j],make_pair(i-1,j))));
                }

                dist[i-1][j] = a[i-1][j] + dist[i][j];
                Q.insert(make_pair(a[i-1][j] + dist[i][j],make_pair(i-1,j)));
            }
        }

        if(i+1<n) {

            if(dist[i+1][j] > a[i+1][j] + dist[i][j]) {

                if(Q.find(make_pair(a[i+1][j],make_pair(i+1,j)))!=Q.end()) {
                    Q.erase(Q.find(make_pair(a[i+1][j],make_pair(i+1,j))));
                }

                dist[i+1][j] = a[i+1][j] + dist[i][j];
                Q.insert(make_pair(a[i+1][j] + dist[i][j],make_pair(i+1,j)));
            }
        }

        if(j-1>=0) {

            if(dist[i][j-1] > a[i][j-1] + dist[i][j]) {

                if(Q.find(make_pair(a[i][j-1],make_pair(i,j-1)))!=Q.end()) {
                    Q.erase(Q.find(make_pair(a[i][j-1],make_pair(i,j-1))));
                }

                dist[i][j-1] = a[i][j-1] + dist[i][j];
                Q.insert(make_pair(a[i][j-1] + dist[i][j],make_pair(i,j-1)));
            }
        }

        if(j+1<m) { 

            if(dist[i][j+1] > a[i][j+1] + dist[i][j]) {

                if(Q.find(make_pair(dist[i][j+1],make_pair(i,j+1)))!=Q.end()) {
    
                    Q.erase(Q.find(make_pair(dist[i][j+1],make_pair(i,j+1))));
                }
                dist[i][j+1] = a[i][j+1] + dist[i][j];
                Q.insert(make_pair(a[i][j+1] + dist[i][j],make_pair(i,j+1)));
            }
        }
    }

    cout  << dist[n-1][m-1] << endl;
    return;
}

int main()
{

    int t;
    int n,m;

    scanf("%d",&t);

    while(t--) {

        scanf("%d %d",&n,&m);

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                scanf("%d",&a[i][j]);
            }
        }

        dijkstra(n,m);
    }

    return 0;
}
