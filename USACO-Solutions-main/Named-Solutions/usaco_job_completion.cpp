#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, p = 0, res = 0;
    cin >> n;
    vector<pair<long long, pair<long long, long long>>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second.first >> v[i].second.second;
        v[i].first = v[i].second.first;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (p <= v[i].second.first) {
            res++;
            p += v[i].second.second;
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}