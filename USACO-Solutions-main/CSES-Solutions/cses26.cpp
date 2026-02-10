#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n, l = 0, r = 0, c = 0, m = INT_MIN;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while (r < n) {
        c += v[r];
        if (v[l] < 0 && l != r) {
            c -= v[l];
            l++;
        }
        m = max(m, c);
        if (c < 0) {
            l = r + 1;
            c = 0;
        }
        r++;
    }
    cout << m << "\n";
    return 0;
}