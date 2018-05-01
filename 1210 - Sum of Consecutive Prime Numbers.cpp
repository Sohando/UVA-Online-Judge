#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
int arr[10001];

void _baby()
{

    prime.push_back(2);

    for(int i=4; i<=10000; i+=2) arr[i] = 1;

    for(int i=3; i<=10000; i+=2)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
            for(int j=i*i; j<=10000; j+=i+i)
            {
                arr[j] = 1;
            }
        }
    }
    return;
}

int main()
{

    _baby();

    int n;

    while(scanf("%d",&n)==1,n)
    {
        int _nafsin = 0,_subna;
        if(!arr[n]) _nafsin++;

        for(int j=0; prime[j]<=n/2; j++)
        {
            _subna = 0;
            for(int k=j; prime[k]<=n; k++)
            {

                _subna += prime[k];

                if(_subna==n)
                {
                    _nafsin++;
                    break;
                }
                else if(_subna>n) break;
            }
        }

        printf("%d\n",_nafsin);
    }

    return 0;
}
