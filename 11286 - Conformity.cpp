#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,x;

    while(scanf("%d",&test)==1 && test)
    {
        map < vector<int>,int > ma;
        int t=0,maxi=0;
        
        while(test--)
        {
            vector <int> vi;
            for(int i=0; i<5; i++)
            {
                scanf("%d",&x);
                vi.push_back(x);
            }
            sort(vi.begin(),vi.end());
            ma[vi]++;

            if(ma[vi]>maxi){
                maxi = ma[vi];
                t = 1;
            }
            else if(ma[vi]==maxi) t++;
        }
        printf("%d\n",t*maxi);
    }
    return 0;
}

