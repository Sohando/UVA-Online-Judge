#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int a,b,c;
	
	cin >> n;
	while(n--) {
		cin >> a >> b >> c;
		bool flag=false;
		for(int x=-100;x<=sqrt(c)+1;x++) {
			for(int y=x+1;y<=sqrt(c)+1;y++) {
				for(int z=y+1;z<=sqrt(c)+1;z++) {
					
					if(x+y+z==a && x*y*z==b && x*x+y*y+z*z==c) {
						flag=true;
						cout << x << " " << y << " " << z << endl;
						break;
					}
					if(flag) break;
				}
				if(flag) break;
			}
		}
		if(!flag) {
			cout << "No solution." << endl;
		}
	}
	
	return 0;
}
