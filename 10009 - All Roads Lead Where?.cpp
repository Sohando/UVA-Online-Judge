#include<bits/stdc++.h>
using namespace std;

map<string, vector<string> > _love;
map<string,string> parent;
map<string,int> visited;

string so,de;

void bfs(string s)
{
    queue <string> qs;
    qs.push(s);
    visited[s] = 1;
    parent[s] = "*";

    while(!qs.empty()) {
        string u = qs.front();
        qs.pop();

        for(int i=0;i<_love[u].size();i++) {
            if(!visited[_love[u][i]]) {
                visited[_love[u][i]] = 1;
                parent[_love[u][i]] = u;
                qs.push(_love[u][i]);

                if(_love[u][i]==de) return;
            }
        }
    }
}

int main()
{

    int t,_naf,_sin,l=0;
    string _sub,_na;

    scanf("%d",&t);

    while(t--)
    {
        if(l==1) cout << endl;
        scanf("%d %d",&_naf,&_sin);
        getchar();
        stack <char> st;

        for(int i=0;i<_naf;i++) {
            cin >> _sub >> _na;
            _love[_sub].push_back(_na);
            _love[_na].push_back(_sub);
        }

        for(int i=0;i<_sin;i++) {
            cin >> so >> de;
            bfs(so);

            while(de!="*") {
                st.push(de[0]);
                de = parent[de];
            }
            
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << endl;
            visited.clear();
            parent.clear();
        }
        l=1;
        _love.clear();
    }
    return 0;
}
