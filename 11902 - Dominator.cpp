#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

vi G[101];
vi x;
vi vis(101), vis0(101);

int ans[101][101];

void dfs1(int s) {
    if (!vis0[s]) {
        vis0[s] = 1;

        for (auto t : G[s]) {
            if (!vis0[t]) {
                x.push_back(t);
                dfs1(t);
            }
        }
    }
}
void dfs(int s, int t) {
    // cout << s << " " << t << endl;
    if (s == t) return;
    vis[s] = 1;

    for (auto l : G[s]) {
        if (t != l and l != 0) ans[t][l] = 1;
        if (!vis[l]) {
            // cout << t << "--> " << l << endl;
            dfs(l, t);
        }
    }
}
void solve() {
    int t;
    scanf("%d", &t);

    for (int cas = 1; cas <= t; ++cas) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            G[i].clear();
            for (int j = 0; j < n; ++j) {
                // if (j == 0 and i) ans[i][j] = 1;
                ans[i][j] = 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int d;
                cin >> d;

                if (d) {
                    G[i].push_back(j);
                }
            }
        }
        x.clear();
        dfs1(0);

        // for (auto t : x) cout << t << ", ";
        // cout << endl;

        for (int i = 0; i < n; ++i) {
            if (vis0[i]) {
                ans[0][i] = 0;
            }
        }
        for (auto t : x) {
            // memset(vis.begin(), vis.end(), 0);
            // vis.clear();
            vis.assign(101, 0);
            dfs(0, t);
            for (int i = 1; i < n; ++i) {
                if (vis[i]) {
                    ans[t][i] = 1;
                }
                else if (vis0[i]) {
                    ans[t][i] = 0;
                }
            }
        }

        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vis0.assign(101, 0);
        printf("Case %d:\n+", cas);

        for (int i = 1; i < 2 * n; ++i) {
            printf("-");
        }
        printf("+\n");

        // cout << "| ";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!j) printf("|");
                !ans[i][j] ? printf("Y|") : printf("N|");
                // if (j == d-1) cout << "|";
            }
            // cout << endl;
            printf("\n+");
            for (int i = 1; i < 2 * n; ++i) {
                printf("-");
            }
            printf("+\n");
        }
        // printf("+");
        // for (int i = 1; i < 2 * n; ++i) {
        //     printf("-");
        // }
        // printf("+\n");
    }
}
int main() {
    solve();
    return 0;
}
