#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n;
    long long r = 0;
    string s1, s2, a = "", b = "";
    cin >> n >> s1 >> s2;
    for (char c : s1) {
        if (c != '1') {
            if (c != '+') {
                if (c == '0') {
                    a.clear();
                }
                c = 'x';
            }
            a.push_back(c);
        }
    }
    for (char c : s2) {
        if (c != '1') {
            if (c != '+') {
                if (c == '0') {
                    b.clear();
                } 
                c = 'x';
            }
            b.push_back(c);
        }
    }
    vector<vector<vector<long long>>> dp(a.length() + 1, vector<vector<long long>>(b.length() + 1, vector<long long>(2)));
    dp[0][0][0] = 1;
    for (int i = 0; i <= a.length(); i++) {
        for (int j = 0; j <= b.length(); j++) {
            for (int k : {0, 1}) {
                if (dp[i][j][k] != 0) {
                    if (i == a.length() && j == b.length()) {
                        r += dp[i][j][k];
                        r %= mod;
                    } else {
                        if (j < b.length()) {
                            dp[i][j + 1][1] += dp[i][j][k];
                            dp[i][j + 1][1] %= mod;
                        }
                        if (i < a.length() && (k == 0 || a[i] != b[j - 1])) {
                            dp[i + 1][j][0] += dp[i][j][k];
                            dp[i + 1][j][0] %= mod;
                        }
                    }
                }
            }
        }
    }
    cout << r << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}