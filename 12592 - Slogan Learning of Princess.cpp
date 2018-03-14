#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,p;
    string q,s;
    map <string,string> ma;

    cin>>t;
    getchar();
    while(t--){
        getline(cin,s);
        getline(cin,q);

        ma[s] = q;
    }

    cin>>p;
    getchar();

    while(p--){
        getline(cin,s);
        cout << ma[s] <<endl;
    }

    return 0;
}
