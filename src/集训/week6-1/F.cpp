#include <iostream>

using namespace std;

const int maxn = 200000 + 100;

int cnt[100], cnt2[100];
int last[100];

int main() {
    int n, k, p;

    cin >> n >> k >> p;

    int cur = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (b <= p) cur = i;

        if (cur >= last[a])
            cnt2[a] = cnt[a];

        ans += cnt2[a];
        cnt[a]++;
        last[a] = i;
    }
    cout << ans << endl;
    
    
    return 0;
}