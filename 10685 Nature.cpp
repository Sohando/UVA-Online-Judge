#include <bits/stdc++.h>
using namespace std;

//#define m
#define mx      5007
int Parent[mx];

void init(int n) {
    for(int i = 0; i <= n; ++i) {
        Parent[i] = i;
    }
}

int parent(int a) {
    if(Parent[a] == a) {
        return a;
    }
    return Parent[a] = parent(Parent[a]);
}

void unite(int a, int b) {
    int u = parent(a);
    int v = parent(b);

    if(u != v) {
        Parent[a] = v;
    }
}
void solve() {
    int n, m;

    while(scanf("%d %d", &n, &m), (n || m)) {
        getchar();

        init(n); //cout  << "foo" << endl;
        string str;
        unordered_map <string, int> um;
        unordered_map <int, int> tm;

        for(int i = 0; i < n; ++i) {
            cin >> str;
            um[str] = i;
        }

        string ttr;
        for(int i = 0; i < m; ++i) {
            cin >> str >> ttr;
            unite(um[str], um[ttr]);
        }

        //cout << "faa" << endl;
        int Mx  =  -1;
        for(int i = 0; i < n; ++i) {
                //cout << " faa " << endl;
            Parent[i] = parent(i);
//cout << "jaa" << endl;
            tm[Parent[i]]++;

            if(tm[Parent[i]] > Mx) {
                Mx = tm[Parent[i]];
            }
        }

        printf("%d\n", Mx);
    }
}

int main() {
    #ifdef m
        freopen("nature.txt", "r", stdin);
    #endif
    solve();
    return 0;
}
