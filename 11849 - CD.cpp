#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    int x;

    //while(cin >> n >> m, n || m)
    while(scanf("%d %d",&n,&m)==2) {

        if(n==0 && m==0) break;
        queue <int> jack;
        queue <int> jill;
        int counter = 0;

        while(n--) {
            //cin >> x;
            scanf("%d",&x);
            jack.push(x);
        }
        while(m--) {
            //cin >> x;
            scanf("%d",&x);
            jill.push(x);
        }

        while(!jack.empty() && !jill.empty()) {

            if(jack.front()==jill.front()) {
                counter++;
                jack.pop();
                jill.pop();
            }
            else if(jack.front()<jill.front()) {
                jack.pop();
            }
            else {
                jill.pop();
            }
        }
        printf("%d\n",counter);
        //cout << counter << endl;
    }

    return 0;
}
