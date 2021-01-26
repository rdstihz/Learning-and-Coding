#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;


const int maxn = 200000 + 100;

int trie[maxn][26];
int pos[maxn];
int tot;
char s[10 * maxn];

void insert(char *s, int id) {
    int u = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int t = s[i] - 'a';
        if (!trie[u][t]) trie[u][t] = ++tot;
        u = trie[u][t];
    }
    pos[id] = u;
}


int fail[maxn];

void getFail() {
    queue<int> Q;

    for (int i = 0; i < 26; i++)
        if (trie[0][i])
            Q.push(trie[0][i]);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < 26; i++) {
            if (trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i];
                Q.push(trie[u][i]);
            } else {
                trie[u][i] = trie[fail[u]][i];
            }
        }

    }

}

int cnt[maxn];
int nxt[maxn], fir[maxn];
int to[maxn];
int tot2;

void add(int u, int v) {
    tot2++;
    to[tot2] = v;
    nxt[tot2] = fir[u];
    fir[u] = tot2;
}

void dfs(int u) {

    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        dfs(v);
        cnt[u] += cnt[v];
    }

}

void query(char *s) {

    int len = strlen(s);
    int u = 0;

    for (int i = 0; i < len; i++) {
        u = trie[u][s[i] - 'a'];
        cnt[u]++;
    }

    for (int i = 1; i <= tot; i++) add(fail[i], i);
    dfs(0);

}

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        insert(s, i);
    }

    getFail();

    scanf("%s", s);
    query(s);

    for (int i = 1; i <= n; i++) {
        printf("%d\n", cnt[pos[i]]);
    }

    return 0;
}