#include<bits/stdc++.h>
using namespace std;

#define valid(i,j,n,m) (i>=0 && i<n && j>=0 && j<m)
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};

//int fx[] = {0,0,1,-1,-1,1,-1,1};
//int fy[] = {-1,1,0,0,1,1,-1,-1};

char Map[100][100];
int co=0;

void dfs(int i,int j,int n,int m,char ch) {

    Map[i][j] = '.';
    co++;

    for(int k=0;k<4;k++) {

        int x = i+fx[k];
        int y = j+fy[k];

        if(y>=m) {
            y=0;
        }
        else if(y<0) {
            y=m-1;
        }

        if(valid(x,y,n,m) && Map[x][y]==ch) {
            dfs(x,y,n,m,ch);
        }
    }
}

int main() {

    int n,m;

    while( cin >> n >> m ) {

        getchar();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> Map[i][j];
            }
            getchar();
        }

        int a,b;
        cin >> a >> b;
        getchar();

        char ch = Map[a][b];
        dfs(a,b,n,m,ch);

        int counter=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(Map[i][j]==ch) {

                    co=0;
                    dfs(i,j,n,m,ch);
                    counter = max(co,counter);
                }
            }
        }
        cout << counter << endl;
    }

    return  0;
}
