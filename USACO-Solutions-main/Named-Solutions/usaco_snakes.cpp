#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("snakes.in");
    ofstream cout ("snakes.out");
    int n, k, r = INT_MAX, mx, sm;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> v(n + 1, vector<int>(k + 2, INT_MAX));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    v[0][k + 1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k + 1; j++) {
            if (v[i][j] != INT_MAX) {
                mx = 0;
                sm = 0;
                for (int l = i; l < n; l++) {
                    mx = max(mx, a[l]);
                    sm += a[l];
                    v[l + 1][j - 1] = min(v[l + 1][j - 1], v[i][j] + mx * (l + 1 - i) - sm);
                }
            }
        }
    }
    for (int i = 0; i <= k; i++) {
        r = min(r, v[n][i]);
    }
    cout << r;
    return 0;
}