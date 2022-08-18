/*
    Created by rdstihz at 2022-08-17 00:01:46
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
int a[maxn];
int s[maxn];



void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        s[i] = s[i - 1] ^ a[i];
    }
    
    set<int> S;
    S.insert(0);
    int ans = n;

    for(int i = 1; i <= n; i++) {
        if(S.count(s[i])) {
            ans--;
            S.clear();
            S.insert(s[i]);

        }else {
            S.insert(s[i]);
        }
    }

    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}