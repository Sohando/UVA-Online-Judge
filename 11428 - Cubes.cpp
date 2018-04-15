#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin >> n,n)
    {
        int f = 0;
        for(int i=1; i<=n; i++)
        {

            if(i*i*i>n)
            {
                for(int j=1; j<=i; j++)
                {
                    if((i*i*i-j*j*j)==n)
                    {
                        cout << i << " " << j << endl;
                        f = 1;
                        break;
                    }
                }
            }
            if(f) break;
        }

        if(f==0) cout << "No solution" << endl;

    }
    return 0;
}
