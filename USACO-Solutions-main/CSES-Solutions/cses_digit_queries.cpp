#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    long long n, c = 9, f = 9;
    bool b;
    int t = 0, v;
    cin >> n;
    while (n > c) {
        n -= c;
        c += f;
        c *= 10;
        f *= 10;
    }
    while (c > 0) {
        c -= f;
        t++;
    }
    v = (t - 1) - ((n - 1) % t);
    b = (v == t - 1);
    n--;
    n /= t;
    while (v--) {
        n /= 10;
    }
    cout << (n % 10) + b << "\n";
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