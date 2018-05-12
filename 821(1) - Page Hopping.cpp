#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[104][104];
    int used[104];
    int x,y,n,m,cases=1;

    while(scanf("%d %d",&x,&y)==2 && x!=0 && y!=0)
    {

        for(int i=0; i<104; i++)
        {
            for(int j=0; j<104; j++)
            {
                a[i][j] = 125;
                //usied[i] = 0;
            }
            used[i]=0;
        }
        a[x][y] = 1;
        used[x] = 1;
        used[y] = 1;

        while(scanf("%d %d",&n,&m)==2 && n!=0 && m!=0)
        {
            a[n][m] = 1;
            used[n] = 1;
            used[m] = 1;
        }

        for(int k=0; k<104; k++)
        {
            for(int i=0; i<104; i++)
            {
                for(int j=0; j<104; j++)
                {
                    //if(used[i] && used[j]) {
                    a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
                    //}
                }
            }
        }

        double sol=0.0,t=0.0;

        for(int i=0; i<104; i++)
        {
            for(int j=0; j<104; j++)
            {

                if(i==j) continue;

                if(used[i] && used[j])
                {
                    sol += a[i][j];
                    t++;
                }
            }
        }

        printf("Case %d: average length between pages = %.3f clicks\n",cases++,sol/t);
    }

    return 0;
}

