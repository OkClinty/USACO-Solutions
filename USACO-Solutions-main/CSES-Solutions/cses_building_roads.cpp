#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1e5 + 1);
vector<int> v(1e5 + 1);

void dfs(int c) {
    if (!v[c]) {
        v[c] = true;
        for (int i : adj[c]) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;
    vector<pair<int, int>> r;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            r.push_back({1, i});
            dfs(i);
        }
    }
    cout << r.size() << "\n";
    for (int i = 0; i < r.size(); i++) {
        cout << r[i].first << " " << r[i].second << "\n";
    }
    return 0;
}