#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int n, m;
int nums[10];

int ans[13 * 13 * 13 * 13 + 100][5];
int cnt;

struct Node {
    vector<PII> a;
    bool div;

    Node() {
        div = false;
        a.clear();
    }

    void operator=(const Node& phs) {
        div = phs.div;
        a = phs.a;
    }
};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void fuck(PII& a) {
    int d = gcd(a.first, a.second);
    a.first /= d;
    a.second /= d;

    if (a.first == 0)
        a.second = 1;
}

PII add(const PII& a, const PII& b) {
    PII res;
    res.second = a.second * b.second;
    res.first = a.first * b.second + b.first * a.second;
    fuck(res);
    return res;
}

PII mil(const PII& a, const PII& b) {
    PII res;
    res.second = a.second * b.second;
    res.first = a.first * b.second - b.first * a.second;
    fuck(res);
    return res;
}

PII mul(const PII& a, const PII& b) {
    PII res;
    res.second = a.second * b.second;
    res.first = a.first * b.first;
    fuck(res);
    return res;
}

PII div(const PII& a, const PII& b) {
    PII res;
    res.second = a.second * b.first;
    res.first = a.first * b.second;
    fuck(res);
    return res;
}

bool check() {
    Node start;
    for (int i = 1; i <= n; i++)
        start.a.push_back(make_pair(nums[i], 1));

    queue<Node> Q;
    Q.push(start);
    bool ok = false;
    while (Q.size()) {
        Node node = Q.front();
        Q.pop();

        if (node.a.size() == 1 && node.div == false && node.a[0] == make_pair(m, 1)) return false;
        if (node.a.size() == 1 && node.div == true && node.a[0] == make_pair(m, 1)) {
            ok = true;
            continue;
        };

        const auto& a = node.a;

        Node v = node;
        vector<PII> b;
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                b.clear();
                for (int k = 0; k < a.size(); k++)
                    if (k != i && k != j)
                        b.push_back(a[k]);

                //加
                b.push_back(add(a[i], a[j]));
                v.a = b;
                Q.push(v);
                b.pop_back();

                //减
                b.push_back(mil(a[i], a[j]));
                v.a = b;
                Q.push(v);
                b.pop_back();

                b.push_back(mil(a[j], a[i]));
                v.a = b;
                Q.push(v);
                b.pop_back();

                //乘
                b.push_back(mul(a[i], a[j]));
                v.a = b;
                Q.push(v);
                b.pop_back();

                //除
                if (a[j].first != 0) {
                    b.push_back(div(a[i], a[j]));
                    v.a = b;
                    v.div |= b.back().second > 1;
                    Q.push(v);
                    v.div = node.div;
                    b.pop_back();
                }

                if (a[i].first != 0) {
                    b.push_back(div(a[j], a[i]));
                    v.a = b;
                    v.div |= b.back().second > 1;
                    Q.push(v);
                    v.div = node.div;
                    b.pop_back();
                }
            }
        }
    }

    return ok;
}

void dfs(int d, int last) {
    if (d == n + 1) {
        if (check()) {
            cnt++;
            for (int i = 1; i <= n; i++)
                ans[cnt][i] = nums[i];
        }
        return;
    }

    for (int i = last; i <= 13; i++) {
        nums[d] = i;
        dfs(d + 1, i);
    }
}

int main() {
    scanf("%d%d", &n, &m);

    int maxv = 1;
    for (int i = 1; i < n; i++)
        maxv = maxv * 13;
    if (m > maxv) {
        printf("0\n");
        return 0;
    }

    dfs(1, 1);
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}