#include<bits/stdc++.h>
using namespace std;

map<string,int> ma;

void _boss_baby()
{
    string s;
    int k=1;
    for(char i='a';i<='z';i++) {
        s+=i;
        ma[s] = k++;
        s="";
    }
    for(char i='a';i<='z';i++) {

        for(char j=i+1;j<='z';j++) {
            s+=i;
            s+=j;
            ma[s] = k++;
            s="";
        }
        s="";
    }
    for(char i='a';i<='z';i++) {

        for(char j=i+1;j<='z';j++) {

            for(int l=j+1;l<='z';l++) {
                s+=i;
                s+=j;
                s+=l;

                ma[s] = k++;
                s="";
            }
        }
    }
    for(char i='a';i<='z';i++) {

        for(char j=i+1;j<='z';j++) {

            for(int l=j+1;l<='z';l++) {

                for(int m=l+1;m<='z';m++) {
                    s+=i;
                    s+=j;
                    s+=l;
                    s+=m;

                    ma[s] = k++;
                    s="";
                }
            }
        }
    }
    for(char i='a';i<='z';i++) {

        for(char j=i+1;j<='z';j++) {

            for(int l=j+1;l<='z';l++) {

                for(int m=l+1;m<='z';m++) {

                        for(int n=m+1;n<='z';n++) {
                        s+=i;
                        s+=j;
                        s+=l;
                        s+=m;
                        s+=n;

                        ma[s] = k++;
                        s="";
                    }
                }
            }
        }
    }
}

int main()
{
    _boss_baby();

    string s;
    while(cin >> s) {
        cout << ma[s] << endl;
    }

    return 0;
}
