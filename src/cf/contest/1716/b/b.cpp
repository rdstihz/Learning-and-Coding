/*
    Created by godlei at 2022-08-04 22:44:45
*/

#include <bits/stdc++.h>

using namespace std;

int a[1000];

void print(int n) {
    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void solve() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }

    printf("%d\n", n);
    print(n);

    for(int i = n; i > 1; i--) {
        swap(a[i], a[i - 1]);
        print(n);
    }

}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}