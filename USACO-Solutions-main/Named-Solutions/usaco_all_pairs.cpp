#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

void operator+=(pair<int, long long> &a, const pair<int, long long> &b) {
    a.first += b.first;
    a.second += b.second;
}

const int mod = 1'000'000'007;

long long e(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    long long r = e(a, b / 2);
    r *= r;
    r %= mod;
    if (b % 2 == 1) {
        r *= a;
        r %= mod;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    long long r;
    cin >> n >> k;
    vector<int> v(n);
    vector<long long> a(k + 1);
    vector<vector<pair<int, long long>>> dp(1 << k, vector<pair<int, long long>>(k + 1));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        dp[v[i]][0].first++;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < (1 << k); j++) {
            if (!(j & (1 << i))) {
                for (int l = i + 1; l >= 0; l--) {
                    if (l == 0) {
                        dp[j ^ (1 << i)][l] = {};
                    } else {
                        dp[j][l] += dp[j ^ (1 << i)][l - 1];
                        dp[j ^ (1 << i)][l] = {dp[j][l - 1].first + dp[j ^ (1 << i)][l - 1].first, dp[j][l - 1].second + dp[j ^ (1 << i)][l - 1].first + dp[j ^ (1 << i)][l - 1].second};
                    }
                }
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        a[i] = e(i, mod - 2);
    }
    for (int i : v) {
        r = 0;
        for (int j = 1; j <= k; j++) {
            r += (dp[i][j].second * a[j]) % mod;
            r %= mod;
        }
        cout << r << "\n";
    }
    return 0;
}