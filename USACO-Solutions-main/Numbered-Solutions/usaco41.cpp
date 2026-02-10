#include <bits/stdc++.h>
using namespace std;

struct Crime {
    long long x, y, t;
};

bool comp(Crime a, Crime b) {
    return a.t < b.t;
}

long long distance(long long x1, long long y1, long long x2, long long y2) {
    return ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long g, n, x, y, t, r = 0;
    cin >> g >> n;
    vector<Crime> v(g);
    Crime c;
    for (int i = 0; i < g; i++) {
        cin >> x >> y >> t;
        v[i] = {x, y, t};
    }
    sort(v.begin(), v.end(), comp);
    while (n--) {
        cin >> x >> y >> t;
        c = {x, y, t};
        auto p = upper_bound(v.begin(), v.end(), c, comp);
        if (p == v.begin()) {
            r += ((v[p - v.begin()].t - t) * (v[p - v.begin()].t - t) < distance(x, y, v[p - v.begin()].x, v[p - v.begin()].y));
        } else if (p == v.end()) {
            r += ((v[p - v.begin() - 1].t - t) * (v[p - v.begin() - 1].t - t) < distance(x, y, v[p - v.begin() - 1].x, v[p - v.begin() - 1].y));
        } else {
            r += ((v[p - v.begin()].t - t) * (v[p - v.begin()].t - t) < distance(x, y, v[p - v.begin()].x, v[p - v.begin()].y) || (v[p - v.begin() - 1].t - t) * (v[p - v.begin() - 1].t - t) < distance(x, y, v[p - v.begin() - 1].x, v[p - v.begin() - 1].y));
        }
    }
    cout << r;
    return 0;
}