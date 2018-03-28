#include<bits/stdc++.h>
using namespace std;

int main()
{
    int maxi=-1,counter=0;
    string ans="",s,temp="";

    while(cin >> s && s!="E-N-D")
    {

        int sz = s.size();
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
                if(counter>maxi)
                {
                    maxi = counter;
                    ans = temp;
                }
                counter = 0;
                temp="";
            }
        }
    }

    for(int i=0;i<ans.size();i++){

        ans[i] = tolower(ans[i]);
    }
    cout << ans << endl;

    return 0;
}
