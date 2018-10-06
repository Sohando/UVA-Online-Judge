#include <stdio.h>
#include<string.h>
char Array[1007];

int bhagsesh(int val) {
	int bs = 0;
	int sz = strlen(Array);
	int i;
	
	for(i=0; i<sz; i++) {
		bs = ((bs*10) + Array[i]-'0') % val;
	}
	return bs;
}

int main(void) {
	
	int n;
	scanf("%d", &n);
	
	while(n--) {
		getchar();
		scanf("%s", &Array);
		
		int t;
		scanf("%d", &t);
		
		int foo = 0, m;
		while(t--) {
			scanf("%d", &m);
			if(bhagsesh(m)) {
				foo = 1;
				
			}
		}
		if(foo) {
			printf("%s - Simple.\n", Array);
		}
		else {
			printf("%s - Wonderful.\n", Array);
		}
	}
	return 0;
}
