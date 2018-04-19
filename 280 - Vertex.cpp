#include <bits/stdc++.h>
using namespace std;

vector < int > v[1000];
int visited[1000];
int n;

void BFS(int source)
{
    for(int i=0;i<1000;i++) {
        visited[i] = 0;
    }
    set <int> si;
    for(int i=1;i<=n;i++) {
        si.insert(i);
    }

    queue < int > q;
    q.push(source);
    visited[source] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++) {

            int w = v[u][i];

            if(visited[w]==0) {

                visited[w] = 1;
                q.push(w);
            }
            si.erase(w);
        }
    }
    int sz = si.size();

    if(sz!=0) {

        cout << si.size() << " ";

        for(auto i=si.begin();i!=si.end();) {

            cout << *i ;
            if(++i!=si.end())
                cout << " ";
        }
        cout << endl;
    }
    else {
        cout << 0 << endl;
    }
}

int main()
{

   int node,x,call,test;

   while(cin >> n,n) {

       for(int i=0;i<1000;i++) {
           v[i].clear();
       }

       while(cin >> node,node) {

           while(cin >> x,x) {
               v[node].push_back(x);
           }
       }

       cin >> test;

       while(test--) {
           cin >> call;

           BFS(call);
       }
   }

   return 0;
}
