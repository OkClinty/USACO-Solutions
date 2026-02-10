#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n, t, c, l = 0, r = 1e18, m;
    cin >> n >> t;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while (l < r) {
        m = l + (r - l) / 2;
        c = 0;
        for (long long i : v) {
            c += m / i;
            if (c >= t) {
                break;
            }
        }
        if (c >= t) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l;
    return 0;
}