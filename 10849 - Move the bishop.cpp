#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long int c, t, n;
    long long int r1, c1, r2, c2, new_r, new_c;
    scanf("%lld", &c);
    while(c--) {
        scanf("%lld %lld", &t, &n);

        for(int i = 0; i < t; ++i) {
            scanf("%lld %lld %lld %lld", &r1, &c1, &r2, &c2);

            
            if(r1 == r2 && c1 == c2) {
                printf("0\n");
            }
            else if((r1 + c1) == (r2 + c2) || (r1 - c1) == (r2 - c2)) {
                printf("1\n");
            }
            else {
                // int new_r = r1 - 1;
                // int new_c = c1;

                // if(valid(new_r, new_c, n) && (new_r + new_c) == (r2 + c2) || (new_r - new_c) == (r2 - c2)) {
                //     printf("no move\n");
                //     continue;
                // }

                // new_r = r1 + 1;
                // new_c = c1;

                // if(valid(new_r, new_c, n) && (new_r + new_c) == (r2 + c2) || (new_r - new_c) == (r2 - c2)) {
                //     printf("no move\n");
                //     continue;
                // }

                // new_r = r1;
                // new_c = c1 - 1;

                // if(valid(new_r, new_c, n) && (new_r + new_c) == (r2 + c2) || (new_r - new_c) == (r2 - c2)) {
                //     printf("no move\n");
                //     continue;
                // }

                // new_r = r1;
                // new_c = c1 + 1;

                // if(valid(new_r, new_c, n) && (new_r + new_c) == (r2 + c2) || (new_r - new_c) == (r2 - c2)) {
                //     printf("no move\n");
                //     continue;
                // }

                // printf("2\n");
                int b = 0;
                for(int j = r1, k = c1; j > 1; --j, --k) {
                    new_r = j - 1;
                    new_c = k - 1;

                    if((new_r + new_c) == (r2 + c2) || (new_r - new_c) == (r2 - c2)) {
                        printf("2\n");
                        b = 1;
                        break;
                    }
                }
                if(!b) {
                    for(int j = r1, k = c1; j < n; ++j, ++k) {
                        new_r = j + 1;
                        new_c = k + 1;

                        if((new_r + new_c) == (r2 + c2) || (new_r - new_c) == (r2 - c2)) {
                            printf("2\n");
                            b = 1;
                            break;
                        }
                    }
                }
                if(!b) {
                	for(int j = r1, k = c1; k < n && j > 1; --j, ++k) {
                        new_r = j - 1;
                        new_c = k + 1;

                        if((new_r + new_c) == (r2 + c2) || (new_r - new_c) == (r2 - c2)) {
                            printf("2\n");
                            b = 1;
                            break;
                        }
                    }
                }
                if(!b) {
                	for(int j = r1, k = c1; j < n && k > 1; ++j, --k) {
                        new_r = j + 1;
                        new_c = k - 1;

                        if((new_r + new_c) == (r2 + c2) || (new_r - new_c) == (r2 - c2)) {
                            printf("2\n");
                            b = 1;
                            break;
                        }
                    }
                }
                if(!b) {
                    printf("no move\n");
                }
            }
//            int ans = BFS(r1, c1, r2, c2);
        }
    }
}

int main() {
//    freopen("test_case.txt", "r", stdin);

    solve();
    return 0;
}

/*
    Approach

    ~ check if already diagonal ( check (r1 + c1) == (r2 + c2) )
    ~ check if already diagonal ( check abs(r1 - c1) == abs(r2 - c2) )
    ~ check for 4 adjacent side's diagonal
    New Thought

    ~ Graph
*/
