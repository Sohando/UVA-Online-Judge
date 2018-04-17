#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a[1000000],number,n,carry=0,multiply=0;

    while(scanf("%lld",&number)==1) {
        printf("%lld!\n",number);
        memset(a,0,sizeof(a));

        a[0] = 1;
        n = 1;

        for(long long int i=2;i<=number;i++) {

            carry = 0;
            for(long long int j=0;j<n;j++) {

                multiply = a[j]*i+carry;

                a[j] = multiply%10;
                carry = multiply/10;
            }

            while(carry) {

                a[n] = carry%10;
                carry /= 10;
                n++;
            }
        }

        for(long long int i = n-1;i>=0;i--) {
            printf("%lld",a[i]);
        }
        printf("\n");
    }

    return 0;
}
