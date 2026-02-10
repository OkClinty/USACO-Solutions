#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, m = 0;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    vector<int> dp(x + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (dp[j] != -1 && j + v[i].first <= x) {
                dp[j + v[i].first] = max(dp[j + v[i].first], dp[j] + v[i].second);
            }
        }
    }
    for (int i = 0; i <= x; i++) {
        m = max(m, dp[i]);
    }
    cout << m;
    return 0;
}