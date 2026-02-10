#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, c = 200, f = 100;
    cin >> n;
    if (n < 10) {
        cout << n << "\n";
        return;
    }
    n -= 9;
    while (n > c) {
        n -= c;
        c += f;
        c *= 10;
        f *= 10;
    }
    while (c % 10 == 0) {
        c /= 10;
    }
    cout << (int)ceil(1.0 * n / (c * pow(10, n % c))) - (n % c == 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}