#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    map <string,string> ma;
    while(getline(cin,s) && s!="\0"){

        //cout << s <<endl;
        int sz = s.size();
        string temp="",ans="";

        for(int i=0;i<sz;i++)
        {
            if(s[i]==' '){
                temp = ans;
                ans="";
            }
            else{
                ans+=s[i];
            }
        }

        ma[ans] = temp;
    }

    map <string ,string > :: iterator it;
    while(cin>>s){

        if(ma[s]!="") cout<<ma[s]<<endl;
        else cout<<"eh"<<endl;
    }

    return 0;
}
