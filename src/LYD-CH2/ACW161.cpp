#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 10010;

int trie[maxn * 10][10];
bool tag[maxn * 10];
int tot, root;
bool ans;

char s[15];

void insert(char *s) {
    int len = strlen(s);
    int u = root;
    bool newnode = false;
    for(int i = 0;i < len; i++ ) {
        if(!trie[u][s[i] - '0']) {
            trie[u][s[i] - '0'] = ++tot; 
            newnode = true;
        }
        u = trie[u][s[i] - '0'];
        if(tag[u]) ans = false;
    }
    tag[u] = true;
    if(!newnode) ans = false;

}


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        tot = root = 0;
        ans = true;
        memset(trie, 0, sizeof(trie));
        memset(tag, 0, sizeof(tag));

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%s", s);
            insert(s);
        }

        if (ans)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}