#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, y, m;
    long long t = 0;
    cin >> n;
    vector<int> a(n + 1), p(n + 1);
    vector<bool> v(n + 1);
    set<int> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i];
        t += p[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            x = i;
            y = i;
            s.clear();
            do {
                s.insert(x);
                x = a[x];
                y = a[a[y]];
            } while (x != y && !v[x]);
            if (s.find(x) != s.end()) {
                m = 1e9 + 5;
                do {
                    v[x] = true;
                    m = min(m, p[x]);
                    x = a[x];
                } while (x != y);
                t -= m;
            }
        }
    }
    cout << t;
    return 0;
}