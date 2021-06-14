#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 100000 + 100;
char s[maxn];

struct Node {
    int len, d;
    LL delta;
    bool operator<(const Node& phs) const {
        return delta < phs.delta;
    }
};

LL get_v(int l, int d) {
    if (l < d) return 0;
    l -= d - 1;
    LL q = l / d;
    LL r = l % d;
    return (d - r) * q * (q + 1) / 2 + r * (q + 1) * (q + 2) / 2;
}

priority_queue<Node> Q;

int main1() {
    int l, d;
    while(cin >> l >> d) {
        cout << get_v(l, d) << endl;
    }

}

int main() {
    int n;
    LL k;
    cin >> n >> k;

    cin >> s + 1;

    LL val = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            int j = i;
            while (s[j + 1] == '1')
                j++;

            int len = j - i + 1;
            
            val += get_v(len, 1);
            Q.push(Node{len, 1, get_v(len, 1) - get_v(len, 2)});
            //cout << len << " " << get_v(len, 1) - get_v(len, 2) << endl;
            i = j;
        }
    }
    int ans = 0;

    while (val > k) {
        Node node = Q.top();
        Q.pop();

        val -= node.delta;

        Q.push(Node{node.len, node.d + 1, get_v(node.len, node.d + 1) - get_v(node.len, node.d + 2)});

        ans += 1;
    }

    cout << ans << endl; 

    return 0;
}

/*
7 0
1110111
*/