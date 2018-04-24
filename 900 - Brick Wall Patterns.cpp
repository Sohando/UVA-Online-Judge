#include <bits/stdc++.h>

using namespace std;

long long int fib[51];

void boss_baby() {
    fib[0] = 1;
    fib[1] = 1;
    
    for(int i=2;i<=50;i++) {
        fib[i] = fib[i-1]+fib[i-2];
    }
}

int main()
{   
    boss_baby();
    
    int n;
    
    while(cin >> n,n) {
        cout << fib[n] << endl;
    }
    return 0;
}
