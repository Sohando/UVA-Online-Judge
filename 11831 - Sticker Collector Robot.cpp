#include <bits/stdc++.h>
#define endl "\n"
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef pair <int, int> ii;
char Arr[101][101];

int collectStriker(ii point, string move, int n, int m) {
    // cout << move << endl;
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << Arr[i][j];
    //     }
    //     cout << endl;
    // }
    // ‘N’, ‘S’, ‘L’, ‘O’
    // North, South, East and West
    int s = 0;
    int x = point.first, y = point.second;
    char lastOrientation = Arr[point.first][point.second];
    for (int iter = 0; iter < (int)move.size(); ++iter) {
        // cout << lastOrientation << " (" << x << "," << y << ")" << endl;
        if (move[iter] == 'D') {
            if (lastOrientation == 'N') {
                lastOrientation = 'L';
            }
            else if (lastOrientation == 'S') {
                lastOrientation = 'O';
            }
            else if (lastOrientation == 'L') {
                lastOrientation = 'S';
            }
            else {
                lastOrientation = 'N';  
            }
        }
        else if (move[iter] == 'E') {
            if (lastOrientation == 'N') {
                lastOrientation = 'O';
            }
            else if (lastOrientation == 'S') {
                lastOrientation = 'L';
            }
            else if (lastOrientation == 'L') {
                lastOrientation = 'N';
            }
            else {
                lastOrientation = 'S';  
            }
        }
        else {
            if (lastOrientation == 'N') {
                // lastOrientation = 'O';
                if (x - 1 >= 0 and Arr[x - 1][y] != '#') {
                    x -= 1;
                    if (Arr[x][y] == '*') s++;
                    // cout << "Found" << endl;
                    Arr[x][y] = '.';
                }
            }
            else if (lastOrientation == 'L') {
                // lastOrientation = 'L';
                if (y + 1 < m and Arr[x][y + 1] != '#') {
                    y += 1;
                    if (Arr[x][y] == '*') s++;
                    // cout << "Found" << endl;
                    Arr[x][y] = '.';
                }
            }
            else if (lastOrientation == 'S') {
                // lastOrientation = 'N';
                if (x + 1 < n and Arr[x + 1][y] != '#') {
                    x += 1;
                    s += (Arr[x][y] == '*');
                    // cout << "Found" << endl;
                    Arr[x][y] = '.';
                }
            }
            else {
                // lastOrientation = 'S';  
                if (y - 1 >= 0 and Arr[x][y - 1] != '#') {
                    y -= 1;
                    s += (Arr[x][y] == '*');
                    // cout << "Found" << endl;
                    Arr[x][y] = '.';
                }
            }
        }
    }
    return s;
}
void solve() {
    int n, m, s;
    ii point;
    char ch;
    while (cin >> n >> m >> s, (n + m + s)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> Arr[i][j];
                if (isalpha(Arr[i][j])) {
                    point = {i, j};
                }
            }
            // getchar();
            // cin >> ch;
        }
        string move;
        cin >> move;
        cout << collectStriker(point, move, n, m) << endl;
    }
}
int main() {
    ios;
    solve();
}
