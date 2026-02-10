#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

const int mod = 1e9 + 7;

ll e(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll r = e(a, b / 2);
    r *= r;
    r %= mod;
    if (b % 2 == 1) {
        r *= a;
        r %= mod;
    }
    return r;
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, d, o = 0, l, r, one = 0, zer = 0;
    ll res;
    cin >> n >> d;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].f >> v[i].s;
        if (v[i].s == 1) {
            o++;
        }
    }
    res = 1;
    r = 0;
    l = 0;
    while (l < n) {
        if (v[l].s == 0) {
            if (l < r) {
                zer--;
            } else {
                r++;
            }
        } else {
            while (r < n && v[l].f + d >= v[r].f) {
                if (v[r].s == 0) {
                    zer++;
                } else {
                    one++;
                }
                r++;
            }
            res *= e(2, zer) + 1;
            res %= mod;
            one--;
        }
        l++;
    }
    cout << res - 1 << "\n";
    return 0;
}