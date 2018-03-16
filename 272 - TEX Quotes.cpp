#include<bits/stdc++.h>
using namespace std;

int main()
{

    char ch;
    int flag1=0;

    while(scanf("%c",&ch)==1)
    {

        if(ch=='\n'){
            cout<<endl;
        }
        else if(ch=='"' && flag1==0){
            cout<<"``";
            flag1=1;
        }
        else if(ch=='"' && flag1==1){
            cout<<"''";
            flag1=0;
        }
        else{
            cout<<ch;
        }
    }

    return 0;
}
