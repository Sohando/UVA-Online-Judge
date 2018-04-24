//time -> .110
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,q,cases = 1;

    while(scanf("%d %d",&p,&q)==2) {

        if(p==0 && q==0) {
            break;
        }

        int marble[p];
        for(int i=0;i<p;i++) {
            scanf("%d",&marble[i]);
        }

        sort(marble,marble+p);

        cout << "CASE# " << cases++ << ":" << endl;
        int f,where;
        while(q--) {
            f = 0;
            scanf("%d",&where);

            int lo=0,hi=p-1,ans = 100000;
            while(lo<=hi) {
                int mid = (lo+hi)/2;

                if(marble[mid]==where) {
                    f = 1;
                    if(mid+1<ans) ans = mid+1;

                    hi = mid-1;
                }
                else if(marble[mid] < where) {
                    lo = mid+1;
                }
                else {
                    hi=mid-1;
                }
            }
            if(!f) {
                cout << where <<" not found" << endl;
            }
            else{
                cout  << where <<" found at " << ans << endl;

            }
        }
    }

    return 0;
}

/*
//time -> .150
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,q,cases = 1;

    while(cin >> p >> q) {

        if(p==0 && q==0) {
            break;
        }

        int marble[p];
        for(int i=0;i<p;i++) {
            cin >> marble[i];
        }

        sort(marble,marble+p);

        cout << "CASE# " << cases++ << ":" << endl;
        int f,where;
        while(q--) {
            f = 0;
            cin >> where;

            int lo=0,hi=p-1,ans = 100000;
            while(lo<=hi) {
                int mid = (lo+hi)/2;

                if(marble[mid]==where) {
                    f = 1;
                    if(mid+1<ans) ans = mid+1;

                    hi = mid-1;
                }
                else if(marble[mid] < where) {
                    lo = mid+1;
                }
                else {
                    hi=mid-1;
                }
            }
            if(!f) {
                cout << where <<" not found" << endl;
            }
            else{
                cout  << where <<" found at " << ans << endl;

            }
        }
    }

    return 0;
}
*/

/*
//time -> .550
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,q,cases = 1;

    while(cin >> p >> q) {

        if(p==0 && q==0) {
            break;
        }

        int marble[p];
        for(int i=0;i<p;i++) {
            cin >> marble[i];
        }

        sort(marble,marble+p);

        cout << "CASE# " << cases++ << ":" << endl;
        int f,where;
        while(q--) {
            f = 0;
            cin >> where;

            for(int i=0;i<p;i++) {
                if(marble[i]==where) {
                    cout  << where <<" found at " << i+1 << endl;
                    f = 1;
                    break;
                }
            }
            if(!f) {
                cout << where <<" not found" << endl;
            }
        }
    }

    return 0;
}

*/
