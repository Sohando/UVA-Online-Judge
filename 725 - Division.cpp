#include<bits/stdc++.h>
using namespace std;

map<int, vector< pair<int, int> > > Mp;
vector<int>V;
int digit[10];

void generate() {
    int high = 98765;
    int low = 1234;
//cout << "foo" << endl;
    for(int i=2; i<=79; i++) {
        for(int j=low; j<=high; j++) {
            int ans = j*i; //bool foo = true;
            if(ans <= high && ans >= 10000) {
                memset(digit, 0, sizeof(digit));
                int t1 = j, t2 = ans;
                if(j <= 9999) {
                    digit[0] = 1;
                    //cout << "foo" << endl;
                }
                while(t1 != 0 && digit[t1%10] == 0) {
                    digit[t1%10] = 1;
                    t1 /= 10;
                    //cout << "gg"<< endl;
                }
                if( t1 == 0) {
                    while(t2 != 0 && digit[t2%10] == 0) {
                        digit[t2%10] = 1;
                        t2 /= 10;
                    }
                    if(t2 == 0) {
                        Mp[i].push_back({j, ans});
                    }
                }
            }
        }
    }
 }
void AnBus() {
    //freopen("o.txt", "w", stdout);
    generate();
    int n, l = 0;
    while(scanf("%d", &n) == 1, n) {
      if(l == 1) printf("\n");
      if(Mp[n].size() !=0 ) {
          int sz = Mp[n].size();

          for(int i=0; i<sz; i++) {
              printf("%d / ", Mp[n][i].second);
              if(Mp[n][i].first <= 9999) {
                printf("0%d = %d\n",Mp[n][i].first, n);
              }
              else {
                  printf("%d = %d\n",Mp[n][i].first, n);
              }
          }
      }
      else {
          printf("There are no solutions for %d.\n", n);
      }
      l = 1;
    }

}

int main() {

    AnBus();
    return 0;
}
