
#include <bits/stdc++.h>
using namespace std;

// Returns the number of digits present
// in n! Since the result can be large
// long long is used as return type
long long findDigits(int n)
{
	// base case
	if (n <= 1)
		return 1;

	// Use Kamenetsky formula to calculate
	// the number of digits
	
	// formula is (n/e)^n*sqrt(2*pi*n)
	// taking log10() we get log10((n/e)^n*sqrt(2*pi*n))
	// which leads to ((n * log10(n / M_E) + log10(2 * M_PI * n) /2.0));
	
	double x = ((n * log10(n / M_E) +
				log10(2 * M_PI * n) /
				2.0));

	return floor(x) + 1;


}

// Driver Code
int main()
{
    int n,t;
    scanf("%d",&n);

    while(n--) {
        scanf("%d",&t);
        cout << findDigits(t) << endl;
    }
	return 0;
}
