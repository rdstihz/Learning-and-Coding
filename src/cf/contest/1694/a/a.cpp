/*
    Created by godlei at 2022-06-16 22:37:15
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    while(a || b) {
        if(a) {
            printf("0");
            a--;
        }
        if(b) {
            printf("1");
            b--;
        }
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}