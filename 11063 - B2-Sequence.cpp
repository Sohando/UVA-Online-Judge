#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("output.txt","w",stdout);

    int n,diff,cases=1;

    while(scanf("%d",&n)==1)
    {
        int a[n+1],flag=0;
        a[0]=0;
        map <int,bool> par;

        for(int i=1; i<=n; i++)
        {

            scanf("%d",&a[i]);

            if(a[i]<=a[i-1])
            {

                flag=1;
            }

        }
        if(!flag)
        {
            for(int i=1; i<=n; i++)
            {

                for(int j=i; j<=n; j++)
                {

                    if(par[a[j]+a[i]])
                    {

                        flag=1;
                        break;
                    }
                    par[a[j]+a[i]] = true;

                    //cout << a[i] + a[j] <<endl;
                }
                if(flag) break;
            }

        }

        if(flag)
        {

            printf("Case #%d: It is not a B2-Sequence.\n\n",cases++);
        }
        else
        {

            printf("Case #%d: It is a B2-Sequence.\n\n",cases++);
        }

    }

    return 0;
}
