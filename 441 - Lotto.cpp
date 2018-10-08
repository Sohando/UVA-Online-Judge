#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, A[50], indicator = 0;
	while(cin >> n, n) {
		if(indicator == 1)
			cout << endl;
		for(int i=0; i<n; i++) {
			cin >> A[i];
		}
		
		for(int i=0; i<n-5; i++) {
			for(int j=i+1; j<n; j++) {
				for(int k=j+1; k<n; k++) {
					for(int l=k+1; l<n; l++) {
						for(int m=l+1; m<n; m++) {
							for(int p=m+1; p<n; p++)
							cout << A[i] << " " << A[j] << " " << A[k] << " " << A[l] << " " << A[m] << " " << A[p] << endl;
						}
					}
				}
			}
		}
		indicator = 1;
	}
	return 0;
}
