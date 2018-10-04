#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll limit = 1e9;
map<int, vector<ll> > Mp;

void fetch() {

    int one, two, three;
    for(ll i=2; i*i<limit; i++) {
        ll ans = i*i;
        int digit = (log10(i*i)+1);
        if( digit%2 == 0 ) {
            if(digit == 2) {
                one = ans%10;
                two = ans/10;
                three = one+two;
                if( three * three == ans ) {
                    Mp[2].push_back(ans);
                }
            }
            else if(digit == 4) {
                one = ans%100;
                two = ans/100;
                three = one+two;
                if( three * three == ans ) {
                    Mp[4].push_back(ans);
                }
            }
            else if(digit == 6) {
              one = ans%1000;
              two = ans/1000;
              three = one+two;
              if( three * three == ans ) {
                  Mp[6].push_back(ans);
              }
            }
            else if(digit == 8) {
                one = ans%10000;
                two = ans/10000;
                three = one+two;
                if( three * three == ans ) {
                    Mp[8].push_back(ans);
                }
            }
        }
        else {
            if(digit == 3) {
                one = ans%100;
                two = ans/100;
                three = one+two;

                if(three*three == ans) {
                    Mp[4].push_back(ans);
                }
             
            }
            if(digit == 5) {
                one = ans%1000;
                two = ans/1000;
                three = one+two;

                if(three*three == ans) {
                    Mp[6].push_back(ans);
                }
                
            }
            if(digit == 7) {
                one = ans%10000;
                two = ans/10000;
                three = one+two;

                if(three*three == ans) {
                    Mp[8].push_back(ans);
                }
            }
        }

    }
}
void AnBus() {
    fetch();
    int n;
    while(scanf("%d", &n) == 1) {
        if(n == 2) {
            puts("00");
            puts("01");
        }
        else if(n == 4) {
            puts("0000");
            puts("0001");
        }
        else if(n == 6) {
          puts("000000");
          puts("000001");
        }
        else if(n == 8) {
          puts("00000000");
          puts("00000001");
        }
        for(int i=0; i<Mp[n].size(); i++) {
            //printf("%lld\n", Mp[n][i]);
            if(log10(Mp[n][i])+1 < n) {
                printf("0");
            }
            printf("%lld\n", Mp[n][i]);
        }
    }

}
int main() {

    AnBus();
    return 0;
}
