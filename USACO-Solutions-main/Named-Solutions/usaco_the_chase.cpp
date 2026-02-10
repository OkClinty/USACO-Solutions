#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

vector<int> p;
vector<pair<int, int>> r;
vector<vector<int>> v;
vector<bool> cyc;

void eval(int num) {
    if (!v[num].empty()) {
        for (int i : v[num]) {
            if (!cyc[i]) {
                eval(i);
                if (r[i].f != -2) {
                    if (r[num].f == -2) {
                        r[num].f = r[i].f + 1;
                    } else {
                        r[num].f = min(r[num].f, r[i].f + 1);
                    }
                }
            }
        }
    }
}

void reval(int num) {
    if (!v[num].empty()) {
        for (int i : v[num]) {
            if (cyc[i]) {
                if (r[i].f != -2 && r[i].s != num) {
                    if (r[num].f == -2) {
                        r[num] = {r[i].f + 1, i};
                    } else if (r[i].f + 1 < r[num].f) {
                        r[num] = {r[i].f + 1, i};
                    }
                }
            }
        }
    }
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, f, x, y, pnt;
    cin >> n >> f;
    p.resize(n);
    r.resize(n);
    v.resize(n);
    cyc.resize(n, false);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        v[p[i]].push_back(i);
        r[i] = {-2, i};
    }
    while (f--) {
        cin >> x;
        r[x - 1].f = -1;
    }
    for (int i = 0; i < n; i++) {
        if (s.find(i) == s.end()) {
            x = i;
            y = i;
            do {
                if (s.find(x) != s.end()) {
                    break;
                }
                s.insert(x);
                x = p[x];
                y = p[p[y]];
            } while (x != y);
            if (x == y) {
                do {
                    s.insert(x);
                    cyc[x] = true;
                    x = p[x];
                } while (x != y);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (cyc[i]) {
            eval(i);
        }
    }
    s.clear();
    for (int i = 0; i < n; i++) {
        if (cyc[i] && s.find(i) == s.end()) {
            pnt = i;
            do {
                reval(pnt);
                pnt = p[pnt];
                s.insert(pnt);
            } while (pnt != i);
        }
    }
    s.clear();
    for (int i = 0; i < n; i++) {
        if (cyc[i] && s.find(i) == s.end()) {
            pnt = i;
            do {
                reval(pnt);
                pnt = p[pnt];
                s.insert(pnt);
            } while (pnt != i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << r[i].f << "\n";
    }
    return 0;
}