#include<bits/stdc++.h>
using namespace std;

#define valid(i,j) i>=1 && i<=8 && j>=1 && j<=8

int fx[] = {-2,-2,2,2,-1,-1,1,1};
int fy[] = {-1,1,-1,1,2,-2,2,-2};

map< pair<int,int>, int > dist;
map < pair<int,int>, bool > vis;

void bfs( int i,int j,int k,int l ) {

    queue< pair<int,int> >Q;
    pair<int,int> P1,P2;

    P1 = make_pair(i,j);
    Q.push( P1 );
    dist[ P1 ] = 0;
    vis[ P1 ] = true;

    while(!Q.empty()) {
        int u = Q.front().first;
        int v = Q.front().second;
        Q.pop();

        P1 = make_pair(u,v);

        for( int n=0;n<8;n++ ) {
            int o = u+fx[n];
            int p = v+fy[n];
            P2 = make_pair(o,p);

            if(valid(o,p) && !vis[ P2 ]) {

                vis[ P2 ] = true;
                dist[ P2 ] = dist[ P1 ] + 1;
                Q.push( P2 );
            }
        }

        if(u==k && v==l) {
            return;
        }
    }
}

int main() {

    string s,t;

    while( cin >> s >> t ) {
        getchar();

        int a = s[0]-'a'+1;
        int b = s[1]-'0';

        int c = t[0]-'a'+1;
        int d = t[1]-'0';
        
        bfs(a,b,c,d);

        cout << "To get from " <<s<< " to "<<t<< " takes " <<dist[ {c,d} ] << " knight moves." << endl;

        vis.clear();
        dist.clear();
    }

    return 0;
}
