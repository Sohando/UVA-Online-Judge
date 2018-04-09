#include<stdio.h>

int G[10000][10000];

int GCD(int i,int j)
{

    if(G[i][j]!=0)
    {
        return G[i][j];
    }

    int rem  = j%i;

    if(rem==0)
    {
        G[i][j] =  i;
        return G[i][j];
    }

    else
    {
        G[i][j] =  GCD(rem,i);
        return G[i][j];
    }


}

int main()
{
    int G=0,N,i,j;

    while(scanf("%d",&N)==1 && N)
    {

        G = 0;
        for( i=1; i<=N; i++)
        {
            for( j=i+1; j<=N; j++)
            {

                G += GCD(i,j);
            }
        }

        printf("%d\n",G);
    }

    return 0;
}
