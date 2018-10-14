#include <bits/stdc++.h>
using namespace std;

int digit[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

int solve(int n) {
      if(n  < 10) {
            return digit[n];
      }
      if(((n / 10) % 10) % 2 == 0) {
            return (6 * solve(n / 5) * digit[n % 10]) % 10;
      }
      else {
            return (4 * solve(n / 5) * digit[n % 10]) % 10;
      }
}

int main() {
      int n;
      while(scanf("%d", &n) == 1)  {
            printf("%5d -> %d\n", n, solve(n));
      }
      return 0;
}
