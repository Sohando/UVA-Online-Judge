#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mx 1000001
int prime[mx];
ll sieve[mx];

void Prime()
{
    sieve[0]=1;
    sieve[1]=1;

    for(ll i=4; i<mx; i+=2) sieve[i] = 1;

    for(ll i=3; i*i<mx; i+=2)
    {

        if(sieve[i]==0)
        {
            for(ll j=i*i; j<mx; j+=(i+i))
            {
                sieve[j] = 1;
            }
        }
    }
}

void dPrime()
{
    ll cou=1;
    prime[0]=0;
    prime[1]=0;
    prime[2]=1;
    for(ll i=3; i<mx; i++)
    {
        ll n=i,c=0;

        while(n!=0)
        {
            c += (n%10);
            n/=10;
        }

        if(sieve[c]==0 && sieve[i]==0)
        {
            prime[i] = ++cou;
        }
        else prime[i] = cou;
    }

}


int main()
{

    Prime();
    ll t,n,m;
    dPrime();

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);

        printf("%lld\n",prime[m]-prime[n-1]);
    }

    return 0;
}
