#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    scanf("%d",&test);
    getchar();

    char s;

    while(test--){

        int m=0,a=0,r=0,g=0,i=0,t=0;
        while(scanf("%c",&s)==1 && s!='\n'){
            if(s=='M') m++;
            else if(s=='A') a++;
            else if(s=='R') r++;
            else if(s=='G') g++;
            else if(s=='I') i++;
            else if(s=='T') t++;
        }

        int pizza = 0;
        while(m>=1 && a>=3 && r>=2 && g>=1 && i>=1 && t>=1){
            pizza++;

            m--;
            i--;
            g--;
            t--;
            a-=3;
            r-=2;
        }

        printf("%d\n",pizza);

    }

    return 0;
}
