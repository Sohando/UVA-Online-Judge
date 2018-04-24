#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,l;
    cin >> test;

    while(test--) {
        cin >> l;

        int train[l];
        for(int i=0;i<l;i++) {
            cin >> train[i];
        }

        int swapped = 0;
        for(int i=1;i<l;i++) {

            int j = i-1;
            while(j>=0 && train[j]>train[j+1]) {
                swap(train[j],train[j+1]);
                swapped ++;
                j--;
            }
        }

        cout << "Optimal train swapping takes "<< swapped <<" swaps." << endl;
    }

    return 0;
}
