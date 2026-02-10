#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("exercise.in");
    ofstream cout ("exercise.out");
    int n, m, p;
    cin >> n >> m;
    vector<bool> composite(n + 1, false);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (!composite[i]) {
            for (int j = i + i; j <= n; j += i) {
                composite[j] = true;
            }
            primes.push_back(i);
        }
    }
    vector<vector<long long>> dp(primes.size() + 1, vector<long long>(n + 1));
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= primes.size(); i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            p = primes[i - 1];
            while (p <= j) {
                dp[i][j] += p * dp[i - 1][j - p];
                dp[i][j] %= m;
                p *= primes[i - 1];
            }
        }
    }
    cout << dp[primes.size()][n];
    return 0;
}