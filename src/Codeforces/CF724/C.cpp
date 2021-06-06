#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
map<PII, int> M;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
char s[500000 + 10];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cin >> (s + 1);

        int ck = 0;
        M.clear();
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'K')
                ck++;

            int d = gcd(ck, i);
            PII t = make_pair(ck / d, i / d);
            if (M.count(t))
                M[t] = M[t] + 1;
            else
                M[t] = 1;
            cout << M[t] << " ";
        }
        cout << endl;
    }

    return 0;
}