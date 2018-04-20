#include<bits/stdc++.h>
using namespace std;
map <string, vector<string> > v;
string so,de;

void bfs()
{
    map <string,int> visited;
    map <string,string> parent;
    bool f = false;

    queue <string> q;
    q.push(so);
    visited[so] = 1;
    parent[so] = "-1";

    while(!q.empty())
    {
        string top = q.front();
        q.pop();

        for(int i=0; i<v[top].size(); i++)
        {

            if(visited[v[top][i]]==0)
            {
                visited[v[top][i]] = 1;
                parent[v[top][i]] = top;
                q.push(v[top][i]);
            }

            if(v[top][i]==de)
            {
                f = true;
            }

        }
    }

    if(f)
    {
        stack <string> ss;

        while(de!="-1")
        {
            ss.push(de);
            de = parent[de];
        }

        while(!ss.empty())
        {
            cout << ss.top();
            ss.pop();

            if(!ss.empty()) cout << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "connection impossible" << endl;
    }

}
int main()
{

    int n,call,t=0;
    string str;

    while(cin >> n)
    {
        if(t==1) {
            cout << "-----" << endl;
        }
        v.clear();
        getchar();

        while(n--)
        {
            getline(cin,str);

            string s="",main;
            for(int i=0; i<=str.size(); i++)
            {

                if(str[i]=='-')
                {
                    main = s;
                    s = "";
                    i++;
                }
                else if(str[i]==',' || str[i]=='\0')
                {
                    v[main].push_back(s);

                    s="";
                    i++;
                }

                if(str[i]!=' ')
                    s+=str[i];
            }

        }
        cin >> call;
        getchar();

        cout << "-----" << endl;
        while(call--)
        {
            cin >> so >> de;

            bfs();
        }

    }
    return 0;
}
