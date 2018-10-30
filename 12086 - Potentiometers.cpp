#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int xXx = 200007;
const int sqt = 500;
ll Array[xXx];
ll block[sqt];
int blk_sz;

void fast() {
      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

void update(int idx, int value) {

      int blk_idx = idx / blk_sz;
      block[blk_idx] += (value - Array[idx]);
      Array[idx] = value;

      return;
}

ll query(int l, int r) {
      ll sum = 0;
      while(l < r && l % blk_sz != 0 && l != 0) {
            sum += Array[l];
            l++;
      }

      while(l + blk_sz <= r) {
            sum += block[l / blk_sz];
            l += blk_sz;
      }

      while(l <= r) {
            sum += Array[l];
            l++;
      }

      return sum;
}

void build(int n) {
      
      blk_sz = sqrt(n);
      int blk_idx = -1;
      for(int i = 0; i < n; i++) {
         
            if(i % blk_sz == 0) {
                  blk_idx++;
            }
            block[blk_idx] += Array[i];
      }

      return;
}

void solve() {
      fast();
      int n, cases = 1, T = 0; string s; int m, k;
      while(cin >> n, n) {
            if(T == 1) cout << endl;
            T = 1;
            cout << "Case " << cases++ <<":" << endl;
            for(int t = 0; t < n; t++) {
                  cin >> Array[t];
            }

            build(n);

            while(cin >> s && s != "END") {
                  cin >> m >> k;
                 
                  if(s == "M") {
                        cout << query(m-1, k-1) << endl;
                  }
                  else if(s == "S") {
                        update(m-1, k);
                  }
                  else {
                        break;
                  }
            }
            memset(block, 0, sizeof(block));
      }

}
int main() {
      solve();
      return 0;
}

