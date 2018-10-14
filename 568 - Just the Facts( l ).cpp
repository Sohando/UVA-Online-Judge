#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll trailing_zero(ll n) {
      ll cow = 0;
      while(n) {
            cow += (n / 5);
            n /= 5;
      }
      return cow;
}
ll solve(int n) {
      ll five_ache = trailing_zero(n);
      ll mul = 1;
      for(ll i = 2; i <= n; i++) {
            ll temp = i;
            while(temp % 5 == 0) temp /= 5;
            while(temp % 2 == 0) {
                  if(five_ache) {
                        temp /= 2;
                        five_ache--;
                  }
                  else {
                        break;
                  }
            }
            mul = (mul * temp) % 10;
      }
      return mul;
}

int main() {
      ios_base::sync_with_stdio(0), cin.tie(0);
      ll n;
      while(cin >> n) {
            printf("%5d -> %d\n",n, solve(n));
      }
      return 0;
}
