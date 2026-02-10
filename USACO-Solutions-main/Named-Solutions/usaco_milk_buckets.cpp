#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

int sum(int v, int tl, int tr, int l, int r, vector<ll> &t) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm), t) + sum(v*2+1, tm+1, tr, max(l, tm+1), r, t);
}

void update(int v, int tl, int tr, int pos, int new_val, vector<ll> &t) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(v*2, tl, tm, pos, new_val, t);
        else update(v*2+1, tm+1, tr, pos, new_val, t);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void solve() {
    int n, p;
    ll r = 0;
    cin >> n;
    vector<ll> v(n), seg(1 << 19), cur;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        seg[(1 << 18) + i] = 1;
        a[i] = {v[i], i};
    }
    for (int i = (1 << 18) - 1; i >= 1; i--) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        p = i;
        while (p < n && a[p].f == a[i].f) {
            cur.push_back(a[p].s);
            update(1, 1, 1 << 18, a[p].s + 1, 0, seg);
            p++;
        }
        for (int j : cur) {
            r += min(sum(1, 1, 1 << 18, 1, j, seg), sum(1, 1, 1 << 18, j + 2, n, seg));
        }
        cur.clear();
        i = p - 1;
    }
    cout << r << "\n";
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}