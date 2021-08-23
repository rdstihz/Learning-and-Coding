/*
    Created by rdstihz at 2021-08-17 11:10:41
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
map<int, int> mp[maxn];
set<int> row[maxn], col[maxn];
set<pair<int, int>> rows;

int f1[maxn], f2[maxn];
int find(int* f, int x) {
    if (f[x] == x)
        return x;
    else {
        f[x] = find(f, f[x]);
        return f[x];
    }
}

void merge_row(int x, int y) {
    for (auto it = row[y].begin(); it != row[y].end(); it++) {
        mp[x][*it] = mp[y][*it];
        row[x].insert(*it);
        col[*it].erase(y);
        col[*it].insert(x);
    }
}

void merge_col(int x, int y) {
    for (auto it = col[y].begin(); it != col[y].end(); it++) {
        mp[*it][x] = mp[*it][y];
        col[x].insert(*it);
        row[*it].erase(y);
        row[*it].insert(x);
    }
}

int main() {
    int n, m1, m2;
    scanf("%d%d%d", &n, &m1, &m2);
    for (int i = 1; i <= n; i++) {
        f1[i] = f2[i] = i;
    }
    int u, v;
    for (int i = 1; i <= m1; i++) {
        scanf("%d%d", &u, &v);
        f1[find(f1, u)] = find(f1, v);
    }
    for (int i = 1; i <= m2; i++) {
        scanf("%d%d", &u, &v);
        f2[find(f2, u)] = find(f2, v);
    }
    if (m1 < m2) {
        swap(f1, f2); //保证第一棵树连通块数量比第二棵树少
    }
    for (int i = 1; i <= n; i++) {
        int a = find(f1, i), b = find(f2, i);
        mp[a][b] = i;
        row[a].insert(b);
        col[b].insert(a);
    }

    for (int i = 1; i <= n; i++) {
        if (find(f1, i) == i) {
            rows.insert(make_pair(-row[i].size(), i));
        }
    }
    vector<pair<int, int>> ans;
    while (rows.size() > 1) {
        int x = rows.begin()->second;
        rows.erase(rows.begin());
        int y = rows.begin()->second;
        rows.erase(rows.begin());
        auto it = row[x].begin();
        int a = *it, b = *(row[y].begin());
        if (a == b) {
            it++;
            a = *it;
        }

        ans.push_back(make_pair(mp[x][a], mp[y][b]));
        if (col[a].size() < col[b].size()) {
            swap(a, b);
        }
        merge_row(x, y);
        merge_col(a, b);
        rows.insert(make_pair(-row[x].size(), x));
    }
    printf("%d\n", (int)ans.size());
    for (auto item : ans) {
        printf("%d %d\n", item.first, item.second);
    }
    return 0;
}