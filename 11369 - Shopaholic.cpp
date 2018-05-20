#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,s;

    scanf("%d",&t);

    for(int i=0;i<t;i++) {
        scanf("%d",&s);

        int a[s];

        for(int j=0;j<s;j++) {
           scanf("%d",&a[j]);
        }

        sort(a,a+s);

        int get = 0;
        int c = 0;
        for(int j = s-1;j>=0;j--) {

            c++;

            if(c%3==0) {
                get += a[j];
            }
        }

        printf("%d\n",get);
    }


    return 0;
}
