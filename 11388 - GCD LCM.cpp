
#include <stdio.h>

int GCD(int a,int b)
{
    int rem = b%a;

    if(rem==0)
    {
        return a;
    }

    return GCD(rem,a);
}

int main()
{

    int t,i,j,gcd,lcm,a,b;

    scanf("%d",&t);

    while(t--)
    {
        int flag=0,a=0,b=0,mul=0;

        scanf("%d %d",&gcd,&lcm);

        if(GCD(gcd,lcm)==gcd)
        {
            printf("%lld %lld\n",gcd,lcm);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}


/*
#include<stdio.h>

int main()
{

    int t,g,l;

    scanf("%d",&t);

    while(t--) {

        scanf("%d %d",&g,&l);

        if(l%g) {
            printf("-1\n");

        }
        else {
            printf("%d %d\n",g,l);
        }
    }
}
*/
