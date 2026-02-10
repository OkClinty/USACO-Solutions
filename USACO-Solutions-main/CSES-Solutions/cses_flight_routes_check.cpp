#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, a, b, num;
    cin >> n >> m;
    vector<vector<int>> g1(n + 1), g2(n + 1);
    vector<bool> v1(n + 1), v2(n + 1);
    stack<int> s;
    while (m--) {
        cin >> a >> b;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    s.push(1);
    while (!s.empty()) {
        num = s.top();
        s.pop();
        v1[num] = true;
        for (int i : g1[num]) {
            if (!v1[i]) {
                s.push(i);
            }
        }
    }
    s.push(1);
    while (!s.empty()) {
        num = s.top();
        s.pop();
        v2[num] = true;
        for (int i : g2[num]) {
            if (!v2[i]) {
                s.push(i);
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!v1[i]) {
            cout << "NO\n1 " << i;
            return 0;
        } else if (!v2[i]) {
            cout << "NO\n" << i << " 1";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}