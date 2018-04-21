#include<bits/stdc++.h>
using namespace std;

int so,de;
vector <int> v[25];
int visited[25];
int level[25];

void bfs()
{
    for(int i=0; i<25; i++)
    {
        visited[i] = 0;
        level[i] = 0;
    }
    queue <int> q;
    q.push(so);
    visited[so]=1;
    level[so] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<v[u].size(); i++)
        {
            if(visited[v[u][i]]==0)
            {
                visited[v[u][i]]=1;
                level[v[u][i]] = level[u]+1;

                q.push(v[u][i]);
            }
        }

    }
}

int main()
{
    
    int how,are,k=0,cases=1;

    while(cin>>how)
    {
        for(int i=0; i<25; i++)
        {
            v[i].clear();
        }

        while(how--) {
            cin >> are;
            v[1].push_back(are);
            v[are].push_back(1);
        }

        for(int i=2; i<=19; i++)
        {
            cin >> how;
            while(how--)
            {
                cin >> are;

                v[i].push_back(are);
                v[are].push_back(i);
            }
        }
        printf("Test Set #%d\n",cases++);
        cin >> how;
        while(how--)
        {
            cin >> so >> de;
            bfs();
            printf("%2d",so);
            printf(" to ");
            printf("%2d",de);
            printf(": ");
            printf("%1d\n",level[de]-level[so]);

        }
        cout << endl;
    }

    return 0;
}
