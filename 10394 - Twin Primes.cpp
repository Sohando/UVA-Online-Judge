#include <bits/stdc++.h>
using namespace std;

long long int prime[20000000+1];
map <int, pair<int,int> > ma;

void _baby_sieve()
{

	prime[0]=1;
	prime[1]=1;

	for(int i=4;i<=20000000;i+=2) prime[i]=1;

	for(int i=3;i*i<=20000000;i+=2) {

		if(prime[i]==0) {
			for(int j=i*i;j<=20000000;j+=i+i) {

				prime[j]=1;
			}
		}
	}

	int _eto=1;
	for(int i=3;i<=20000000;i++) {
		if(prime[i]==0 && prime[i+2]==0) {
			ma[_eto++] = make_pair(i,i+2);
			i++;
		}
	}
}

int main() {

	_baby_sieve();

	int _koto;

	while(scanf("%d",&_koto)==1) {
		printf("(%d, %d)\n",ma[_koto].first,ma[_koto].second);

	}

	return 0;
}


