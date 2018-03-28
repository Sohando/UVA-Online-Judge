#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,ans=0,d=1;
    string s;

    scanf("%d",&t);
    getchar();

    while(t--)
    {

        if(d==0)printf("\n");

        cin >> s;
        int sz = s.size();

        for(int i=1; i<=sz; i++)
        {

            map < string,bool > mstr;
            int k=0;
            bool flag = true;
            for(int j=0; j<sz; j+=i)
            {

                string temp = s.substr(j,i);

                if(k==0)
                {
                    mstr[temp] = true;
                    k=1;
                }
                else
                {

                    if(mstr[temp]==false)
                    {
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)
            {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
        d=0;
    }

    return 0;
}
