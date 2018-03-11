#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define maxi 100000

int main()
{

    string s;
    int ch,s2;

    while(cin>>s>>ch>>s2)
    {
        getchar();

        int len = s.size()-1,ans=0,l=0,a=0;

        for(int i=len; i>=0; i--)
        {

            if(s[i]>='A' && s[i]<='F')
            {
                a = (s[i]-65)+10;
            }
            else
            {
                a = s[i]-'0';
            }
            ans += a*pow(ch,l++);
        }

        if(ans!=0)
        {
            char arr[maxi];
            int i=0;

            while(ans>0)
            {
                int b = ans%s2;

                if(b>9)
                {
                    arr[i++] = b+55;
                }
                else
                {
                    arr[i++] = b+'0';
                }

                ans/=s2;
            }
            arr[i] = '\0';

            if(i>7)
            {
                printf("%7s\n","ERROR");
            }

            else
            {
                for(int j=1; j<=7-i; j++)
                {
                    cout<<" ";
                }
                for(int j=i-1; j>=0; j--)
                {
                    printf("%c",arr[j]);
                }

                cout<<endl;
            }

        }
        else
        {
            for(int i=1;i<=6;i++)
            {
                cout<<" ";
            }
            cout<<0<<endl;
        }
    }

    return 0;
}
