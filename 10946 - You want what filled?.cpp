#include<bits/stdc++.h>
using namespace std;

char Hole[55][55];
int c=0;

bool cmp(pair<int,char>A, pair<int,char>B) {

    if(A.first==B.first) {
        return A.second<B.second;
    }

    return A.first>B.first;
}

bool valid(int i,int j,int n,int m) {

    if(i>=0 && j>=0 && i<n && j<m ) {
        return true;
    }
    return false;
}

void dfs(int i,int j,int h,int w,char ch) {

    Hole[i][j]='*';
    c++;

    if(valid(i+1,j,h,w) && Hole[i+1][j]==ch) {
        //c++;
        dfs(i+1,j,h,w,ch);
    }
    if(valid(i-1,j,h,w)&& Hole[i-1][j]==ch) {
        //c++;
        dfs(i-1,j,h,w,ch);
    }
    if(valid(i,j+1,h,w) && Hole[i][j+1]==ch) {
        //c++;
        dfs(i,j+1,h,w,ch);
    }
    if(valid(i,j-1,h,w) && Hole[i][j-1]==ch) {
        //c++;
        dfs(i,j-1,h,w,ch);
    }

}

int main() {

    int n,m,t=1;

    while(cin >> n >> m ) {
        getchar();

        if(n==0 && m==0) {
            break;
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> Hole[i][j];
            }
            getchar();
        }

        vector< pair<int,char> > V;
   
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(Hole[i][j]!='.' && Hole[i][j]!='*') {

                    c=0;
                    char cha = Hole[i][j];
                    dfs(i,j,n,m,Hole[i][j]);
                    V.push_back({c,cha});
                }
            }
        }
        sort(V.begin(),V.end(),cmp);

        int Vs=V.size();
        cout << "Problem " << t++ << ":" << endl;
        for(int j=0;j<Vs;j++) {
            cout << V[j].second << " " << V[j].first << endl;
        }
    }
    return 0;
}
