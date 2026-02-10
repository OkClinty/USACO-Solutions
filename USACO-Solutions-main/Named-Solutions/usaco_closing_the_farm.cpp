#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("closing.out");
    ifstream cin ("closing.in");
    int n, m, a, b, c, p = 1;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> s(n + 1), v(n + 1);
    stack<int> q;
    for (int i = 1; i <= n; i++) {
        s[i] = true;
    }
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        c = 1;
        for (int j = 1; j <= n; j++) {
            v[j] = false;
        }
        while (!s[p]) {
            p++;
        }
        q.push(p);
        v[p] = true;
        while (!q.empty()) {
            b = q.top();
            q.pop();
            for (int num : adj[b]) {
                if (s[num] && !v[num]) {
                    q.push(num);
                    v[num] = true;
                    c++;
                }
            }
        }
        if (c == n - i) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        s[a] = false;
    }
    return 0;
}