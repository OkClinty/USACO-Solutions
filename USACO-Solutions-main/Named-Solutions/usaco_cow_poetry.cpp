#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long recur(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    long long r = recur(a, b / 2);
    r *= r;
    r %= mod;
    if (b % 2 == 1) {
        return (r * a) % mod;
    } else {
        return r;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("poetry.in");
    ofstream cout ("poetry.out");
    int n, m, k;
    long long r = 1, s;
    char ch;
    cin >> n >> m >> k;
    vector<pair<int, int>> v(n);
    vector<long long> dp(k);
    vector<int> c(26);
    vector<vector<int>> u(k);
    map<long long, long long> mp;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        for (int j = 0; j < k; j++) {
            if (j >= v[i].first) {
                u[j].push_back(j - v[i].first);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j : u[i]) {
            dp[i] += dp[j];
            dp[i] %= mod;
        }
    }
    for (int i = 0; i < n; i++) {
        mp[v[i].second] += dp[k - v[i].first];
    }
    while (m--) {
        cin >> ch;
        c[ch - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (c[i] != 0) {
            s = 0;
            for (auto it = mp.begin(); it != mp.end(); it++) {
                s += recur(it->second, c[i]);
                s %= mod;
            }
            r *= s;
            r %= mod;
        }
    }
    cout << r;
    return 0;
}