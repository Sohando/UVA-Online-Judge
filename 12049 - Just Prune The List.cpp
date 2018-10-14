#include <bits/stdc++.h>
using namespace std;
map < int, int > Mp1, Mp2;
map < int, int > :: iterator it;
void reset()
{
    Mp1.clear(), Mp2.clear();
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(0);
    int test, n, m, x;
    cin >> test;
    while(test--)
    {
        reset();
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            Mp1[x]++;
        }
        for(int i = 0; i < m; i++)
        {
            cin >> x;
            Mp2[x]++;
        }
        int cow = 0;
        int s2 = Mp2.size();
        int s1 = Mp1.size();

        for(it = Mp2.begin(); it != Mp2.end(); it++)
        {
            int x = Mp1[it->first];
            int y = it->second;
            if(x != y)
            {
                cow += abs(x - y);
                Mp1[it->first] = abs(x - y);
                Mp2[it->first] = abs(x - y);
            }
        }
        for(it = Mp1.begin(); it != Mp1.end(); it++)
        {
            int x = Mp2[it->first];
            int y = it->second;
            if(x != y)
            {
                cow += abs(x - y);
            }
        }

        cout << cow << endl;
    }
    return 0;
}
