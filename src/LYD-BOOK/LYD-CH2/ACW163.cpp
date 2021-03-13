#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int maxn = 100000 + 100;

int d[maxn];
int l[maxn], r[maxn];

void remove(int x) {
    r[l[x]] = r[x];
    l[r[x]] = l[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    int k = 1;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x * d[k] < 0)
            d[++k] = x;
        else
            d[k] += x;
    }
    n = k;

    int cnt = 0;
    int res = 0;

    for (int i = 1; i <= n; i++)
        if (d[i] > 0) {
            res += d[i];
            cnt++;
        }

    for (int i = 1; i <= n; i++) {
        l[i] = i - 1;
        r[i] = i + 1;
    }
    r[0] = 1;
    l[n + 1] = n;

    set<PII> S;
    for (int i = 1; i <= n; i++) {
        S.insert(make_pair(abs(d[i]), i));
    }

    while (cnt > m) {
        auto it = S.begin();
        int v = it->first;
        int p = it->second;
        S.erase(it);

        if (l[p] > 0 && r[p] <= n || d[p] > 0) {
            cnt--;
            res -= v;
            int left = l[p];
            int right = r[p];

            if (left > 0) {
                remove(left);
                S.erase(make_pair(abs(d[left]), left));
            }
            if (right <= n) {
                remove(right);
                S.erase(make_pair(abs(d[right]), right));
            }

            d[p] += d[left] + d[right];
            S.insert(make_pair(abs(d[p]), p));
        }
    }
    cout << res << endl;
    return 0;
}
