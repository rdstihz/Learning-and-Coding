#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int maxn = 100000 + 10;

PII a[maxn];
int n;

int main() {
    cin >> n;
    int t = 0; //总及格人数
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        t += a[i].second;
    }
    sort(a + 1, a + 1 + n);

    int ans, maxv = -1;
    int cnt = 0; //当前扫描到的及格人数
    for (int i = 1; i <= n;) {
        int val = (i - 1 - cnt) + (t - cnt);
        if (val >= maxv) {
            maxv = val;
            ans = a[i].first;
        }
        do {
            cnt += a[i].second;
            i++;
        } while (i <= n && a[i].first == a[i - 1].first);
    }
    cout << ans << endl;
    return 0;
}