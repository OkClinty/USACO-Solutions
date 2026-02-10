#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

const int mod = 1e9 + 7;

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, m, q, l, r, k, o, z, cnt;
    ll cur, res;
    bool b = false;
    cin >> n >> m >> q;
    vector<bool> s(n), v(n + 1, false);
    while (m--) {
        cin >> l >> r;
        v[l - 1] = !v[l - 1];
        v[r] = !v[r];
    }
    for (int i = 0; i < n; i++) {
        if (v[i]) {
            b = !b;
        }
        if (b) {
            s[i] = true;
        } else {
            s[i] = false;
        }
    }
    while (q--) {
        cin >> l >> r >> k;
        l--;
        r--;
        o = 0;
        z = 0;
        cnt = 0;
        cur = 1;
        res = 0;
        for (int i = l; i <= r; i++) {
            if (s[i]) o++;
        }
        for (int i = r; i >= l; i--) {
            if (s[i] && cnt < k) {
                cnt++;
                res += cur;
                res %= mod;
                cur *= 2;
                cur %= mod;
            } else if (o + z < k) {
                z++;
                cnt++;
                cur *= 2;
                cur %= mod;
            }
        }
        cout << res << "\n";
    }
    return 0;
}