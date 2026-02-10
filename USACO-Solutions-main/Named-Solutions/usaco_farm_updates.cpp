#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

vector<int> p, r, sz;
vector<vector<int>> guys;

void init(int v) {
    p[v] = v;
    sz[v] = 1;
    guys[v] = {v};
}

int finds(int v) {
    if (v == p[v])
        return v;
    return p[v] = finds(p[v]);
}

void unions(int a, int b, int t) {
    a = finds(a);
    b = finds(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        if (r[a] == -1 && r[b] == -1) {
            for (int i : guys[b]) {
                guys[a].push_back(i);
            }
        } else if (r[a] == -1) {
            for (int i : guys[a]) {
                r[i] = max(r[i], t);
            }
        } else if (r[b] == -1) {
            for (int i : guys[b]) {
                r[i] = max(r[i], t);
            }
        }
    }
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, q, x;
    cin >> n >> q;
    vector<bool> a(n + 1, true), eds;
    vector<pair<char, pair<int, int>>> o(q);
    vector<pair<int, int>> e;
    r.resize(n + 1);
    p.resize(n + 1);
    sz.resize(n + 1);
    guys.resize(n + 1);
    for (int i = 0; i < q; i++) {
        cin >> o[i].f;
        if (o[i].f == 'D') {
            cin >> o[i].s.f;
            o[i].s.s = -1;
            a[o[i].s.f] = false;
        } else if (o[i].f == 'A') {
            cin >> o[i].s.f >> o[i].s.s;
            e.push_back(o[i].s);
            eds.push_back(true);
        } else {
            cin >> o[i].s.f;
            o[i].s.s = -1;
            o[i].s.f--;
            eds[o[i].s.f] = false;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            r[i] = q;
        } else {
            r[i] = -1;
        }
        init(i);
    }
    for (int i = 0; i < e.size(); i++) {
        if (eds[i]) {
            unions(e[i].f, e[i].s, q);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        if (o[i].f == 'D') {
            x = finds(o[i].s.f);
            for (int j : guys[x]) {
                r[j] = max(r[j], i);
            }
        } else if (o[i].f == 'R') {
            unions(e[o[i].s.f].f, e[o[i].s.f].s, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << r[i] << "\n";
    }
    return 0;
}