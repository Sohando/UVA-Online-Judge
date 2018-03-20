#include<bits/stdc++.h>
using namespace std;

int main()
{

    set <int> iset;
    set <int>::iterator it;
    int t,x,cases=1;

    cin>>t;
    while(t--){

        for(int i=0;i<13;i++){

            cin>>x;
            iset.insert(x);
        }

        it=iset.begin();

        if(*it==0) cout << "Set #"<<cases++ <<": No" << endl;
        else cout << "Set #"<<cases++ <<": Yes" << endl;

        iset.clear();
    }

    return 0;
}
