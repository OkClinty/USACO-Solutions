#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    string s;
    int g, h, r = 0;
    cin >> s;
    vector<int> G(s.size() + 1), H(s.size() + 1);
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    for (int i = 1; i <= s.size(); i++) {
        G[i] = G[i - 1];
        H[i] = H[i - 1];
        if (s[i - 1] == 'G') G[i]++;
        else H[i]++;
    }
    for (int I = 0; I < s.size(); I++) {
        for (int J = 0; J < s.size() - I; J++) {
            int i = J; int j = J + I;
            if (abs(j - i) >= 2 && s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else {
                g = G[j + 1] - G[i]; h = H[j + 1] - H[i];
                vector<int> v;
                for (int k = i; k <= j; k++) {
                    if (s[k] == 'G') {
                        v.push_back(k);
                    }
                }
                if ((i - j + 1) % 2 == 0 && g % 2 == 1) {
                    dp[i][j] = -1;
                } else {
                    for (int k = 0; k < v.size() / 2; k++) {
                        dp[i][j] += abs((v[k] - i) - (j - v[v.size() - 1 - k]));
                    }
                    if (g % 2 == 1) dp[i][j] += abs((i + j) / 2 - v[v.size() / 2]);
                }
            }
            r += dp[i][j];
        }
    }
    cout << r;
    return 0;
}