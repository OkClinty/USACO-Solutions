#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k, ap = 0, bp = 0, c = 0;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while (ap < n && bp < m) {
        if (abs(a[ap] - b[bp]) <= k) {
            c++;
            ap++;
            bp++;
        } else if (a[ap] < b[bp]) {
            ap++;
        } else {
            bp++;
        }
    }
    cout << c << "\n";
    return 0;
}