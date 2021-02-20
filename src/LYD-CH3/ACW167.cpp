#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int maxl, minl;
int n;
int cnt[55];

bool dfs(int rest, int cur, int last, int target) {
    if (rest == 0) {
        return true;
    }

    if (cur == target) {
        return dfs(rest - 1, 0, maxl, target);
    }

    for(int i = last; i >= minl;i--) {
        if(cnt[i] && cur + i <= target) {
            cnt[i]--;
            if(dfs(rest,cur + i, i, target)) return true;
            cnt[i]++;

            if(cur == 0 || cur + i == target) break;

        }

    }

    return false;
}

int main() {

    while (cin >> n && n) {
        int v;
        minl = 100;
        maxl = 0;
        memset(cnt, 0, sizeof(cnt));
        int S = 0;
        for (int i = 1; i <= n; i++) {
            cin >> v;
            cnt[v]++;
            minl = min(minl, v);
            maxl = max(maxl, v);
            S += v;
        }

        for (int i = maxl;; i++)
            if (S % i == 0) {
                if (dfs(S / i, 0, maxl, i)) {
                    cout << i << endl;
                    break;
                }
            }
    }

    return 0;
}