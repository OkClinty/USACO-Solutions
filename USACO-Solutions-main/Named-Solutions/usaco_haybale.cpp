#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, a, b;
    cin >> n;
    vector<int> v(n), l(n), r(n);
    vector<double> s(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s[i] = (double)i / (n - i - 1);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) {
        l[i] = l[i - 1] + i * (v[i] - v[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        r[i] = r[i + 1] + (n - i - 1) * (v[i + 1] - v[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        int d = distance(s.begin(), upper_bound(s.begin(), s.end(), (double)b / a));
        if (d == n) {
            cout << l[n - 1] * a + r[n - 1] * b << "\n";
        } else {
            cout << min(l[d] * a + r[d] * b, l[d - 1] * a + r[d - 1] * b) << "\n";
        }
    }
    return 0;
}
