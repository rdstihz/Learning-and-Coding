/*
    Created by rdstihz at 2022-08-16 22:56:55
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 100000 + 100;

int a[maxn];
vector<int> v[maxn];
void solve() {
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    
    int cur = 1, tot;
    for(int i = 2; i <= n; i++) {
        if(a[i] > a[cur]) {
            cur = i;
            v[i].push_back(i - 1);
            if(a[i] == n) {
                tot = i - 1;
                break;
            }
        }else {
            v[cur].push_back(i - 1);
        }
    }

    while(q--) {
        int i, k;
        scanf("%d%d", &i, &k);

        if(a[i] != n || a[i] == n && k <= tot) {
            int ans = upper_bound(v[i].begin(), v[i].end(), k) - v[i].begin();
            printf("%d\n", ans);
        }else {
            int ans = k - tot + v[i].size();
            printf("%d\n", ans);
        }


    }

    for(int i = 0; i <= n; i++)
        v[i].clear();

}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}