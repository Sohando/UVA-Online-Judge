#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,d,r;

    while(scanf("%d %d %d",&n,&d,&r)) {

        if(n==0 && d==0  && r==0) break;

        int morning[n],night[n];

        for(int i=0;i<n;i++) {
            scanf("%d",&morning[i]);
        }

        for(int i=0;i<n;i++) {
            scanf("%d",&night[i]);
        }

        sort(morning,morning+n);
        sort(night,night+n);

        int sum = 0;
        for(int i=0;i<n;i++) {

            if(morning[i]+night[n-i-1] > d) {
                sum += ( (morning[i]+night[n-i-1]) - d ) * r;
            }
        }

        printf("%d\n",sum);
    }

    return 0;
}
