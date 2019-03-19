#include<bits/stdc++.h>
using namespace std;

map<int, vector<string>> Graph;
map<string, bool> vis;
map<string, int> level;

void clear_(int sz) {
    int x = Graph[sz].size();

    for(int i = 0; i < x; ++i) {
        vis[Graph[sz][i]] = false;
        level[Graph[sz][i]] = 0;
    }
}

void _clear() {
    Graph.clear();
}
bool check(string str, string ptr) {
    int cnt = 0, sz = str.size();
//cout << str << " Checked " << ptr << endl;
    for(int i = 0; i < sz; ++i) {
        if(str[i] != ptr[i]) {
            cnt++;
        }
        if(cnt > 1) {
            return false;
        }
    }

    return true;
}
int BFS(string str, string ptr) {
    int x = str.size();
//    cout << x << endl;
    int sz = Graph[x].size();
//    cout << sz << endl;
    int cnt = 0;
//cout << ptr << endl;
    queue<string>Q;
    Q.push(str);
    level[str] = 0;
    vis[str] = true;

    while(!Q.empty()) {
        string frnt = Q.front(); Q.pop();
//cout << frnt << " vis = " << vis[frnt]  << endl;
//cout << "hmm" << endl;
        for(int i = 0; i < sz; ++i) {
//            cout << Graph[x][i] << endl;
            if(!vis[Graph[x][i]] && check(frnt, Graph[x][i])) {
//                    cout << "dukce" << endl;
                Q.push(Graph[x][i]);
                level[Graph[x][i]] = level[frnt] + 1;
                vis[Graph[x][i]] = true;
                if(Graph[x][i] == ptr) {
                    return level[ptr];
                }
            }
//cout << "Bhul koi" << endl;
        }
//        cout << "hmm" << endl;
    }
}

int main() {
//    freopen("test_case.txt", "r", stdin);

    int test, k = 0;
    string str, ptr, ctr;
    scanf("%d", &test);
    getchar();

    while(test--) {
        if(k == 1) printf("\n");
        k = 1;
        while(cin >> ctr, ctr != "*") {
//            cout << ctr << endl;
            int sz = ctr.length();
            Graph[sz].push_back(ctr);
        }
        getchar();
        while(getline(cin, ctr), ctr != "") {
//                cout << ctr << endl;
            int i; str = "", ptr = "";
            for(i = 0; ctr[i] != ' '; ++i) {
                str += ctr[i];
            }
            ++i;
            for(; ctr[i] != '\0'; ++i) {
                ptr += ctr[i];
            }
//        cout << str << ptr << endl;
            int ans = BFS(str, ptr);
//            cout << ans << endl;
            cout << str << " " << ptr << " " << ans;
            printf("\n");
            clear_(str.length());
        }
        _clear();
//        printf("\n");
    }
    return 0;
}

/*
    Approach
    ~ Take Input (#)
    ~ Make Graph (?)
*/
