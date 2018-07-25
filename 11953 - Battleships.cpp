#include<bits/stdc++.h>
using namespace std;
char Array[105][105];
bool flag=false;

bool valid(int i,int j,int n) {

    if(i>=0 && i<n && j>=0 && j<n) {
        return true;
    }
    return false;
}

void dfs_verti(int i,int j,int n) {

    Array[i][j] = '#';
 
    if(valid(i+1,j+1,n) && Array[i+1][j+1]=='x' || Array[i+1][j+1]=='@') {
        dfs_verti(i+1,j+1,n);
    }

    if(valid(i-1,j+1,n) && Array[i-1][j+1]=='x' || Array[i-1][j+1]=='@') {
        dfs_verti(i-1,j+1,n);
    }

    if(valid(i-1,j-1,n) && Array[i-1][j-1]=='x' || Array[i-1][j-1]=='@') {
        dfs_verti(i-1,j-1,n);
    }

    if(valid(i+1,j-1,n) && Array[i+1][j-1]=='x' || Array[i+1][j-1]=='@') {
        dfs_verti(i+1,j-1,n);
    }

    return;
}

void dfs_hori(int i,int j,int n) {

    Array[i][j] = '#';

    if(valid(i,j+1,n) && Array[i][j+1]=='x' || Array[i][j+1]=='@') {
        dfs_hori(i,j+1,n);
        flag=true;
    }
    if(valid(i,j-1,n) && Array[i][j-1]=='x' || Array[i][j-1]=='@') {
        dfs_hori(i,j-1,n);
        flag=true;
    }
    if(valid(i-1,j,n) && Array[i-1][j]=='x' || Array[i-1][j]=='@') {
        dfs_hori(i-1,j,n);
        flag=true;
    }
    if(valid(i+1,j,n) && Array[i+1][j]=='x' || Array[i+1][j]=='@') {
        dfs_hori(i+1,j,n);
        flag=true;
    }

    return;
}

int main(){

    int test;
    cin >> test;

    for(int cas=1,n;cas<=test;cas++) {

        cin >> n;
        getchar();

        for(int i=0;i<105;i++) {
            for(int j=0;j<105;j++) {
                Array[i][j] = '.';
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> Array[i][j];
            }
            getchar();
        }

        int c=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                
                if(Array[i][j]=='x') {
                    dfs_hori(i,j,n);
                    
                    if(flag==false) {
                        dfs_verti(i,j,n);
                        flag=false;
                    }
                    c++;
                    
                }
            }
        }

        cout << "Case " << cas << ": " << c << endl;
    }

    return 0;
}
