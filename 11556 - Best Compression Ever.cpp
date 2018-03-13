#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int  m,n,k,y;
    while(scanf("%lld %lld",&m,&n)==2){

        k = pow(2,n+1)-1;
        //y = ceil(log2(m))-1;

        if(k>=m)
        //if(y<=n)
            printf("yes\n");

        else
            printf("no\n");

        //cout << k <<endl;
        //cout<< y << endl;
    }

    return 0;
}
