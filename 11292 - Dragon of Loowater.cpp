#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);

    long long int n,m;

    while(scanf("%lld %lld",&n,&m)==2,n,m)
    {

        long long int a[n],b[m],l=0,ans=0,i,j;

        for(i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
        }

        for(i=0; i<m; i++)
        {
            scanf("%lld",&b[i]);
        }

        if(m<n)
        {
            printf("Loowater is doomed!\n");
        }
        else
        {
            sort(b,b+m);
            sort(a,a+n);

            int flag=0;
            i=0,j=0;

            while(i<m && j<n){

                if(b[i]>=a[j]){
                    j++;
                    ans+=b[i];
                    l++;
                }

                i++;

                //cout << ans << endl;
            }

            if(l==n)
            {
                printf("%lld\n",ans);
            }
            else
            {
                printf("Loowater is doomed!\n");
            }
        }
    }

    return 0;
}
