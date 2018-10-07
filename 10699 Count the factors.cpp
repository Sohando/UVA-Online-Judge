#include<bits/stdc++.h>
using namespace std;

const int mx = 1000007;
vector< int > Primes;
int foo[mx];

void sieve() {
    int i, j;
    Primes.push_back(2);

    for(i=4; i<mx; i+=2) {
        foo[i] = 1;
    }

    for(i=3; i*i<mx; i+=2) {
        if(foo[i] == 0) {
                Primes.push_back(i);
                for(j=i*i; j<mx; j+=(i+i)) {
                        foo[j] = 1;
                }
        }
    }

    for(i=i; i<mx; i+=2) {
        if(foo[i] == 0) {
                Primes.push_back(i);
        }
    }
}

void Factor(int n) {

        int i, cnt = 0;

        if(n%2 == 0) {
                cnt++;
                while(n > 0 && n%2 == 0) {
                       n /= 2;
                }
        }
        for(i=1; Primes[i]*Primes[i] <= n; i++) {
                if(n % Primes[i] == 0) {
                        cnt++;
                        while(n > 0 && n % Primes[i] == 0) {
                                n /= Primes[i];
                        }
                }
        }
        if( n > 1) {
                cnt++;
        }

        printf("%d\n", cnt);
}

void solve() {

        sieve();
        int n;
        while(scanf("%d", &n) == 1, n) {
                printf("%d : ", n);
                Factor(n);
        }

}

int main() {

        solve();

        return 0;
}

