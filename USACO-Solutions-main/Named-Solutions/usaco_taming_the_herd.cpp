#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("taming.in");
    ofstream cout ("taming.out");
    int n, cnt;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dp[n][0] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            for (int k = i + 1; k <= n; k++) {
                if (dp[k][j - 1] != INT_MAX) {
                    cnt = 0;
                    for (int l = i; l < k; l++) {
                        cnt += (v[l] != l - i);
                    }
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + cnt);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[0][i] << "\n";
    }
    return 0;
}