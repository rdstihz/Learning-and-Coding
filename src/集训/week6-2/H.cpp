#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

const int maxn = 100000 + 100;

LL a[maxn];
LL dp[maxn];

deque<int> Q;

int main() {

    int n, k;
    cin >> n >> k;
    LL S = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S += a[i];
    }

    dp[0] = 0;

    Q.push_back(0);

    for (int i = 1; i <= n + 1; i++) {
        if (Q.size() && Q.front() < i - k - 1) Q.pop_front();
        dp[i] = dp[Q.front()] + a[i];

        while (Q.size() && dp[Q.back()] > dp[i]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    cout << S - dp[n + 1] << endl;
    return 0;
}
