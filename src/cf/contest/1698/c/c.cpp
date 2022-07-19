/*
    Created by godlei at 2022-06-28 22:47:24
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;

int a[maxn];

void solve() {
    int n, m;
    scanf("%d", &n);

    m = 0;
    int cnt0 = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if(a[i] != 0) m++;
        else cnt0++;
    }

    if(m >= 10) {
        printf("NO\n");
        return;
    } 


    
    multiset<int> vis;
    vector<int> nums;
    for(int i = 1; i <= n; i++) {
        if(a[i] != 0) {
            nums.push_back(a[i]);
            vis.insert(a[i]);
        }
    }

    if(cnt0) {
        nums.push_back(0);
        vis.insert(0);
    }

    m = nums.size();

    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            for(int k = j + 1; k < m; k++) {
                long long t = 0ll + nums[i] + nums[j] + nums[k];
                if(!vis.count(t)) {
                    printf("NO\n");
                    //printf("%d %d %d %lld\n", nums[i], nums[j], nums[k], t);
                    return;
                }
            }
        }
    }
    printf("YES\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
