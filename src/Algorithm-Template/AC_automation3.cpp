//Luogo P5357

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 200000 + 100;
const int maxm = 2000000 + 100;

int trie[maxn][26], fail[maxn], pos[maxn], cnt[maxn], tot;
char s[maxm];


void insert(char* s, int id) {
    int len = strlen(s), u = 0;
    for (int i = 0; i < len; i++) {
        if (!trie[u][s[i] - 'a']) trie[u][s[i] - 'a'] = ++tot;
        u = trie[u][s[i] - 'a'];
    }
    pos[id] = u;
}

void getFail() {
    queue<int> Q;
    for (int i = 0; i < 26; i++)
        if (trie[0][i])
            Q.push(trie[0][i]);

    while (Q.size()) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < 26; i++) {
            if (trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i];
                Q.push(trie[u][i]);
            } else
                trie[u][i] = trie[fail[u]][i];
        }
    }
}

int fir[maxn], nxt[maxn], to[maxn];
int idx;
void add(int a, int b) {
    idx++;
    to[idx] = b, nxt[idx] = fir[a], fir[a] = idx;
}

void dfs(int u) {
    for (int e = fir[u]; e; e = nxt[e]) {
        dfs(to[e]);
        cnt[u] += cnt[to[e]];
    }
}

void query(char* s) {
    int n = strlen(s);
    int u = 0;
    for (int i = 0; i < n; i++) {
        u = trie[u][s[i] - 'a'];
        cnt[u]++;
    }
    for (int i = 1; i <= tot; i++)
        add(fail[i], i);
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
    for (int i = 1; i <= n; i++)
        printf("%d\n", cnt[pos[i]]);

    return 0;
}