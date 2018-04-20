#include<bits/stdc++.h>
using namespace std;

vector <int> v[3000];
bool visited[3000];
int day[3000];
int level[3000];

void bfs(int source)
{
    for(int i=0;i<3000;i++) {
        visited[i] = false;
        day[i] = 0;
        level[i] = 0;
    }

    queue <int> q;
    q.push(source);
    visited[source] = true;
    level[source] = 0;

    int sum = 0,m = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i = 0; i < v[u].size();i++) {
            if(visited[v[u][i]]==false) {

                q.push(v[u][i]);
                visited[v[u][i]] = true;
                level[v[u][i]] = level[u]+1;

                int lev = level[v[u][i]];

                day[lev]++;

                if(day[lev]>sum) {
                    sum = day[lev];
                    m = level[v[u][i]];
                }
            }
        }
    }

    if(m!=0)
        cout << sum << " " << m << endl;
    else
        cout << 0 << endl;
}

int main()
{
    int node,friends,he;

    cin >> node;

    int man = 0;
    while(node--) {
        cin >> friends;

        while(friends--) {
            cin >> he;

            v[man].push_back(he);
        }
        man++;
    }

    int test,call;
    cin >> test;
    while(test--) {
        cin >> call;

        bfs(call);
    }

    return 0;
}
