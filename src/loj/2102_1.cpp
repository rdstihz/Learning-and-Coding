#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 1000000 + 10;

struct Node {
    int len; //当前节点代表的最长子串长度
    int ch[26], fa;
} node[maxn];
char s[maxn];
int idx = 1, last = 1;
LL es[maxn], ans;

void extend(int c) {
    int p = last, np = last = ++idx;
    es[np] = 1;
    node[np].len = node[p].len + 1;
    for (; p && !node[p].ch[c]; p = node[p].fa)
        node[p].ch[c] = np;
    if (!p)
        node[np].fa = 1;
    else {
        int q = node[p].ch[c];
        if (node[q].len == node[p].len + 1) {
            node[np].fa = q;
        } else {
            int nq = ++idx;
            node[nq] = node[q], node[nq].len = node[p].len + 1;
            node[q].fa = node[np].fa = nq;
            for (; p && node[p].ch[c] == q; p = node[p].fa)
                node[p].ch[c] = nq;
        }
    }
}


int c[maxn], q[maxn];
int t, k;
LL d[maxn], sz[maxn];



int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        extend(s[i] - 'a');

    scanf("%d%d", &t, &k);
    
    
    for(int i = 1; i <= idx; i++)
        c[node[i].len]++;
    for(int i = 1; i <= idx; i++)
        c[i] += c[i - 1];
    for(int i = idx; i >= 1; i--)
        q[c[node[i].len]--] = i;
    
    for(int i = idx; i >= 1; i--) {
        int u = q[i];
        es[node[u].fa] += es[u];
    }

    for(int i = 2; i <= idx; i++) 
        sz[i] = d[i] = t ? es[i] : 1;

    for(int i = idx; i >= 1; i--) {
        int u = q[i];
        for(int i = 0; i < 26; i++)
            if(node[u].ch[i]) sz[u] += sz[node[u].ch[i]];
    }

    if(k > sz[1]) 
        printf("-1\n");
    else {
        int cur = 1;
        while(k > d[cur]) {
            k -= d[cur];
            for(int i = 0; i < 26; i++) {
                int v = node[cur].ch[i];
                if(!v) continue;
                if(k <= sz[v]) {
                    putchar('a' + i);
                    cur = v;
                    break;
                }else k -= sz[v];
            }
        }

    }
    return 0;
}