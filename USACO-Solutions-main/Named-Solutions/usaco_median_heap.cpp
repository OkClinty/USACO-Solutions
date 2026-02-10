#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q, m;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    vector<int> dp(n + 1);
    vector<int> dpp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
        dp[i] = v[i].second;
        dpp[i] = v[i].first;
    }
    cin >> q;
    for (int j = 0; j < q; j++) {
        cin >> m;
        for (int i = n / 2; i >= 1; i--) {
            pair<int, int> a = {v[i].first, v[i].second}, b = {dpp[i * 2], dp[i * 2]}, c = {dpp[i * 2 + 1], dp[i * 2 + 1]};
            if (a.first > b.first) {
                swap(a, b);
            }
            if (b.first > c.first) {
                swap(b, c);
            }
            if (a.first > b.first) {
                swap(a, b);
            }
            if (m == b.first) {
                dp[i] = 0;
            } else if (a.first <= m && m <= b.first) {
                dp[i] = min(b.second, c.second);
            } else if (b.first <= m && m <= c.first) {
                dp[i] = min(b.second, a.second);
            } else {
                dp[i] = a.second + b.second + c.second - max(a.second, max(b.second, c.second));
            }
            dpp[i] = b.first;
        }
        cout << dp[1] << "\n";
    }
    return 0;
}