#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, num;
    cin >> n;
    vector<int> dp(n + 1, inf);
    dp[n] = 0;
    for (int i = n; i > 0; i--) {
        num = i;
        while (num > 0) {
            dp[i - num % 10] = min(dp[i - num % 10], dp[i] + 1);
            num /= 10;
        }
    }
    cout << dp[0];
    return 0;
}