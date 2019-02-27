/**
	palindrome = 'Normal Palindrome'
	mirrored string = 'each element of the string is chaged to its reversed (If it has)'
	mirrored palindrom = 'mirrored string + palindrome'
**/
#include <bits/stdc++.h>
using namespace std;

bool is_reversed(string str) {
	int sz = str.size();
	for(int i = 0, j = sz-1; i <= j; ++i, --j) {
		if(str[i] == 'A' && str[j] != 'A' || str[i] == 'A' && str[j] != 'A') {
			return false;
		}
		else if(str[i] == 'E' && str[j] != '3' || str[i] == '3' && str[j] != 'E') {
			return false;
		}
		else if(str[i] == 'H' && str[j] != 'H' || str[i] == 'H' && str[j] != 'H') {
			return false;
		}
		else if(str[i] == 'I' && str[j] != 'I' || str[i] == 'I' && str[j] != 'I') {
			return false;
		}
		else if(str[i] == 'J' && str[j] != 'L' || str[i] == 'L' && str[j] != 'J') {
			return false;
		}
		else if(str[i] == 'M' && str[j] != 'M' || str[i] == 'M' && str[j] != 'M') {
			return false;
		}
		else if(str[i] == 'O' && str[j] != 'O' || str[i] == 'O' && str[j] != 'O') {
			return false;
		}
		else if(str[i] == 'S' && str[j] != '2' || str[i] == '2' && str[j]!= 'S') {
			return false;
		}
		else if(str[i] == 'T' && str[j] != 'T' || str[i] == 'T' && str[j] != 'T') {
			return false;
		}
		else if(str[i] == 'U' && str[j] != 'U' || str[i] == 'U' && str[j] != 'U') {
			return false;
		}
		else if(str[i] == 'V' && str[j] != 'V' || str[i] == 'V' && str[j] != 'V') {
			return false;
		}
		else if(str[i] == 'W' && str[j] != 'W' || str[i] == 'W' && str[j] != 'W') {
			return false;
		}
		else if(str[i] == 'X' && str[j] != 'X' || str[i] == 'X' && str[j] != 'X') {
			return false;
		}
		else if(str[i] == 'Y' && str[j] != 'Y' || str[i] == 'Y' && str[j] != 'Y') {
			return false;
		}
		else if(str[i] == 'Z' && str[j] != '5' || str[i] == '5' && str[j] != 'Z') {
			return false;
		}
		else if(str[i] == '1' && str[j] != '1' || str[i] == '1' && str[j] != '1') {
			return false;
		}
		else if(str[i] == '8' && str[j] != '8' || str[i] == '8' && str[j] != '8') {
			return false;
		}
		else if(str[i] == 'B' || str[i] == 'C' ||str[i] == 'D'||str[i] =='F'||str[i] =='G'||str[i] =='K'||str[i] == 'N'||str[i] == 'P'|| str[i] =='Q'|| str[i] =='R'||str[i] == '4'|| str[i] =='6'|| str[i] =='7'||str[i] == '9'){
			return false;
		}
	}
	return true;
}

bool is_palin(string str) {
	int sz = str.size();
	for(int i = 0, j = sz -1; i < j; --j, ++i) {
		if(str[i] != str[j]) {
			return false;
		}
	}
	return true;
}

bool rev_pali(string str) {
	int sz = str.size();
	for(int i = 0, j = sz -1; i < j; --j, ++i) {
		if(str[i] != str[j]) {
			return false;
		}
	}
	return true;
}
void solve() {
	string str;
	while(getline(cin, str)) {
		
		cout << str;
		if(is_reversed(str)) {
			if(rev_pali(str)) {
				printf(" -- is a mirrored palindrome.\n");
			}
			else {
				printf(" -- is a mirrored string.\n");
			}
		}
		else if(is_palin(str)) {
			printf(" -- is a regular palindrome.\n");
		}
		else {
			printf(" -- is not a palindrome.\n");
		}
		printf("\n");
	}
}

int main() {

	//freopen("in.txt", "r", stdin);

	solve();
	return 0;
}
