#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("time.out");
    ifstream cin ("time.in");
    int n, m, c, a, b, r = 0;
    cin >> n >> m >> c;
    vector<int> arr(n + 1);
    vector<vector<int>> v(n + 1), dp(1001, vector<int>(n + 1, INT_MIN));
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[0][1] = 0;
    while (m--) {
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 0; i < 1000; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] != INT_MIN) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                for (int k : v[j]) {
                    dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + arr[k]);
                }
            }
        }
    }
    for (int i = 1; i <= 1000; i++) {
        r = max(r, dp[i][1] - c * i * i);
    }
    cout << r;
    return 0;
}