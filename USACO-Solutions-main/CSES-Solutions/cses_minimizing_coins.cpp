#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(x + 1);
    b[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= x; i++) {
        b[i] = 1e7;
        for (int j : a) {
            if (i - j >= 0) {
                b[i] = min(b[i], b[i - j] + 1);
            }
        }
    }
    if (b[x] >= 1e7) {
        cout << -1;
    } else {
        cout << b[x];
    }
    return 0;
}