/*
给出一个小写字母的字符串S
求出 S 的所有出现次数不为 1 的子串的出现次数乘上该子串长度的最大值。
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 2000000 + 10;

struct Node {
    int len; //当前节点代表的最长子串长度
    int ch[27], fa;
    bool flag;
    int val, maxc;
} node[maxn];
char s[maxn];
int idx = 1, last = 1;
int to[maxn], nxt[maxn], fir[maxn], tot;
LL es[maxn], ans;

void dfs(int u) {
    node[u].flag = false;

    if(node[u].maxc)
        dfs(node[u].ch[node[u].maxc]);
    
}


int extend(int c) {
    int p = last, np = last = ++idx;
    es[np] = 1;
    node[np].len = node[p].len + 1;
    for (; p && !node[p].ch[c]; p = node[p].fa) {
        if(node[p].flag && c > node[p].maxc) {
            if(node[p].maxc) 
                dfs(node[p].ch[node[p].maxc]);
            
            node[p].maxc = c;
            node[np].val = node[p].val + 1;
            node[np].flag = true;
        }
        node[p].ch[c] = np;

    }   
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
            
            node[nq].flag = false;
            if(node[p].flag && node[q].flag && node[p].ch[node[p].maxc] == q) {
                node[nq].flag = true;
                node[q].flag = false;
            }

            for (; p && node[p].ch[c] == q; p = node[p].fa) {
                if(node[q].flag && node[p].flag && node[p].ch[node[p].maxc] == q) {
                    node[nq].flag = true;
                    node[q].flag = false;
                }
                node[p].ch[c] = nq;
            }
                
        }
    }
    return node[np].val;
}


int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    node[1].flag = true;
    for(int i = 1; i <= n; i++) {
        int t = extend(s[i] - 'a' + 1);
        printf("%d %d\n", i - t + 1, i);
    }

    return 0;
}

/*
tgttggttt
gtgggt
*/