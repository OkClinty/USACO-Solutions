#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

const long long inf = 1'000'000'000'000;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k, x;
    long long r;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<long long>> dp_1(5, vector<long long>(n, inf)), dp_n(5, vector<long long>(n, inf));
    vector<vector<vector<long long>>> b(3, vector<vector<long long>>(n, vector<long long>(n, inf)));
    vector<pair<int, int>> v(n * n);
    vector<long long> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n * n; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].first--;
        v[i].second--;
    }
    for (int i = n * n - 1; i >= 0; i--) {
        r = inf;
        for (int j = 0; j < n; j++) {
            r = min(r, dp_1[k / 2][j] + dp_n[(k + 1) / 2][j]);
        }
        if (r == inf) {
            res.push_back(-1);
        } else {
            res.push_back(r);
        }
        b[1][v[i].first][v[i].second] = a[v[i].first][v[i].second];
        x = b[1][v[i].first][v[i].second];
        for (int j = 0; j < n; j++) {
            b[2][j][v[i].second] = min(b[2][j][v[i].second], b[1][j][v[i].first] + x);
            b[2][v[i].first][j] = min(b[2][v[i].first][j], b[1][v[i].second][j] + x);
        }
        for (int j = 0; j < n; j++) {
            dp_1[1][j] = min(dp_1[1][j], b[1][0][j]);
            dp_n[1][j] = min(dp_n[1][j], b[1][j][n - 1]);
            dp_1[2][j] = min(dp_1[2][j], b[2][0][j]);
            dp_n[2][j] = min(dp_n[2][j], b[2][j][n - 1]);
            dp_1[3][j] = min(dp_1[3][j], x + b[1][0][v[i].first] + b[1][v[i].second][j]);
            if (v[i].first == 0) {
                dp_1[3][j] = min(dp_1[3][j], x + b[2][v[i].second][j]);
            }
            if (v[i].second == j) {
                dp_1[3][j] = min(dp_1[3][j], x + b[2][0][v[i].first]);
            }
            dp_n[3][j] = min(dp_n[3][j], x + b[1][j][v[i].first] + b[1][v[i].second][n - 1]);
            if (v[i].first == j) {
                dp_n[3][j] = min(dp_n[3][j], x + b[2][v[i].second][n - 1]);
            }
            if (v[i].second == n - 1) {
                dp_n[3][j] = min(dp_n[3][j], x + b[2][j][v[i].first]);
            }
        }
    }
    for (int i = n * n - 1; i >= 0; i--) {
        cout << res[i] << "\n";
    }
    return 0;
}