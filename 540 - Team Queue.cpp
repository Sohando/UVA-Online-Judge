#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);

    long long int t,t_n,n,number,cases=1;
    string s;

    while(scanf("%lld",&t)==1,t){

       queue <long long int> T_Q;
       queue <long long int> Q[t+1];
       map < long long int,long long int > ma;
       map < long long int,bool> ba;

       long long int team = 0;

       printf("Scenario #%lld\n",cases++);
       while(t--){

            team++;
            scanf("%lld",&number);

            while(number--){

                scanf("%lld",&t_n);
                ma[t_n] = team;
             }
       }
       getchar();

       while(cin >> s){
			getchar();

            if(s=="STOP") break;

            else if(s=="ENQUEUE"){

                scanf("%lld",&n);
                getchar();

                if(!Q[ma[n]].empty()){

                    Q[ma[n]].push(n);
                }
                else{

                    Q[ma[n]].push(n);

                    T_Q.push(ma[n]);
                }
            }
            else{

                int u = T_Q.front();

                while(Q[u].empty()){

                    T_Q.pop();

                    u = T_Q.front();
                }

                long long int v = Q[u].front();
                printf("%lld\n",v);

                Q[u].pop();
            }
       }
       printf("\n");
    }

    return 0;
}
