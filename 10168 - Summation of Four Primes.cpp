#include<bits/stdc++.h>
using namespace std;

const int mx = 10000007;
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

int goldbach(int n) {
        int i;
        for(i=0; Primes[i] <= n; i++) {
                if(foo[n-Primes[i]] == 0) {
                        return Primes[i];
                }
        }
        return -1;
}

void solve() {

        sieve();
        int n;
        while(scanf("%d", &n) == 1) {
              if(n < 8) {
                        printf("Impossible.\n");
                        continue;
              }
              
              if(n & 1) {
                        printf("2 3");
                        n -= 5;
              }
              else {
                        printf("2 2");
                        n -= 4;
              }
              
              int x = goldbach(n);
              
              if(x != -1)
                printf(" %d %d\n", x, n-x);
              else
                printf("Impossible.\n");
        }

}

int main() {

        solve();

        return 0;
}
