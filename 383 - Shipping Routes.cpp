#include <bits/stdc++.h>
using namespace std;
map < string, vector<string> > v ;
string so,de;
map <string,int> visited;
map <string,int> level;

bool bfs()
{
    level.clear();
    visited.clear();

    int flag = 0;
    queue<string> q;

    q.push(so);
    visited[so] = 1;
    level[so] = 1;

    while(!q.empty()) {
        string s = q.front();
        q.pop();
        //cout  << s << "->" ;
        for(int i =0;i < v[s].size(); ++i) {

            //cout << v[s][i] <<" ->";
            if(!visited[v[s][i]]) {

                visited[v[s][i]] = 1;
                q.push(v[s][i]);
                level[v[s][i]] = level[s]+1;

                if(v[s][i]==de) {
                flag = 1;
                }
            }

        }
        //cout << endl;
    }
    if(flag==0) return false;

    return true;
}

int main()
{
    int t,n,m,p,cases=1,price,k=1;
    string str,str1;

    cin >> t;

    cout << "SHIPPING ROUTES OUTPUT" << endl << endl;
    while(t--) {
        v.clear();

        cout <<"DATA SET  " << cases++ << endl << endl;

        cin >> n >> m >> p;
        getchar();

        while(n--) {

            cin >> str;
        }

        while(m--) {

            cin >> str >> str1;

            v[str].push_back(str1);
            v[str1].push_back(str);

        }

        while(p--) {
            cin >> price;
            getchar();
            cin >> so >> de;

            if(bfs()) {
                cout <<"$"<< (level[de] - level[so]) * 100 * price << endl;
            }
            else {
                cout << "NO SHIPMENT POSSIBLE" << endl;
            }
        }
        cout << endl;
    }
    cout << "END OF OUTPUT" << endl ;
    return 0;
}

