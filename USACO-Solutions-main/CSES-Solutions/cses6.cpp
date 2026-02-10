#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long y, x, m;
    cin >> y >> x;
    m = max(x, y);
    cout << m * m - (m % 2 == 0) * (x + abs(m - y) - 1) - (m % 2 == 1) * (y + abs(m - x) - 1) << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
