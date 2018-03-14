#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);

    int test,r,c,m,n,cases=1,i,j;
    int ch[26];
    char A;

    cin>>test;
    while(test--)
    {
        cin>>r>>c>>m>>n;
        getchar();

        memset(ch,0,sizeof(ch));
        int maxi = 0;

        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                scanf("%c",&A);
                //cin>>A;

                ch[A-'A']++;

                if(ch[A-'A']>maxi)
                {
                    maxi = ch[A-'A'];
                }

            }
        }

        int ans=0;
        for(i=0; i<26; i++)
        {

            if(ch[i]==maxi)
            {
                ans += (ch[i]*m);
            }
            else
            {
                ans+= (ch[i]*n);
            }

        }

        printf("Case %d: %d\n",cases++,ans);
    }

    return 0;
}
