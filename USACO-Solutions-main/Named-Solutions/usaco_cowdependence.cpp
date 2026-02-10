#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, l;
    long long add = 0;
    cin >> n;
    vector<int> v(n), r(n), a(n);
    map<int, set<int>> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]].insert(i);
    }
    for (auto p : m) {
        if (p.second.size() <= 169) {
            set<int> s;
            a[n - 1]++;
            for (auto it = p.second.begin(); it != p.second.end(); it++) {
                for (auto itt = it; itt != p.second.end(); itt++) {
                    int x = (*itt) - (*it) - 1;
                    if (x > 0) {
                        s.insert(x);
                    }
                }
            }
            int prev = 1;
            for (auto it = s.rbegin(); it != s.rend(); it++) {
                int cnt = 0, x = *(it);
                auto itt = p.second.begin();
                while (itt != p.second.end()) {
                    l = *itt;
                    cnt++;
                    itt = p.second.lower_bound(l + x + 1);
                }
                a[x - 1] += cnt - prev;
                prev = cnt;
            }
        } else {
            for (int x = 1; x <= n; x++) {
                auto it = p.second.begin();
                while (it != p.second.end()) {
                    l = *it;
                    r[x - 1]++;
                    it = p.second.lower_bound(l + x + 1);
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        add += a[i];
        r[i] += add;
    }
    for (int i = 0; i < n; i++) {
        cout << r[i] << "\n";
    }
    return 0;
}