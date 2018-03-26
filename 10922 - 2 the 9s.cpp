#include<bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    string s;

    while(scanf("%c",&c) && c!='0')
    {
        long long int sum=0,counter=1,k=0;
        s="";

        s+=c;
        sum+=(c-48);

        while(scanf("%c",&c)==1 && c!='\n')
        {
            s+=c;
            sum+=(c-48);
            
        }

        if(sum%9==0)
        {
            while(sum>9)
            {
                counter++;

                k=sum;
                sum=0;

                while(k!=0){

                    sum += k%10;
                    k/=10;
                }
            }
            cout << s;
            printf(" is a multiple of 9 and has 9-degree %lld.\n",counter);
        }
        else{
            cout << s;
            printf(" is not a multiple of 9.\n");
        }

    }

    return 0;
}
