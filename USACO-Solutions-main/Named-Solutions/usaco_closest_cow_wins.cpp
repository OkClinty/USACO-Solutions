#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int k, m, n, b = -1;
    long long r = 0, t = 0, c, mx;
    cin >> k >> m >> n;
    vector<pair<int, int>> p(k + m);
    vector<long long> v;
    for (int i = 0; i < k; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for (int i = k; i < k + m; i++) {
        cin >> p[i].first;
        p[i].second = -1;
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < k + m; i++) {
        if (p[i].second == -1) {
            if (b == -1) {
                v.push_back(t);
            } else {
                c = 0;
                mx = 0;
                for (int l = b + 1, r = b; l < i; l++) {
                    while (r + 1 < i && (p[r + 1].first - p[l].first) * 2 < p[i].first - p[b].first) {
                        r++;
                        c += p[r].second;
                    }
                    mx = max(mx, c);
                    c -= p[l].second;
                }
                v.push_back(mx);
                v.push_back(t - mx);
            }
            b = i;
            t = 0;
        } else {
            t += p[i].second;
        }
    }
    v.push_back(t);
    sort(v.begin(), v.end(), greater<int>());
    v.resize(n);
    for (int i = 0; i < n; i++) {
        r += v[i];
    }
    cout << r;
    return 0;
}