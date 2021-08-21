#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> frac;

frac get_frac(int a, int b) {
    LL d = __gcd(a, b);
    return make_pair(a / d, b / d);
}

frac operator+(const frac& a, const frac& b) {
    LL y = a.second * b.second;
    LL x = a.first * b.second + a.second * b.first;
    LL d = __gcd(x, y);
    return make_pair(x / d, y / d);
}

frac operator*(const frac& a, const frac& b) {
    LL y = a.second * b.second;
    LL x = a.first * b.first;
    LL d = __gcd(x, y);
    return make_pair(x / d, y / d);
}

frac operator/(const frac& a, const frac& b) {
    LL y = a.second * b.first;
    LL x = a.first * b.second;
    LL d = __gcd(x, y);
    return make_pair(x / d, y / d);
}

set<frac> S, temp;
queue<frac> Q;
frac one, two;
int main() {
    int T;
    scanf("%d", &T);
    one = make_pair(1, 1);
    two = make_pair(2, 1);
    while (T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == b) {
            puts("Yes");
            continue;
        }
        S.clear();
        while (Q.size())
            Q.pop();

        S.insert(get_frac(a, b)), Q.push(get_frac(a, b));
        S.insert(get_frac(b, a)), Q.push(get_frac(b, a));
        bool ok = false;
        int day = 10;
        while (Q.size() && day--) {
            printf("%d\n", day);
            frac u = Q.front();
            Q.pop();
            if (u == one) {
                ok = true;
                break;
            }
            temp.clear();
            for (frac v : S) {
                frac t = (u + v) / two;
                if (!S.count(t)) {
                    temp.insert(t);
                }
                t = (two * u * v) / (u + v);
                if (!S.count(t)) {
                    temp.insert(t);
                }
            }
            for (frac v : temp) {
                if (!S.count(v)) {
                    S.insert(v);
                    Q.push(v);
                }
            }
        }
        puts(ok ? "Yes" : "No");
    }

    return 0;
}