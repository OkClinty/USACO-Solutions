#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("radio.in");
    ofstream cout ("radio.out");
    long long n, m, fx, fy, bx, by;
    string a, b;
    cin >> n >> m >> fx >> fy >> bx >> by >> a >> b;
    vector<vector<long long>> dp(n + 2, vector<long long>(m + 2));
    vector<long long> Fx(n + 1), Fy(n + 1), Bx(m + 1), By(m + 1);
    Fx[0] = fx;
    Fy[0] = fy;
    Bx[0] = bx;
    By[0] = by;
    dp[0][0] = LLONG_MAX;
    dp[n + 1][0] = LLONG_MAX;
    dp[0][m + 1] = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = LLONG_MAX;
        Fx[i] = Fx[i - 1];
        Fy[i] = Fy[i - 1];
        if (a[i - 1] == 'N') {
            Fy[i]++;
        } else if (a[i - 1] == 'S') {
            Fy[i]--;
        } else if (a[i - 1] == 'E') {
            Fx[i]++;
        } else {
            Fx[i]--;
        }
    }
    for (int i = 1; i <= m; i++) {
        dp[0][i] = LLONG_MAX;
        Bx[i] = Bx[i - 1];
        By[i] = By[i - 1];
        if (b[i - 1] == 'N') {
            By[i]++;
        } else if (b[i - 1] == 'S') {
            By[i]--;
        } else if (b[i - 1] == 'E') {
            Bx[i]++;
        } else {
            Bx[i]--;
        }
    } 
    dp[1][1] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i != 0 || j != 0) {
                dp[i + 1][j + 1] = pow(Fx[i] - Bx[j], 2) + pow(Fy[i] - By[j], 2) 
                    + min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j]));
            }
        }
    }
    cout << dp[n + 1][m + 1];
    return 0;
}