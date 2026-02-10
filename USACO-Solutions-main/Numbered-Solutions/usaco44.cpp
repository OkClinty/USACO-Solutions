#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q, x, y;
    long long t;
    cin >> n;
    vector<int> v(n), c;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> q;
    while (q--) {
        cin >> x >> y;
        c = v;
        c[x - 1] = y;
        sort(c.begin(), c.end());
        t = 0;
        for (int i = 1; i <= n; i++) {
            t += 1ll * c[i - 1] * i;
        }
        cout << t << "\n";
    }
    return 0;
}