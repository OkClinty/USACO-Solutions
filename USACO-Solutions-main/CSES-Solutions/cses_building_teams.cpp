#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, a, b, o;
    cin >> n >> m;
    vector<int> v(n);
    vector<vector<int>> adj(n);
    pair<int, int> p;
    stack<pair<int, int>> s;
    while (m--) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (!v[i]) {
            s.push({i, 1});
            while (!s.empty()) {
                p = s.top();
                s.pop();
                if (p.second == 1) {
                    o = 2;
                } else {
                    o = 1;
                }
                v[p.first] = p.second;
                for (int j : adj[p.first]) {
                    if (v[j] == 0) {
                        s.push({j, o});
                    } else if (v[j] == p.second) {
                        cout << "IMPOSSIBLE";
                        return 0;
                    }
                }
            }
        }
    }
    for (int num : v) {
        cout << num << " ";
    }
    return 0;
}