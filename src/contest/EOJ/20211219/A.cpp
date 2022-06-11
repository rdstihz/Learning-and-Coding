#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000;

struct Node{
    string name;
    double strength;
} a[maxn];
string b[4];

bool cmp(const Node& a, const Node &b) {
    return a.strength > b.strength;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].name >> a[i].strength;
    }
    sort(a + 1, a + 1 + n, cmp);
    int j = 1;
    for(int i = 1; i <= n && j <= 3; i++) {
        if(a[i].name == "morph" || a[i].name == "magnus")
            continue;
        b[j++] = a[i].name;
    }

    sort(b + 1, b + 1 + 3);
    for(int i = 1; i <= 3; i++)
        cout << b[i] << endl;


    return 0;
}