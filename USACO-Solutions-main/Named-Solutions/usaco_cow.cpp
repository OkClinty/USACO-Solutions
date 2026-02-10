#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

vector<int> p, sz, mk, rev;
vector<vector<int>> v;
vector<bool> cyc;

void sum_it(int num) {
    if (!v[num].empty()) {
        for (int i : v[num]) {
            if (!cyc[i]) {
                sum_it(i);
                sz[num] += sz[i];
            }
        }
    }
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, m, c = 0, o = 0, w = 0, x, y, guy, cnt, mark;
    char ch;
    cin >> n;
    p.resize(n);
    sz.resize(n, 1);
    v.resize(n);
    cyc.resize(n, false);
    mk.resize(n);
    rev.resize(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        v[p[i]].push_back(i);
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
                    rev[p[x]] = x;
                    mk[x] = 4;
                    x = p[x];
                } while (x != y);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (cyc[i]) {
            sum_it(i);
        }
    }
    cin >> m;
    while (m--) {
        cin >> guy >> ch;
        guy--;
        if (cyc[guy]) {
            x = guy;
            cnt = 0;
            do {
                cnt += sz[x];
                x = rev[x];
            } while (mk[x] == 4 && x != guy);
            if (mk[x] != 4) {
                if (mk[guy] == 4) {
                    x = guy;
                    do {
                        x = p[x];
                    } while (mk[x] == 4);
                    mark = mk[x];
                } else {
                    mark = mk[guy];
                }
                switch (mark) {
                    case 1:
                        c -= cnt;
                        break;
                    case 2:
                        o -= cnt;
                        break;
                    case 3:
                        w -= cnt;
                        break;
                }
            }
            switch (ch) {
                case 'C':
                    c += cnt;
                    mk[guy] = 1;
                    break;
                case 'O':
                    o += cnt;
                    mk[guy] = 2;
                    break;
                case 'W':
                    w += cnt;
                    mk[guy] = 3;
                    break;
            }
        } else {
            mark = mk[guy];
            switch (ch) {
                case 'C':
                    c += sz[guy];
                    mk[guy] = 1;
                    break;
                case 'O':
                    o += sz[guy];
                    mk[guy] = 2;
                    break;
                case 'W':
                    w += sz[guy];
                    mk[guy] = 3;
                    break;
            }
            x = guy;
            if (guy != p[guy]) {
                do {
                    x = p[x];
                    sz[x] -= sz[guy];
                } while (mk[x] == 0);
                if (mk[x] == 4) {
                    y = x;
                    do {
                        y = p[y];
                    } while (x != y && mk[y] == 4);
                    mark = mk[y];
                } else {
                    mark = mk[x];
                }
            }
            switch (mark) {
                case 1:
                    c -= sz[guy];
                    break;
                case 2:
                    o -= sz[guy];
                    break;
                case 3:
                    w -= sz[guy];
                    break;
            }
            p[guy] = guy;
        }
        cout << c << " " << o << " " << w << "\n";
    }
    return 0;
}