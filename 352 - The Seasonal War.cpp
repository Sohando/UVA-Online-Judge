#include<bits/stdc++.h>
using namespace std;

#define valid(i,j,n) i>=0 && i<n && j>=0 && j<n
int fx[] = {1,-1,-1,1,0,0,1,-1};
int fy[] = {1,-1,1,-1,1,-1,0,0};

char War[26][26];
int c=0;

void dfs(int i,int j,int n) {

    War[i][j] = '0';

    for( int k=0;k<8;k++ ) {

        int x = i+fx[k];
        int y = j+fy[k];

        if(valid(x,y,n) && War[x][y]=='1') {
            dfs(x,y,n);
        }
    }
}
int main() {

    int n,cas=1;

    while( scanf("%d",&n) ==1 ) {

        for( int i=0;i<n;i++ ) {

            for( int j=0;j<n;j++ ) {
                cin >> War[i][j];
            }
            getchar();
        }

        c=0;
        for( int i=0;i<n;i++ ) {
            for( int j=0;j<n;j++ ) {
                if(War[i][j]=='1') {
                    c++;
                    dfs(i,j,n);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",cas++,c);
    }

    return 0;
}
