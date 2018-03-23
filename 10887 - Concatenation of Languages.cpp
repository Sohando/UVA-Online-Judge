#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,t,cases=1;
    vector <string> a,b;
    set <string> S;
    string s;

    cin >> t;

    while(t--){

        scanf("%d %d",&n,&m);
        getchar();

        for(int i=0;i<n;i++) {
            getline(cin,s);
            a.push_back(s);
        }

        for(int i=0;i<m;i++) {
            getline(cin,s);
            b.push_back(s);
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                S.insert(a[i]+b[j]);
            }
        }
        
       cout << "Case "<<cases++ <<": "<< S.size() << endl;
       S.clear();
       a.clear();
       b.clear();

    }

    return 0;
}
