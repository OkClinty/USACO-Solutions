#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("reststops.out");
    ifstream cin ("reststops.in");
    int l, n, f, b, m;
    long long r = 0;
    cin >> l >> n >> f >> b;
    vector<pair<int, int>> v(n + 1);
    v[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    m = 0;
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for (int i = 0; i < n; i++) {
        m = max(m, v[i].second);
        r += 1ll * m * (v[i].first - v[i + 1].first) * (f - b);
    }
    cout << r;
    return 0;
}