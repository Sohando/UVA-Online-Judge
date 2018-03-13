#include <stdio.h>

int main(void) 
{
     int test;
     char c;
     
     scanf("%d",&test);
     getchar();
     
     while(test--){
     	
     	int cou=0,co=0;
     	while(scanf("%c",&c)==1 && c!='\n'){
     	     if(c=='O'){
     	     	co++;
     	     }
     	     else{
     	     	co=0;
     	     }
     	     cou+=co;
     	}
     	printf("%d\n",cou);
     }
     
      return 0;
}
