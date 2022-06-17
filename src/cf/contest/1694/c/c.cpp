/*
    Created by godlei at 2022-06-16 22:59:47
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 200000 + 100;

LL a[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }

    if(a[n] != 0) flag = false;
    
    for(int i = 1; i < n; i++) {
        if(a[i] < 0) {
            flag = false;
            break;
        }
        else if(a[i] == 0) {
            for(int j = i + 1; j <= n; j++)
                if(a[j] != 0) {
                    flag = false;
                    break;
                }
            break;
        }
    }

    puts(flag ? "Yes":"No");


}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}