#include<bits/stdc++.h>
using namespace std;

int main()
{
    int input,taka,jon,t,k=1;

    while(cin>>input)
    {
        if(k==0){
            cout << endl;
        }
        string s[input],str;
        map < string,int > ma;

        for(int i=0; i<input; i++)
        {
            cin >> s[i];
        }

        for(int i=0; i<input; i++)
        {
            cin>>str>>taka>>jon;
            t=0;
            if(jon!=0)
            {
                t = taka%jon;
                ma[str] -= (taka-t);
            }

            for(int j=0; j<jon; j++)
            {
                cin>>str;
                ma[str] += taka/jon;
            }
        }
        for(int i=0; i<input; i++)
        {
            cout <<s[i]<<" "<< ma[s[i]] <<endl;
        }
        k=0;
    }

    return 0;
}
