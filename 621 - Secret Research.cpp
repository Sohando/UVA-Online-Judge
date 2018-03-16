#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long int n;

    scanf("%lld",&n);
    int s;
    string str;

    while(n--)
    {

        cin>>str;

        int len = str.size();


        if(str=="1" || str=="4" || str=="78"){
            printf("+\n");
        }
        else if(str[len-1]=='5' && str[len-2]=='3')
        {
            printf("-\n");
        }
        else if(str[0]=='9' && str[len-1]=='4')
        {
            printf("*\n");
        }
        else
        {
            printf("?\n");
        }
    }

    return 0;
}
