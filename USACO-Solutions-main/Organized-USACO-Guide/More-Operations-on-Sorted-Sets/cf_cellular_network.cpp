#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, mx = 0, l = 0, r, p = 0;
    cin >> n >> m;
    r = n - 1;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    while (b[0] > a[l] && l < n) {
        mx = max(mx, b[0] - a[l]);
        l++;
    }
    while (b[m - 1] < a[r] && r >= 0) {
        mx = max(mx, a[r] - b[m - 1]);
        r--;
    }
    for (int i = l; i <= r; i++) {
        while (a[i] > b[p + 1]) {
            p++;
        }
        mx = max(mx, min(abs(a[i] - b[p]), abs(a[i] - b[p + 1])));
    }
    cout << mx << "\n";
    return 0;
}