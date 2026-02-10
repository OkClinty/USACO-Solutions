#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    string s;
    cin >> n;
    vector<vector<long long>> dp(n, vector<long long>(n));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '*') {
                dp[i][j] = 0;
            } else {
                if (i != 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j != 0) {
                    dp[i][j] += dp[i][j - 1];
                }
                dp[i][j] %= m;
            }
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}