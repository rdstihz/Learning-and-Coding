#include <cstdio>

using namespace std;

typedef long long LL;
const int maxn = 100000 + 10;
const LL P = 1000000;
int snow[maxn][6];


LL code(int x) {
    LL res = 1;
    for (int i = 0; i < 6; i++) {
        res = (res * snow[x][i]) % P;
    }
    for (int i = 0; i < 6; i++) {
        res = (res + snow[x][i]) % P;
    }
    return res;
}

int head[P + 10];
int nxt[maxn];


bool equal(int a, int b) {

    for (int k = 0; k < 6; k++) {
        bool flag = true;
        for (int i = 0; i < 6; i++) {
            if (snow[a][i] != snow[b][(k + i) % 6]) {
                flag = false;
                break;
            }
        }
        if (flag) return true;


        flag = true;
        for (int i = 0; i < 6; i++) {
            if (snow[a][i] != snow[b][(k + 6 - i) % 6]) {
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }
    return false;
}

bool find(int x) {
    int c = code(x);
    for (int e = head[c]; e; e = nxt[e]) {
        if (equal(e, x)) return true;
    }
    nxt[x] = head[c];
    head[c] = x;
    return false;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 6; j++)
            scanf("%d", &snow[i][j]);
    }

    for (int i = 1; i <= n; i++) {
        if (find(i)) {
            printf("Twin snowflakes found.\n");
            return 0;
        }
    }

    printf("No two snowflakes are alike.\n");
    return 0;
}