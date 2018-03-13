#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;

        cout<<floor(log2(n))<<endl;
    }
    return 0;
}
