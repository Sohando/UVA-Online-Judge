#include<bits/stdc++.h>
using namespace std;

int main() {

	int test,n,m;
	pair<int,int>de;

	scanf("%d",&test);

	while(test--) {
		queue< pair<int,int> > q;
		priority_queue<int> pq;

		scanf("%d %d",&n,&m);

		for(int i=0, x;i<n;i++) {
			scanf("%d",&x);
			q.push(make_pair(x,i));
			pq.push(x);
		}

		int ans=0;
		while(!q.empty()) {

            if(q.front().first==pq.top()) {
                ans++;
                if(q.front().second==m) {
                    break;
                }
                q.pop();
                pq.pop();
            }
            else {
                de.first = q.front().first;
                de.second = q.front().second;
                q.pop();
                q.push(de);
            }
		}
		printf("%d\n",ans);
	}

	return 0;
}
