/*
    Created by godlei at 2022-06-28 23:21:29
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000 + 10;

int a[maxn];

void ask(int l,int r) {
    printf("? %d %d\n", l, r);
    fflush(stdout);

    for(int i = l; i <= r; i++)
        scanf("%d", a + i);
}

void answer(int x) {
    printf("! %d\n", x);
    fflush(stdout);
}


bool check(int l,int r) {
    ask(l, r);
    int cnt = 0;
    for(int i = l; i <= r; i++) {
        if(a[i] >= l && a[i] <= r) cnt++;
    }
    return cnt % 2;
}

void solve() {
    int n;
    scanf("%d", &n);

    int L = 1, R = n;
    int M;
    while(L < R) {
        M = L + R >> 1;
        if(check(L, M)) R = M;
        else L = M + 1;
    }
    answer(L);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}