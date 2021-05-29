#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000 + 100;

char s[maxn];

int main() {

    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);

    if (k % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }

    int c0 = 0, c1 = 0;

    for (int i = 0; i < k; i++) {
        bool v0 = false, v1 = false;

        for (int j = i; j < n; j += k)
            if (s[j] == '0')
                v0 = true;
            else if (s[j] == '1')
                v1 = true;

        if (v0 && v1) {
            cout << "No" << endl;
            return 0;
        }

        if (v0)
            c0++;
        else if (v1)
            c1++;
    }

    if (c0 > k / 2 || c1 > k / 2)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}