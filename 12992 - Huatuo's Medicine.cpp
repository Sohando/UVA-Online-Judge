#include <stdio.h>

int main(void) 
{
     int test;
     int c,cases=1;
     
     scanf("%d",&test);
    
     while(test--){
     	scanf("%d",&c);
     	printf("Case #%d: %d\n",cases++,2*c-1);
     }
     
      return 0;
}
