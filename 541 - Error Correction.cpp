#include<bits/stdc++.h>
using namespace std;

int main()
{

    int _naf;

    while(cin >> _naf,_naf) {

        int c=0,arr[_naf][_naf],row=0,f=1;
        pair<int,int> de;

        for(int i=0;i<_naf;i++) {
            row = 0;
            for(int j=0;j<_naf;j++) {
                cin >> arr[i][j];
                row += arr[i][j];
            }
            if(row%2==1) {
                c++;
                f=0;
                de.first = i+1;
            }
        }

        if(c>1) {
            cout << "Corrupt\n";
            continue;
        }

        int col=0;
        c=0;

        for(int j=0;j<_naf;j++) {

            int col=0;
            for(int i=0;i<_naf;i++) {
                col += arr[i][j];
            }
            if(col%2==1) {
                de.second = j+1;
                c++;
                f=0;
            }
        }

        if(c>1) {
            cout << "Corrupt\n";
            continue;
        }

        else if(f) {
            cout << "OK\n";
        }
        else {
            cout << "Change bit ("<<de.first <<","<<de.second <<")"<<endl;
        }

    }

    return 0;
}
