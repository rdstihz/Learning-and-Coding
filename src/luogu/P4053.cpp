#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
priority_queue<PII> Q;

int main() {
    int n;
    cin >> n;
    LL t1, t2;
    LL cur = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t1 >> t2;
        cur = max(cur, t2);
        Q.push(make_pair(t2 - t1, t2));
    }
    LL ans = 0;
    while (Q.size()) {
        PII p = Q.top();
        Q.pop();
        if (p.second > cur) {
            LL t = p.second - cur;
            if(p.first - t >= 0)
                Q.push(make_pair(p.first - t, p.second - t));
            continue;
        }
        ans++;
        cur = p.first;
    }
    cout << ans << endl;
    return 0;
}