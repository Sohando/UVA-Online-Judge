#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,n,p,q,cases = 1;
    cin>>test;

    while(test--) {
        cin >> n >> p >> q;
        int egg[n];

        for(int i=0;i<n;i++) {
            cin >> egg[i];
        }

        int rakhte_pari = 0,koto_gm = 0,ans = 0;

        for(int i=0;i<n;i++) {

           if(rakhte_pari<p && koto_gm+egg[i]<=q) {

                rakhte_pari++;
                koto_gm += egg[i];
                ans++;

            }
        }

        cout << "Case " << cases++ << ": " << ans << endl;
    }
    return 0;
}
