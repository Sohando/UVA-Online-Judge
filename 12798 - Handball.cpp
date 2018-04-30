#include<stdio.h>

int main()
{
	int n,m,x,i;
	
	while(scanf("%d %d",&n,&m)==2) {
		
		int player=0;
		while(n--) {
			int f = 1;
			for(i=0;i<m;i++) {
				scanf("%d",&x);
				if(x==0) f=0;
			}
			if(f) {
				player++;
			}
		}
		printf("%d\n",player);
	}
	
	return 0;
}
