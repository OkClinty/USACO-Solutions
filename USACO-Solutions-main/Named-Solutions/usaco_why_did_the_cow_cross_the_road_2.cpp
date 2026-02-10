#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("nocross.in");
    ofstream cout ("nocross.out");
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + (abs(a[i - 1] - b[j - 1]) <= 4));
        }
    }
    cout << dp[n][n];
    return 0;
}