#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000 + 100;

char s[55];
int trie[maxn * 55][26], root, tot;
int ed[maxn * 55];
bool vis[maxn];

void insert(char* s, int id) {
    int cur = root;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int v = s[i] - '0';
        if (!trie[cur][v])
            trie[cur][v] = ++tot;
        cur = trie[cur][v];
    }
    ed[cur] = id;
}

void query(char* s) {
    int cur = root;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int v = s[i] - '0';
        if (!trie[cur][v]) {
            printf("WRONG\n");
            return;
        }
        cur = trie[cur][v];
    }
    if (vis[ed[cur]])
        printf("REPEAT\n");
    else {
        printf("OK\n");
        vis[ed[cur]] = true;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        insert(s, i);
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        scanf("%s", s);
        query(s);
    }

    return 0;
}