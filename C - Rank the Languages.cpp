#include<bits/stdc++.h>
using namespace std;

char World[1000][1000];

bool valid(int i,int j,int h,int w) {

    if(i>=0 && i<h && j>=0 && j<w) {
        return true;
    }
    return false;
}

void dfs(int i,int j,int h,int w,char ch) {
    World[i][j] = '*';

    if(valid(i+1,j,h,w) && World[i+1][j]==ch) {
        dfs(i+1,j,h,w,ch);
    }
    if(valid(i-1,j,h,w)&& World[i-1][j]==ch) {
        dfs(i-1,j,h,w,ch);
    }
    if(valid(i,j+1,h,w) && World[i][j+1]==ch) {
        dfs(i,j+1,h,w,ch);
    }
    if(valid(i,j-1,h,w) && World[i][j-1]==ch) {
        dfs(i,j-1,h,w,ch);
    }
}

int main() {

    int n;
    int h,w;

    cin >> n;
    for(int cas=1;cas<=n;cas++) {

        for(int i=0;i<1000;i++) {
            for(int j=0;j<1000;j++) {
                World[i][j] = '*';
            }
        }
        cin >> h >> w;
        getchar();
        map< char,int > M;

        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                cin >> World[i][j];
            }
            getchar();
        }

        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                if(World[i][j]!='*') {
                    M[World[i][j]]++;
                    dfs(i,j,h,w,World[i][j]);
                }
            }
        }

        cout << "World #" << cas << endl;
        vector< pair<int,char> > V;

        for(auto it=M.begin();it!=M.end();it++) {
            V.push_back({it->second,it->first});
        }


        int sz = V.size();

        for(int i=0;i<sz-1;i++) {

            int j=i;

            while(j>=0) {

                if( V[j].first<V[j+1].first ) {
                    swap(V[j],V[j+1]);
                }
                else if( V[j].first==V[j+1].first) {
                    if(V[j].second>V[j+1].second) {
                        swap(V[j],V[j+1]);
                    }
                }
                j--;
            }
        }

        for(int i=0;i<sz;i++) {
            cout << V[i].second << ": " << V[i].first;

            if(i!=sz-1) {
                cout << endl;
            }
        }

        if(sz!=0) {
            cout << endl;
        }
    }

    return 0;
}
