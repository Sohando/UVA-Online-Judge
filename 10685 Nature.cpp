#include <bits/stdc++.h>
using namespace std;

#define M
#define mx      5007
int Parent[mx];

void init(int n) {
    for(int i = 0; i <= n; ++i) {
        Parent[i] = i;
    }
}

int root(int a) {
    if(Parent[a] == a) {
        return a;
    }
    return Parent[a] = root(Parent[a]);
}

void unite(int a, int b) {

    Parent[root(b)] = root(a);
}
void solve() {
    int n, m;

    while(scanf("%d %d", &n, &m) == 2 ) {
        //getchar();
        //cout << n << " " << m << endl;
        if( n + m == 0 ) break;

        init(n);
        string str;
        map <string, int> um;
        map <int, int> tm;

        for(int i = 0; i < n; ++i) {
            cin >> str;
            um[str] = i;
        }

        string ttr;
        for(int i = 0; i < m; ++i) {
            cin >> str >> ttr;

            unite(um[str], um[ttr]);
        }

        int Mx  =  -1;

        for(int i = 0; i < n; ++i) {
            Parent[i] = root(i);

            tm[Parent[i]]++;

            if(tm[Parent[i]] > Mx) {
                Mx = tm[Parent[i]];
            }
        }
        printf("%d\n", Mx);
    }
}

int main() {
    #ifdef M
        freopen("natrue.txt", "r", stdin);
    #endif
    solve();
    return 0;
}
