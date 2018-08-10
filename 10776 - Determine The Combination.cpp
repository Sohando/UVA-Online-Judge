#include<bits/stdc++.h>
using namespace std;

vector< char > vs;
bool used[100];
void _baby( string s, int t, int index ) {
    //cout << s << t << endl;

    if( vs.size()==t ) {
        for( int i=0;i<t;i++ ) {
            cout << vs[i];
        }
        cout << endl;
        return;
    }

    for( int i=index;i<s.size();i++ )  {

        if( used[i] ) continue;
        used[i] = true;
        vs.push_back( s[i] );
        _baby( s,t,i );
        used[i] = false;
        vs.pop_back();
        while( s[i]==s[i+1] ) i++;
    }
}

int  main() {

    string s;
    int t;

    while( cin >> s >> t ) {
        sort( s.begin(),s.end() );
       
        _baby( s, t, 0 );
    }

    return 0;
}
