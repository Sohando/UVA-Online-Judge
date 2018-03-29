#include<bits/stdc++.h>
using namespace std;
#define mx 1e9

int main()
{

    long long int n,b,h,w,ans,flag,cost,x;

    while(scanf("%lld %lld %lld %lld",&n,&b,&h,&w)==4){

        ans = mx;
        for(int j=1;j<=h;j++){

            flag=0;
            scanf("%lld",&cost);

            for(int i=0;i<w;i++){

                scanf("%lld",&x);
                if(x>=n){
                    flag=1;
                }
            }

            if(flag==1 && n*cost<=b && n*cost<ans){
                ans = n*cost;
            }

        }
        if(ans==mx) puts("stay home");
        else printf("%lld\n",ans);
    }

    return 0;
}
