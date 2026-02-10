#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

int l, n;
string s;
vector<int> c;

struct Info {
    int len;
    array<array<vector<ll>, 3>, 3> dp;
};

void update(vector<ll> &a, const vector<ll> &b, const vector<ll> &c, int i, ll add) {
    int nsize = b.size() + c.size() - 1 + i;
    if (a.size() < nsize) a.resize(nsize, LLONG_MAX);
    int ib = 0, ic = 0;
    for (;; ++i) {
        a[i] = min(a[i], add);
        if (ib + 1 < b.size()) {
            if (ic + 1 < c.size()) {
                if (b[ib + 1] - b[ib] <= c[ic + 1] - c[ic])
                    add += b[ib + 1] - b[ib], ++ib;
                else add += c[ic + 1] - c[ic], ++ic;
            } else add += b[ib + 1] - b[ib], ++ib;
        } else if (ic + 1 < c.size()) add += c[ic + 1] - c[ic], ++ic;
        else break;
    }
}

Info solve(int L, int R) {
    Info res;
    res.len = R - L;
    if (l == 1 && res.len == 1) {
        res.dp[0][0] = {0, c[L]};
        return res;
    }
    if (res.len < l) {
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                if (i + j <= res.len) res.dp[i][j] = {0};
            }
        }
        return res;
    }
    int m = (L + R) / 2;
    Info l_info = solve(L, m), r_info = solve(m, R);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            if (i + j <= res.len) {
                if (i >= l_info.len) res.dp[i][j] = r_info.dp[i - l_info.len][j];
                else if (j >= r_info.len) res.dp[i][j] = l_info.dp[i][j - r_info.len];
                else {
                    update(res.dp[i][j], l_info.dp[i][0], r_info.dp[0][j], 0, 0);
                    for (int p = 1; p < l; p++) {
                        if (l_info.len >= i + p && r_info.len >= j + l - p) update(res.dp[i][j], l_info.dp[i][p], r_info.dp[l - p][j], 1, c[m - p]);
                    }
                }
            }
        }
    }
    return res;
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> l >> n >> s;
    string moo = "MOO";
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    c.resize(n - l + 1);
    for (int i = 0; i < n - l + 1; i++) {
        for (int j = 0; j < l; j++) {
            c[i] += a[i + j] * (s[i + j] != moo[j]);
        }
    }
    vector<ll> r = solve(0, n).dp[0][0];
    for (int i = 1; i < r.size(); i++) {
        cout << r[i] << "\n";
    }
    return 0;
}