#include<bits/stdc++.h>
using namespace std;

#define scan(a) scanf("%d",&a)
#define max(a,b) a>b?a:b

void faster() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

}

int main() {
    
    faster();

    int n;

    while( scan( n ) == 1 && n) {

    int Array[ n ];

    for( int i=0;i<n;i++ ) {
        scan( Array[ i ] );
    }

    int s=0,p=0;
    for( int i=0;i<n;i++ ) {
        s = max( Array[ i ], s+Array[ i ] );
        p = max( s,p );
    }

    if( p==0 ) {
        printf("Losing streak.\n");
    }
    else {
        printf( "The maximum winning streak is %d.\n",p );
    }

  }
  return 0;
}
