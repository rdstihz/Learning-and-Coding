#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 400000 + 100;

int trie[maxn][26];
int pos[100000 + 10];
int tot;
char s[40];
char t[100000 + 10];

void insert(char* s, int id) {
    int u = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int t = s[i] - 'a';
        if (!trie[u][t]) trie[u][t] = ++tot;
        u = trie[u][t];
    }
    pos[id] = u;
}

int ans[maxn], last[maxn];
int cur;

void query(char* s) {
    int u = 0;
    int len = min(30, (int)strlen(s));
    int d = 0;
    for (int i = 0; i < len; i++) {
        int t = s[i] - 'a';
        if (!trie[u][t]) return;
        u = trie[u][t];
        d++;
        if (last[u] + d - 1 >= cur) continue;
        ans[u]++;
        last[u] = cur;
    }
}

void solve() {
    int n;
    scanf("%s", t);
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        insert(s, i);
    }

    for(int i = 0; i <= tot; i++)
        last[i] = -1e8;

    int m = strlen(t);
    for (int i = 0; i < m; i++) {
        cur = i;
        query(t + i);
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[pos[i]]);
    //清空
    for (int i = 0; i <= tot; i++) {
        for (int j = 0; j < 26; j++)
            trie[i][j] = 0;
        ans[i] = 0;
    }
    tot = 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}

/*
abababccc
2  
aba
bc
*/