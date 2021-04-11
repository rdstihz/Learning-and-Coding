#include <algorithm>
#include <cctype>
#include <cstdio>

using namespace std;

int readIn() {
    int res = 0;
    char ch = getchar();
    bool XX = false;
    for (; !isdigit(ch); ch = getchar())
        (ch == '-') && (XX = true);
    for (; isdigit(ch); ch = getchar())
        res = (res << 3) + (res << 1) + (ch ^ 48);
    return XX ? -res : res;
}

const int maxn = 3000000 + 100;
int a[maxn];

int Q[maxn];
int l, r;

inline double getk(int i, int j) {
    return 1.0 * (a[i] - a[j]) / (i - j);
}

inline int find1(int l, int r, int i) {
    int m;

    while (l < r) {
        m = l + r >> 1;

        if (getk(Q[m], i) <= getk(Q[m], Q[m + 1])) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

inline int find2(int l, int r, int i) {

    int m;
    while (l < r) {
        m = l + r >> 1;

        if (getk(Q[m], i) >= getk(Q[m], Q[m + 1])) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    int n = readIn();
    l = r = 0;
    for (int i = 1; i <= n; i++)
        a[i] = readIn();

    //1.求Qiang
    l = r = 0;
    Q[++r] = 1;
    double qiang = -1e15;
    for (int i = 2; i <= n; i++) {
        int pos = find1(l + 1, r, i);
        double t = getk(Q[pos], i);
        pos--;
        if (pos > l)
            t = max(t, getk(Q[pos], i));

        qiang = max(qiang, t);

        while (r > l) {
            if (r - l == 1 && getk(Q[r], i) <= 0) {
                r--;
            } else if (r - l > 1 && getk(Q[r], i) <= getk(Q[r - 1], Q[r])) {
                r--;
            } else {
                break;
            }
        }

        Q[++r] = i;
    }

    //算ruo
    double ruo = 1e15;
    l = r = 0;
    Q[++r] = 1;

    for (int i = 2; i <= n; i++) {
        int pos = find2(l + 1, r, i);
        double t = getk(Q[pos], i);
        pos--;
        if (pos > l)
            t = min(t, getk(Q[pos], i));

        ruo = min(ruo, t);

        while (r > l) {
            if (r - l == 1 && getk(Q[r], i) >= 0) {
                r--;
            } else if (r - l > 1 && getk(Q[r], i) >= getk(Q[r - 1], Q[r])) {
                r--;
            } else {
                break;
            }
        }

        Q[++r] = i;
    }

    printf("%.3lf\n%.3lf", ruo, qiang);

    return 0;
}