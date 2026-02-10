#include <bits/stdc++.h>
using namespace std;
 
const int m = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    vector<long long> dp(x + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - v[i] >= 0) {
                dp[j] += dp[j - v[i]];
                dp[j] %= m;
            }
        }
    }
    cout << dp[x];
    return 0;
}