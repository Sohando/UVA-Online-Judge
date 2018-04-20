
#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    string str;
    cin >> n;
    getchar();
    
    while(n--) {
       cin >> str;
       
       sort(str.begin(),str.end());

       cout << str << endl;
       
       while(next_permutation(str.begin(),str.end())) {
            	cout << str << endl;
       }

       cout << endl;
    }
    
    return 0;
}
