#include <bits/stdc++.h>
using namespace std;

#define mx      1007
//#define m
int W[mx], P[mx], Bosta[mx][100];
int Capacity, n;
int SuperSale(int idx, int taken) {
    if(idx == n) {
        //cout << "Returned For " << idx-1 <<  endl;
        return 0;
    }

    if(Bosta[idx][taken] != -1) {
            //cout << Bosta[idx][taken] << endl;
        return Bosta[idx][taken];
    }

    int p1 = 0, p2 = 0;
    if(taken + W[idx] <= Capacity) {
        //cout << idx << " Nilam" << endl;
        p1 = P[idx] + SuperSale(idx + 1, taken + W[idx]);

        //cout << p1 << endl;
    }
    else {
        //cout << idx << " baad with taken " << taken  << " and " << p1 << "\n";
        p1 = 0;
    }

    //cout << "Calling without " << idx << " With Taken " << taken << endl;
    p2 = SuperSale(idx + 1, taken);

    //cout << p1 << " " << p2 << endl;

    Bosta[idx][taken] = max(p1, p2);
    return Bosta[idx][taken];
//    return max(p1, p2);
}

void solve() {
    int t;

    //cin >> t;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i) {
        //cin >> n;
        scanf("%d", &n);

        for(int j = 0; j < n; ++j) {
            //cin >> P[j] >> W[j];
            scanf("%d %d", &P[j], &W[j]);
        }

        int k, sum = 0;
        //cin >> k;
        scanf("%d", &k);

        for(int j = 0; j < k; ++j) {
            //cin >> Capacity;
            scanf("%d", &Capacity);
            memset(Bosta, -1, sizeof(Bosta));
            sum += SuperSale(0, 0);
        }

        printf("%d\n", sum);
    }
}
int main() {
    #ifdef m
        freopen("knap.txt", "r", stdin);
    #endif
    solve();
    return 0;
}
