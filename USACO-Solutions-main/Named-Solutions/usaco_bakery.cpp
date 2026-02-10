#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, c, m, l = 0, r, md, a, b, L, R, MD;
    cin >> n >> c >> m;
    vector<pair<pair<long long, long long>, long long>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    }
    r = c + m;
    while (l < r) {
        md = (l + r) / 2;
        a = 0;
        b = 0;
        for (int i = 0; i < n; i++) {
            L = 0;
            if (v[i].first.first >= v[i].first.second) {
                R = c;
                while (L < R) {
                    MD = (L + R) / 2;
                    if (1ll * v[i].first.first * max(1ll, c - MD) + 1ll * v[i].first.second * max(1ll, m - (md - MD)) <= v[i].second) {
                        R = MD;
                    } else {
                        L = MD + 1;
                    }
                }
                if (1ll * v[i].first.first * max(1ll, c - R) + 1ll * v[i].first.second * max(1ll, m - (md - R)) <= v[i].second && R >= 0 && md - R >= 0) {
                    a = max(a, R);
                } else {
                    a = c;
                    break;
                }
            } else {
                R = m;
                while (L < R) {
                    MD = (L + R) / 2;
                    if (1ll * v[i].first.first * max(1ll, c - (md - MD)) + 1ll * v[i].first.second * max(1ll, m - MD) <= v[i].second) {
                        R = MD;
                    } else {
                        L = MD + 1;
                    }
                }
                if (1ll * v[i].first.first * max(1ll, c - (md - R)) + 1ll * v[i].first.second * max(1ll, m - R) <= v[i].second && R >= 0 && md - R >= 0) {
                    b = max(b, R);   
                } else {
                    b = m;
                    break;
                }
            }
        }
        if (a + b <= md && a < c && b < m) {
            r = md;
        } else {
            l = md + 1;
        }
    }
    cout << l << "\n";
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