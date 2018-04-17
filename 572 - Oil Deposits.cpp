#include<bits/stdc++.h>
using namespace std;

char a[200][200];

void dfs(int x,int y)
{

    stack < pair<int,int> > st;
    st.push(make_pair(x,y));

    while(!st.empty()) { 

        int i = st.top().first;
        int j = st.top().second;

        a[i][j] = '*';

        st.pop();

        if(a[i+1][j+1] != '*') {
            st.push(make_pair(i+1,j+1));
            
        }
        if(a[i+1][j-1] != '*') {
            st.push(make_pair(i+1,j-1));
           
        }
        if(a[i][j+1] != '*') {
            st.push(make_pair(i,j+1));
            
        }
       if(a[i][j-1] != '*') {
            st.push(make_pair(i,j-1));
           
        }
        if(a[i+1][j] != '*') {
            st.push(make_pair(i+1,j));
           
        }
        if(a[i-1][j] != '*') {
            st.push(make_pair(i-1,j));
            
        }

        if(a[i-1][j+1] != '*') {
            st.push(make_pair(i-1,j+1));
            
        }
        if(a[i-1][j-1] != '*') {
            st.push(make_pair(i-1,j-1));
        }
    }


}
int main()
{
    int n,m;
    while(cin >> n >> m ,n ,m) {
    
        getchar();

        for(int i=0;i<102;i++) {
            for(int j=0;j<102;j++) {
                a[i][j] = '*';
            }
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin >> a[i][j];
            }
            getchar();
        }

        int counter = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {

                if(a[i][j]=='@') {
                    counter++;

                    dfs(i,j);
                }
            }
        }

        cout << counter << endl;
    }

    return 0;
}
