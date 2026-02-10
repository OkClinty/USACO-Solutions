#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, m, x, y;
    long long r;
    cin >> n >> m;
    r = -m;
    vector<set<int>> adj(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        adj[min(x, y)].insert(max(x, y));
    }
    for (int i = 0; i < n; i++) {
        if (adj[i].size() > 0) {
            r += adj[i].size();
            x = *adj[i].begin();
            adj[i].erase(x);
            if (adj[i].size() > adj[x].size()) {
                swap(adj[i], adj[x]);
            }
            for (int j : adj[i]) {
                adj[x].insert(j);
            }
        }
    }
    cout << r;
    return 0;
}