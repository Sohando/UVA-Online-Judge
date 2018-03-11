#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define maxi 100000

void binary(int a)
{
    ll ans[maxi],i=0;

    while(a!=0){
       ans[i++] = (a%2);
       a/=2;
    }

    if(i<13){
        while(i<13){
            ans[i++] = 0;
        }
    }

    for(int j=12;j>=0;j--){
        printf("%lld",ans[j]);
    }

    return;
}
int decimal(string str)
{
    ll sz=str.size(),a=0,b=0,l=0;
    l=sz-1;

    for(int i=0; i<sz; i++){
        if(str[i]>='A' && str[i]<='F'){
            a = (str[i]-65)+10;
        }
        else{
        	a = str[i]-'0';
        }
        b += a*pow(16,l--);

    }

    return b;
}

void xplus(string first,string second){

     int a= decimal(first);
     int b= decimal(second);

     binary(a);
     printf(" + ");
     binary(b);
     printf(" = %lld\n",a+b);

     return;
}

void xminus(string first,string second){

     ll a= decimal(first);
     ll b= decimal(second);

     binary(a);
     printf(" - ");
     binary(b);
     printf(" = %lld\n",a-b);

     return;
}

int main() {

    ll n,ans;

    string s,ch,s2;

    while(scanf("%lld",&n)==1){
         getchar();

         while(n--){
           cin>>s>>ch>>s2;

           if(ch=="+"){
          	  xplus(s,s2);
           }
           else{
        	xminus(s,s2);
           }
         }
    }

    return 0;
}
