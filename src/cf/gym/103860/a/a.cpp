/*
    Created by rdstihz at 2022-08-13 23:58:34
*/

#include <bits/stdc++.h>

using namespace std;

struct Node{
    string type;
    string name;
    int cnt;
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<Node> P, Q;
    for(int i = 1; i <= n; i++) {
        Node a;
        cin >> a.type;
        if(a.type == "echo") cin >> a.name;
        else cin >> a.cnt;
        P.push_back(a);
        Q.push_back(a);
    }

    for(int i = 0; i < Q.size(); i++) {
        Node a = Q[i];
        if(a.type == "echo") {
            cout << a.name;
        }else {
            for(int j = 0; j < a.cnt && Q.size() < k && j < P.size(); j++) {
                Q.push_back(P[j]);
            }
        }
    }
    cout << endl;
    return 0;
}