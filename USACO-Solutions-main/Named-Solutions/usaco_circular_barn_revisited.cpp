#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("cbarn2.in");
    ofstream cout ("cbarn2.out");
    long long n, k, r = LLONG_MAX, num, cnt;
    cin >> n >> k;
    vector<long long> v(n);
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (k > n) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = LLONG_MAX;
            }
        }
        dp[0][0] = 0;
        num = v[0];
        for (int i = 0; i < n - 1; i++) {
            v[i] = v[i + 1];
        }
        v[n - 1] = num;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (dp[i][j] != LLONG_MAX) {
                    cnt = 0;
                    for (int l = i + 1; l <= n; l++) {
                        cnt += v[l - 1] * (l - i - 1);
                        dp[l][j + 1] = min(dp[l][j + 1], dp[i][j] + cnt);
                    }
                }
            }
        }
        r = min(r, dp[n][k]);
    }
    cout << r;
    return 0;
}