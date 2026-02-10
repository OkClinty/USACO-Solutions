#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<bool>> v(n - 1, vector<bool>(n - 1));
    vector<long long> dp(1 << (n - 1));
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a != n && b != 1) {
            v[a - 1][b - 2] = true;
        }
    }
    dp[0] = 1;
    for (int s = 0; s < (1 << (n - 1)); s++) {
        for (int i = 0; i < n - 1; i++) {
            if (!(((1 << i) & s) || !v[__builtin_popcount(s)][i])) {
                dp[s | (1 << i)] += dp[s];
                dp[s | (1 << i)] %= mod;
            }
        }
    }
    cout << dp[(1 << (n - 1)) - 1];
    return 0;
}