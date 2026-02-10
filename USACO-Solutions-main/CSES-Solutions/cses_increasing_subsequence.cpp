#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, p = 1, num;
    cin >> n;
    vector<int> dp(n + 2, INT_MAX);
    dp[0] = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto it = lower_bound(dp.begin(), dp.begin() + p, num);
        if ((*it) == INT_MAX) {
            p++;
        }
        dp[distance(dp.begin(), it)] = num;
    }
    cout << p - 1;
    return 0;
}