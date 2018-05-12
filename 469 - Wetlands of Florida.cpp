#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int vis[105][105];
int ans=1;

int row,col;

void dfs(int x,int y)
{

    stack < pair<int,int> > st;
    st.push(make_pair(x,y));
    vis[x][y] = true;

    while(!st.empty())
    {

        int i = st.top().first;
        int j = st.top().second;

        //a[i][j] = 'L';
        //cout << i  << " " << j << endl;

        st.pop();

        if(i>=0 && j>=0 && i+1<row && j+1<col && !vis[i+1][j+1] && a[i+1][j+1] != 'L')
        {
            ans++;
            st.push(make_pair(i+1,j+1));
            vis[i+1][j+1] = true;

        }
        if(i>=0 && j<col && i+1<row && j-1>=0 && !vis[i+1][j-1] && a[i+1][j-1] != 'L')
        {
            ans++;
            st.push(make_pair(i+1,j-1));
            vis[i+1][j-1] = true;

        }
        if(i<row && i>=0 && j+1<col && j>=0 && !vis[i][j+1] &&  a[i][j+1] != 'L')
        {
            ans++;
            st.push(make_pair(i,j+1));
            vis[i][j+1] = true;

        }
        if(i<row && i>=0 && j-1>=0 && j<col && !vis[i][j-1] && a[i][j-1] != 'L')
        {
            ans++;
            st.push(make_pair(i,j-1));
            vis[i][j-1] = true;

        }
        if(i>=0 && i+1<row && j>=0 && j<col && !vis[i+1][j] && a[i+1][j] != 'L')
        {
            ans++;
            st.push(make_pair(i+1,j));
            vis[i+1][j] = true;

        }
        if(i<row && i-1>=0 && j>=0 && j<col && !vis[i-1][j] &&  a[i-1][j] != 'L')
        {
            ans++;
            st.push(make_pair(i-1,j));
            vis[i-1][j] = true;

        }

        if(i<row && i-1>=0 && j+1<col && j>=0 && !vis[i-1][j+1] &&  a[i-1][j+1] != 'L')
        {
            ans++;
            st.push(make_pair(i-1,j+1));
            vis[i-1][j+1] = true;

        }
        if(i<row && i-1>=0 && j-1>=0 && j<col && !vis[i-1][j-1] &&  a[i-1][j-1] != 'L')
        {
            ans++;
            st.push(make_pair(i-1,j-1));
            vis[i-1][j-1]= true;
        }
    }

}



int main()
{

    int t,q=1;
    string s;
    scanf("%d",&t);
    getchar();
    getchar();

    for(int i=0; i<t; i++)
    {

        if(q==0) printf("\n");

        for(int j=0; j<105; j++)
        {
            for(int k=0; k<105; k++)
            {
                a[j][k] = 'L';
                //vis[j][k] = false;
            }
        }
        int k=0,l=0,tem=105;
        col=0;
        row=0;

        while(getline(cin,s) && s!="")
        {
            tem = s.size();

            if(col>tem)
            {
                row = k;

                string t="",u="";
                stringstream sin(s);
                while(sin >> t >> u)
                {

                    int _naf = stoi(t,nullptr,10);
                    int _sin = stoi(u,nullptr,10);

                    for(int n=0; n<=row; n++)
                    {
                        for(int m=0; m<=col; m++)
                        {
                            vis[n][m] = false;
                        }
                    }

                    ans = 1;
                    dfs(_naf-1,_sin-1);

                    cout << ans << endl;
                }
            }

            else
            {
                l=0;
                col = tem;
                while(l<col)
                {
                    a[k][l] = s[l];

                    l++;
                }
                k++;
            }

        }

        q=0;
    }

    return 0;
}
