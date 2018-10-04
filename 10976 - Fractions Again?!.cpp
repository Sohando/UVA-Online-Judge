#include<bits/stdc++.h>
using namespace std;

void AnBus() {
    long long n;
    while(scanf("%lld", &n) == 1) {
		
		int c = 0;
		vector< pair<long long, long long>  > V;
        for(long long i=n+1; i<=n+n; i++) {
            long long denom = n*i;
            long long numen = i-n;

            if(denom % numen == 0) {
                denom = (denom / numen);
                //printf("1/%lld = 1/%lld + 1/%lld\n", n, denom, i);
                V.push_back({denom, i});
                c++;
            }
        }
        printf("%lld\n", c);
        for(int k=0; k<c; k++) {
        	printf("1/%lld = 1/%lld + 1/%lld\n", n, V[k].first, V[k].second);
        }
    }
}

int main() {

    AnBus();
    return 0;
}
