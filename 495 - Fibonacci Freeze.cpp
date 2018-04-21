#include<bits/stdc++.h>
using namespace std;

#define maxi 5000
map <int,string> ma;

void boss_baby()
{
    ma[0] = "0";
    ma[1] = "1";

    for(int i=2; i<=maxi; i++)
    {

        string ans= "";
        string s = ma[i-1];
        string t = ma[i-2];

        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());

        int carry = 0;

        int n1 = s.size();
        int n2 = t.size();

        for (int i=0; i<n2; i++)
        {
            int sum = ((s[i]-'0')+(t[i]-'0')+carry);
            ans.push_back(sum%10 + '0');

            carry = sum/10;
        }

        for (int i=n2; i<n1; i++)
        {
            int sum = ((s[i]-'0')+carry);
            ans.push_back(sum%10 + '0');
            carry = sum/10;
        }

        if (carry)
            ans.push_back(carry+'0');

        reverse(ans.begin(), ans.end());

        ma[i] = ans;

    }
}

int main()
{
    boss_baby();

    int n;

    while(cin >> n)
    {
        printf("The Fibonacci number for %d is ",n);
        cout << ma[n] << endl;
    }

    return 0;
}
