#include<bits/stdc++.h>
using namespace std;

int GCD(int a,int b)
{

    if(a%b==0)
    {
        return b;
    }
    else return  GCD(b,a%b);
}

int main()
{
    string s,item;
    int n,num;
    vector <int> v;
    cin >> n;
    getchar();

    while(n--)
    {
        int gcd = 0,maxi = 1;

        getline(cin,s);

        istringstream ss(s);

        while(getline(ss,item,' '))
        {
            num = stoi(item,nullptr,10);
            v.push_back(num);
        }
        sort(v.begin(),v.end());

        int sz = v.size();

        for(int i=0; i<sz; i++)
        {
            for(int j=i+1; j<sz; j++)
            {

                gcd = GCD(v[i],v[j]);
                if(gcd>maxi)
                {
                    maxi = gcd;
                }
            }
        }
        cout << maxi << endl;
        v.clear();
    }

    return 0;
}
