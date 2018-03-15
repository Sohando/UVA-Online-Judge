#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,instruction,element,st,qu,pri,i,j,l,k,m;

    while(scanf("%d",&n)==1)
    {

        st=1,qu=1,pri=1,i=-1,j=0,k=1,l=-1,m=-1;

        int stac[1010]={0},prio[1010]={0},que[1010]={0};

        while(n--)
        {
            scanf("%d %d",&instruction,&element);

            if(instruction==1)
            {
                i++;
                l++;
                m++;
                stac[i] = element;
                que[m] = element;
                prio[l] = element;

            }
            else
            {
                sort(prio,prio+l+1);

                if(que[j]!=element) { qu=0; }
                else j++;

                if(stac[i]!=element) { st=0; }
                else i--;

                if(prio[l]!=element) { pri=0; }
                else { l--; }

            }
        }

        if(st && qu || st && pri || qu && pri || st && pri && qu)
        {
            printf("not sure\n");
        }
        else if(st)
        {
            printf("stack\n");
        }
        else if(qu)
        {
            printf("queue\n");
        }
        else if(pri)
        {
            printf("priority queue\n");
        }
        else
        {
            printf("impossible\n");
        }
    }

    return 0;
}
