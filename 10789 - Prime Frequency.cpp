#include<bits/stdc++.h>
using namespace std;

int prime[1000001];
void sieve()
{
    prime[0] = 1;
    prime[1] = 1;

    for(int i=4; i<1000000; i+=2) prime[i] = 1;

    for(int i=3; i*i<1000000; i+=2)
    {

        if(prime[i]==0)
        {
            for(int j=i*i; j<1000000; j+=i+i)
            {
                prime[j] = 1;
            }
        }
    }
}


int main()
{
    sieve();

    int arra[77];
    char c;
    int test,cases=1;

    scanf("%d",&test);
    getchar();

    while(test--)
    {

        memset(arra,0,sizeof(arra));
        while(scanf("%c",&c)==1 && c!='\n')
        {
            arra[c-48]++;
        }

        int flag=1;
        printf("Case %d: ",cases++);
        for(int i=0; i<76; i++)
        {
            if(prime[arra[i]]==0)
            {
                printf("%c",i+48);
                flag=0;
            }
        }
        if(flag)
        {
            printf("empty");
        }
        printf("\n");
    }

    return 0;
}
