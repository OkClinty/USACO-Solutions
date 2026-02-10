#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> v;

bool process(long long d, int n) {
    long long c = v[0].first;
    int p = 0;
    n--;
    while (n--) {
        c += d;
        while (c > v[p].second && p < v.size()) {
            p++;
        }
        c = max(v[p].first, c);
    }
    return (p < v.size());
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("socdist.out");
    ifstream cin ("socdist.in");
    int n, m;
    long long l = 1, r = 1e18, md;
    cin >> n >> m;
    v.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    while (l < r) {
        md = (l + r + 1) / 2;
        if (process(md, n)) {
            l = md;
        } else {
            r = md - 1;
        }
    }
    cout << l;
    return 0;
}