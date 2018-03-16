#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,sum=0,t;
    string s;

    cin>>t;

    while(t--)
    {
        cin>>s;

        if(s=="donate")
        {
            cin>>a;
            sum+=a;
        }
        else
        {
            cout<<sum<<endl;
        }
    }

    return 0;
}
