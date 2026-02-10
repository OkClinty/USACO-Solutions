#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("teamwork.in");
    ofstream cout ("teamwork.out");
    int n, k, mx;
    cin >> n >> k;
    vector<int> v(n), dp(n + k);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        mx = v[i];
        for (int j = 1; j <= k; j++) {
            mx = max(mx, v[i + j - 1]);
            dp[i + j] = max(dp[i + j], dp[i] + mx * j);
        }
    }
    cout << dp[n];
    return 0;
}