#include<bits/stdc++.h>
using namespace std;

int main()
{
    int maxi=-1,counter=0,flag=0;
    string ans="",s,temp="";

    while(cin >> s && s!="E-N-D")
    {

        int sz = s.size();
        flag=0;
        temp = "";

        for(int i=0; i<=sz; i++)
        {

            if(s[i]>='A' && s[i]<='z' || s[i]=='-')
            {
                temp += s[i];
                counter++;
            }
            else
            {

                flag=1;
                if(counter>maxi)
                {
                    maxi = counter;
                    ans = temp;
                }
                counter = 0;
                temp="";
            }
        }

        if(flag==0)
        {
            if(sz>maxi)
            {
                maxi = sz;
                ans = s;
            }
        }
    }

    for(int i=0;i<ans.size();i++){

        ans[i] = tolower(ans[i]);
    }
    cout << ans << endl;

    return 0;
}
