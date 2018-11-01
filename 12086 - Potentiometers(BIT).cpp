#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define mx        200007
ll n, x, a, b;
ll Tree[mx], tx[mx];

void build(ll a, ll b) {
      for(; a <= n; a += a & (-a)) {
            Tree[a] += b;
      }
}

void update(ll a, ll b) {

      ll value = b - tx[a];
      tx[a] = b;
      for(; a <= n; a += a & (-a)) {
            Tree[a] += value;
      }
      
}

ll query(ll a) {
      ll sum = 0;

      for(; a > 0; a -= a & (-a)) {
            sum += Tree[a];
      }

      return sum;
}

void solve() {
	
	  ll kas = 1;
      while(cin >> n, n) {
      		if(kas != 1) cout << endl;
      		cout << "Case " << kas++ << ":" << endl;
            for(ll i = 1; i <= n; i++) {
                  cin >> tx[i];
                  build(i, tx[i]);
            }
            string s;
            while(cin >> s && s != "END") {
                  cin >> a >> b;
                  if(s == "S") {
                        update(a, b);
                  }
                  else if(s == "M") {
                        cout << query(b) - query(a - 1) << endl;
                  }
            }
            for(ll i = 0; i <= n; i++) Tree[i] = 0;
      }
}

int main() {
      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
      solve();
      return 0;
}
