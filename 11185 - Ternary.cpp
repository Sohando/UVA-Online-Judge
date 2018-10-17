/**
* author : r_hasan
* created: 17.10.18 11.55
**/
#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
      int tomato = n; string ternary = "";
      while(tomato > 0) {
            ternary += (tomato % 3 + '0');
            tomato /= 3;
      }
      reverse(ternary.begin(), ternary.end());
      cout << ternary << endl;
}

int main() {
      ios_base::sync_with_stdio(0), cin.tie(0);
      int n;
      while(cin >> n) {
            if(n < 0) break;
            else if(n == 0) cout << 0 << endl;
            else {
                  solve(n);
            }
      }
      return 0;
}
