#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
int arr[10001];
int counter[10001];

void _baby() {

    prime.push_back(2);

    for(int i=4;i<=10000;i+=2) arr[i] = 1;

    for(int i=3;i<=10000;i+=2) {
    	if(arr[i]==0) {
    		prime.push_back(i);
    		for(int j=i*i;j<=10000;j+=i+i) {
    			arr[j] = 1;
    		}
    	}
    }

    for(int i=2;i<=10000;i++) {

        int _nafsin = 0,_subna = 0;

        if(!arr[i]) _nafsin++;

        for(int j=0;prime[j]<=i/2;j++) {
            _subna = 0;
            for(int k=j;prime[k]<=i;k++) {

                _subna += prime[k];

                if(_subna==i)  {
                    _nafsin++;
                    break;
                }
                else if(_subna>i) break;
            }
        }
        counter[i] = _nafsin;

        //cout << i << " " << counter[i] << endl;
    }

    return;
}

int main() {

	_baby();

	int n;

	while(scanf("%d",&n)==1,n) {
        printf("%d\n",counter[n]);
	}

	return 0;
}
