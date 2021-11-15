/*
    Created by rdstihz at 2021-11-15 22:14:03
*/

#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> PII;
const int maxn = 3000;
int a[maxn], b[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for(int i = 1; i <= n; i++)
        scanf("%d", b + i);
    
    vector<PII> ans;
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        while(a[i] > b[i]) {
            int j = i + 1;
            while(a[j] > a[i] || a[j] < b[i])
                j++;
            ans.push_back(make_pair(i, j));
            swap(a[i], a[j]);
        }
        if(a[i] < b[i]) {
            flag = false;
            break;
        }
    }

    if(!flag) {
        printf("-1\n");
    }else {
        printf("%d\n", int(ans.size()));
        for(auto x : ans)
            printf("%d %d\n", x.first, x.second);
    }

}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}