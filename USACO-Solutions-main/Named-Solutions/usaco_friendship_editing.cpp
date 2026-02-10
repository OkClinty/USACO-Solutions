#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, r = 0;
    cin >> n >> m;
    vector<pair<int, int>> v(n), p(n);
    for (int i = 0; i < n; i++) {
        v[i].second = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> p[i].first >> p[i].second;
        v[p[i].first - 1].first++;
        v[p[i].second - 1].first++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        if (p[i].first - 1 != v[n - 1].second && p[i].second - 1 != v[n - 1].second) {
            v[p[i].first - 1].first--;
            v[p[i].second - 1].first--;
            r += 2;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        r += abs(1 - v[i].first);
    }
    cout << (r + abs(n - 1 - v[n - 1].first)) / 2;
    return 0;
}
