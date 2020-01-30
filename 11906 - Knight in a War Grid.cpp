#include <bits/stdc++.h>
#define endl "\n"
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef pair <int, int> ii;

int Arr[101][101];
map<ii, bool> vis;
void trip(int a, int b, int c, int d) {
    queue<int>Q;
    Q.push(0),Q.push(0);
    int x[] = {c, c, d, d, -c, -c, -d, -d};
    int y[] = {d, -d, c, -c, d, -d, c, -c};
    // vis[{0, 0}] = true;
    int even = 0, odd = 0;
    vis.clear();
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        int v = Q.front(); Q.pop();
        // cout << "(" << u << "," << v <<")" << " ==: ";
        int pos = 0;
        // cout << vis[{u, v}] << endl;
        vis[{u, v}] = true;
        for (int i = 0; i < 8; ++i) {
            int e = u + x[i];
            int f = v + y[i];
            // cout << "E = " << e << " F " << f << " ";
            // cout << e << "," << f << endl;
            if ((e < a and e >= 0) and (f < b and f >= 0) and Arr[e][f] == 0) {
                pos++;
                Arr[e][f] = 2;
                // cout << e << " " << f << endl;
                // ii o = ;
                if (!vis[{e, f}]) {
                    Q.push(e), Q.push(f);
                    vis[{e, f}] = true;
                }
            }
        }
        for (int i = 0; i < 8; ++i) {
            int e = u + x[i];
            int f = v + y[i];
            // cout << "E = " << e << " F " << f << " ";
            if ((e < a and e >= 0) and (f < b and f >= 0) and Arr[e][f] == 2) {
                // pos++;
                Arr[e][f] = 0;
            }
        }
        // cout << pos << "\n";
        odd += (pos%2 == 1);
        even += (pos%2 == 0);
    }
    cout << even << " " << odd << endl;
}
void solve() {
    int t;
    cin >> t;

    for (int cas = 1; cas <= t; ++cas) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        memset(Arr, 0, sizeof Arr);
        int g;
        cin >> g;

        for (int i = 0, x, y; i < g; ++i) {
            cin >> x >> y;
            Arr[x][y] = -1;
        }
        cout << "Case " << cas <<": ";
        trip(a, b, c, d);
    }
}
int main() {
    ios;
    solve();
}
