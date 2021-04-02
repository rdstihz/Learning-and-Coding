#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

const int maxn = 100000 + 100;

int v[maxn];
int bit[maxn];

double a, b, c;
int n;

int cnt[2], last[2];

void solve() {

    for (int k = 0; k < 31; k++) {

        for (int i = 1; i <= n; i++) {
            bit[i] = (v[i] >> k) & 1;

            if (bit[i] == 1) {
                a += (1 << k) * 1.0 / n / n;
                b += (1 << k) * 1.0 / n / n;
                c += (1 << k) * 1.0 / n / n;
            }
        }
        cnt[0] = cnt[1] = 0;
        last[0] = last[1] = 0;
        for (int i = 1; i <= n; i++) {
            if (bit[i] == 1) {
                b += (1 << k) * 2.0 / n / n * (i - 1 - last[0]);
                c += (1 << k) * 2.0 / n / n * (i - 1);
            } else {
                c += (1 << k) * 2.0 / n / n * (last[1]);
            }

            if (bit[i] == 1) {
                a += (1 << k) * 2.0 / n / n * cnt[0];
                swap(cnt[0], cnt[1]);
                cnt[1]++;
            } else {
                a += (1 << k) * 2.0 / n / n * cnt[1];
                cnt[0]++;
            }

            last[bit[i]] = i;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> v[i];
    a = b = c = 0;
    solve();
    cout << fixed << setprecision(3);
    cout << a << " " << b << " " << c << endl;

    return 0;
}