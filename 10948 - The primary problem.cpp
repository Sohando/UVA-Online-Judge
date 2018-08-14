#include<bits/stdc++.h>
using namespace std;

#define mx  1000007
map< int, pair< int,int >  > ans;
bool tr[mx];

int prime[mx];
vector< int > pr;

void sieve() {

    prime[0] = 1;
    prime[1] = 1;
    pr.push_back(2);
    for( int i=4;i<mx;i+=2 ) {
        prime[i] = 1;
    }

    for( int i=3;i*i<mx;i+=2 ) {
        if( !prime[i] ) {
            for( int j=i*i;j<mx;j+=(i+i) ) {
                prime[j] = 1;
            }
        }
    }

    for( int i=3;i<mx;i+=2 ) {
        if( !prime[i] ) {
            pr.push_back(i);
        }
    }

    for( int i=3;i<1000007;i++ ) {
        int j=0;
        bool foo=false;
        while( pr[j]*pr[j]<=i+5 ) {
            if( !prime[i-pr[j]] ) {
                ans[i]= {pr[j],i-pr[j]};
                tr[i] = true;
                foo=true;
                break;
            }
            j++;
        }
        if( !foo ) {
            tr[i] = false;
        }
    }
}

int main() {

    sieve();
   int n;
    while( scanf("%d",&n)==1,n ) {
        printf("%d:\n",n);
        if( tr[n]==true ) {
            cout << ans[n].first<<"+"<<ans[n].second<<endl;
        }else {
          puts("NO WAY!");
        }
    }

    return 0;
}
