#include <bits/stdc++.h>
using namespace std;

#define     mx            200007
typedef     long long int ll;
ll Tree[4 * mx], tx[mx];
int n, a, b;

void build(int node, int start, int end) {
    if(start == end) {
        Tree[node] = tx[start];
    }
    else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
    }
}

void update(int node, int start, int end, int idx, int val) {
    if(start == end) {
    	Tree[node] = val;
        tx[start] = val;
    }
    else {
        int mid = (start + end) / 2;
        if(idx >= start && idx <= mid) {
            update(node * 2, start, mid, idx, val);
        }
        else {
            update(node * 2 + 1, mid + 1, end, idx, val);
        }
        Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
    }
}

ll query(int node, int start, int end, int l, int r) {
    if(r < start || l > end) {
        return 0;
    }
    if(l <= start && r >= end) {
        return Tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(node * 2, start, mid, l, r);
    int p2 = query(node * 2 + 1, mid + 1, end, l, r);

    return (p1 + p2);
}

void solve() {
    ll kas = 1;
    while(cin >> n, n) {
        if(kas != 1) cout << endl;
        cout << "Case " << kas++ << ":" << endl;
        for(ll i = 1; i <= n; i++) {
            cin >> tx[i];
        }

        build(1, 1, n);
        
        string s;
        while(cin >> s && s != "END") {
            cin >> a >> b;
            if(s == "S") {
                update(1, 1, n, a, b);
            }
            else if(s == "M") {
                cout << query(1, 1, n, a, b) << endl;
            }
        }
        for(ll i = 0; i <= 4 * n + 1; i++) Tree[i] = 0;
    }
}

int main() {
    solve();
    return 0;
}
