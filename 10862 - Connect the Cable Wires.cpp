#include<bits/stdc++.h>
using namespace std;

string fib,tib,tem;
map< int, string > mp;

string doSum(string a, string b)
{
    if(a.size() < b.size())
        swap(a, b);

    int j = a.size()-1;
    for(int i=b.size()-1; i>=0; i--, j--)
        a[j]+=(b[i]-'0');

    for(int i=a.size()-1; i>0; i--)
    {
        if(a[i] > '9')
        {
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
    }
    if(a[0] > '9')
    {
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    return a;
}

void fibonacci_string() {
    mp[1] = "1";
    mp[2] = "2";
    for( int i=3;i<=4500;i++ ) {
        fib = mp[i-2];
        tib = mp[i-1];
        tem = doSum(fib,tib);
        mp[i] = tem;
    }
}
int main() {

    fibonacci_string();
    int n;
    while( scanf("%d",&n)==1, n ) {

        int in = (2*n-1);
        cout << mp[in] << endl;
    }

    return 0;
}
