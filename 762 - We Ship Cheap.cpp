#include<bits/stdc++.h>
using namespace std;
map <string, vector<string> > v;

string se,de;

void bfs()
{
    map <string,string> parent;
    map <string,int> visited;
    bool f = false;

    queue <string> q;
    q.push(se);
    visited[se] = 1;
    parent[se] = "-1";

    while(!q.empty()) {

        string s = q.front();
        q.pop();

        for(int i=0;i<v[s].size();i++) {
            if(visited[v[s][i]]==0) {

                q.push(v[s][i]);
                visited[v[s][i]] = 1;
                parent[v[s][i]] = s;
            }
        }

        if(s==de) {
            f=true;
        }
    }

    if(f) {
        stack <string> ss;
        while(parent[de]!="-1") {
            ss.push(de);
            de = parent[de];
            //ss.push(de);

            //if(parent[de]=="-1") {
            ss.push(de);
            //}
        }

        while(!ss.empty()) {
            cout << ss.top();
            ss.pop();

            if(!ss.empty()) {
                cout << " " << ss.top() << endl;
                ss.pop();
            }
            else {
                cout << endl;
            }
        }
    }
    else {
        cout << "No route" << endl;
    }

}

int main()
{
    int l = 0;
    int check;
    string s,d;

    while(cin >> check) {
        getchar();
        v.clear();
        if(l==1) cout << endl;

        while(check--) {
            cin >> s >> d;

            v[s].push_back(d);
            v[d].push_back(s);
        }
        cin >> se >> de;

        bfs();
        l=1;
    }

    return 0;
}
