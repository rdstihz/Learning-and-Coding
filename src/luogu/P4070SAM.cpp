/*
给出一个小写字母的字符串S
求出 S 的所有出现次数不为 1 的子串的出现次数乘上该子串长度的最大值。
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 200000 + 10;

struct Node {
    int len; //当前节点代表的最长子串长度
    map<int, int> ch;
    int fa;
} node[maxn];
char s[maxn];
int idx = 1, last = 1;
int to[maxn], nxt[maxn], fir[maxn], tot;
LL es[maxn], ans;

int extend(int c) {
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
    return node[np].len - node[node[np].fa].len;
}


int main() {
    // scanf("%s", s);
    // int n = strlen(s);
    // for (int i = 0; i < n; i++)
    //     extend(s[i] - 'a');
    // for (int i = 2; i <= idx; i++)
    //     add_edge(node[i].fa, i);
    // dfs(1);
    // printf("%lld\n", ans);

    int n;
    scanf("%d", &n);
    LL res = 0;
    int x;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        res += extend(x);
        printf("%lld\n", res);
    }

    return 0;
}