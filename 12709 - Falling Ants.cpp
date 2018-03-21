#include<bits/stdc++.h>
using namespace std;

struct Ant
{
    int v;
    double r;
};

int main()
{
    int test,h,w,l;

    while(scanf("%d",&test)==1 && test)
    {
        Ant ant[test];

        for(int i=0; i<test; i++)
        {
            cin >> l >> w >> h;

            ant[i].v = w*h*l;
            ant[i].r = h;
        }

        int maximum=0;
        double rate=0.0;
        
        for(int i=0; i<test; i++)
        {
            if(ant[i].r>rate)
            {
                maximum = ant[i].v;
                rate = ant[i].r;
            }
            else if(ant[i].r==rate)
            {
                maximum = max(maximum,ant[i].v);
            }
        }
        cout << maximum << endl;
    }
    return 0;
}
