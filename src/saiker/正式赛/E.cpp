#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 100000 + 100;

char s[maxn];

int main() {
    int n;
    cin >> n;
    cin >> (s + 1);
    int m = strlen(s + 1);

    long long ans = 0;
    int a = 0, b = 0;
    int v = 0;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int t = s[i] - '0';
        if (v + t <= n) {
            v += t;
            cnt++;

            if (t == 1)
                a++;
            else if (t == 2)
                b++;

        } else if (t == 1 && b) {
            b--;
            a++;
            v--;
        }

        ans = ans + cnt;
    }

    cout << ans << endl;

    return 0;
}