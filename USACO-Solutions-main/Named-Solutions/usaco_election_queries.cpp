#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q, x, y, z, res;
    cin >> n >> q;
    vector<int> a(n + 1), v(n + 1);
    set<int> f, b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (f.empty()) {
            if (v[i] > 0) {
                f.insert(i);
            }
        } else {
            if (v[i] > v[(*prev(f.end()))]) {
                f.insert(i);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        if (b.empty()) {
            if (v[i] > 0) {
                b.insert(i);
            }
        } else {
            if (v[i] > v[(*b.begin())]) {
                b.insert(i);
            }
        }
    }
    while (q--) {
        cin >> x >> y;
        z = a[x];
        a[x] = y;
        v[z]--;
        v[y]++;
        auto it = f.find(y);
        if (it != f.end() && it != prev(f.end())) {
            if (v[y] >= v[*next(it)]) {
                f.erase(next(it));
            }
        } else if (it == f.end()) {
            auto itt = f.lower_bound(y);
            if (itt == f.begin() || v[*prev(itt)] < v[y]) {
                f.insert(y);
                itt = f.find(y);
                if (itt != prev(f.end()) && v[y] >= v[*next(itt)]) {
                    f.erase(next(itt));
                }
            }
        }
        it = b.find(y);
        if (it != b.end() && it != b.begin()) {
            if (v[y] >= v[*prev(it)]) {
                b.erase(prev(it));
            }
        } else if (it == b.end()) {
            auto itt = b.lower_bound(y);
            if (itt == b.end() || v[*itt] < v[y]) {
                b.insert(y);
                itt = b.find(y);
                if (itt != b.begin() && v[y] >= v[*prev(itt)]) {
                    b.erase(prev(itt));
                }
            }
        }
        it = f.find(z);
        if (it != f.end()) {
            for (int i = z + 1; i < *next(it); i++) {
                if (v[i] == v[z] + 1) {
                    f.insert(i);
                    break;
                }
            }
            if (it == f.begin()) {
                if (v[z] == 0) {
                    f.erase(it);
                }
            } else if (v[z] <= v[*prev(it)]) {
                f.erase(it);
            }
        }
        it = b.find(z);
        if (it != b.end()) {
            for (int i = z - 1; i > *prev(it); i--) {
                if (v[i] == v[z] + 1) {
                    b.insert(i);
                    break;
                }
            }
            if (it == prev(b.end())) {
                if (v[z] == 0) {
                    b.erase(it);
                }
            } else if (v[z] <= v[*next(it)]) {
                b.erase(it);
            }
        }
        res = 0;
        auto l = f.begin();
        auto r = b.begin();
        while (l != f.end()) {
            while (r != b.end() && v[*l] + v[*r] >= v[*prev(f.end())]) {
                res = max(res, *r - *l);
                r++;
            }
            l++;
        }
        cout << res << "\n";
    }
    return 0;
}