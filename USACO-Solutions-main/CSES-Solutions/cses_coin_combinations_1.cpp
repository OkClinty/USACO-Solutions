#include <bits/stdc++.h>
using namespace std;

int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<long long> v(n), dp(x + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= x; i++) {
        for (int j : v) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }
        }
        dp[i] %= m;
    }
    cout << dp[x];
    return 0;
}