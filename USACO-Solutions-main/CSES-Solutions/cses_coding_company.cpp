#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, r = 0;
    cin >> n >> x;
    vector<int> v(n);
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(10201)));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    dp[0][0][5100] = 1;
    dp[0][1][5100 - v[0]] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = max(5100 - 100 * i, 100); k <= min(5100 + 100 * i, 10100); k++) {
                dp[i][j][k] = (1ll * (j + 1) * dp[i - 1][j][k]) % mod;
                if (j != n - 1) {
                    dp[i][j][k] += (1ll * (j + 1) * dp[i - 1][j + 1][k - v[i]]) % mod;
                    dp[i][j][k] %= mod;
                }
                if (j != 0) {
                    dp[i][j][k] += dp[i - 1][j - 1][k + v[i]];
                    dp[i][j][k] %= mod;
                }
            }
        }
    }
    for (int i = 0; i <= x; i++) {
        r += dp[n - 1][0][5100 + i];
        r %= mod;
    }
    cout << r;
    return 0;
}