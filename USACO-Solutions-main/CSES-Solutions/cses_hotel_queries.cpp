#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

const int MAXN = 200000;
int t[4 * MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int maximum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return maximum(v*2, tl, tm, l, min(r, tm))
           + maximum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, x, l, r;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(a, 1, 0, n - 1);
    while (m--) {
        cin >> x;
        l = 0, r = n - 1;
        while (l < r) {
            int med = (l + r) / 2;
            if (maximum(1, 0, n - 1, l, med) >= x) {
                r = med;
            } else {
                l = med + 1;
            }
        }
        if (maximum(1, 0, n - 1, r, r) < x) {
            cout << "0 ";
        } else {
            cout << r + 1 << " ";
            update(1, 0, n - 1, r, maximum(1, 0, n - 1, r, r) - x);
        }
    }
    return 0;
}