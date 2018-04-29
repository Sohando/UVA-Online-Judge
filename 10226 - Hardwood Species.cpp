#include<bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    int test,k=1;

    cin >> test;
    getchar();
    getchar();
    while(test--) {
    	
    	if(k==0) cout << endl;

        map <string,int> sim;
        double moot=0;

        while(getline(cin,s)) {
            if(s=="\0") break;

            sim[s]++;

            moot++;

        }

        for(auto it=sim.begin();it!=sim.end();it++) {
            double sol = (it->second/moot);
            sol *= 100;

            cout << it->first << " ";
            printf("%.4f\n",sol);
        }
		k=0;
    }

    return 0;
}
