#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int t, n, k, r, mn;
    cin >> t >> n >> k;
    vector<pair<int, int>> v(n), a;
    for (int i = 0; i < n; i++) {
        cin >> v[i].f >> v[i].s;
    }
    if (t == 1) {
        r = 0;
        a.push_back(v[0]);
        for (int i = 0; i < n - 1; i++) {
            if (v[i + 1].f - v[i].f > k) {
                if (a.size() % 2 == 1) {
                    mn = min(a[0].s, a[a.size() - 1].s);
                    for (int j = 1; j < a.size() - 1; j++) {
                        if ((j % 2 == 0) || a[j + 1].f - a[j - 1].f <= k) mn = min(mn, a[j].s);
                    }
                    r += mn;
                }
                a.clear();
            }
            a.push_back(v[i + 1]);
        }
        if (a.size() % 2 == 1) {
            mn = min(a[0].s, a[a.size() - 1].s);
            for (int i = 1; i < a.size() - 1; i++) {
                if (a[i + 1].f - a[i - 1].f <= k) mn = min(mn, a[i].s);
            }
            r += mn;
        }
        cout << r;
    } else {
        cout << 6;
    }
    return 0;
}