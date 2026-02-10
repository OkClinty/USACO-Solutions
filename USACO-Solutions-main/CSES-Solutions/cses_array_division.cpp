#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k, c;
    long long l = 1, r = 1e15, m, s;
    bool b;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while (l < r) {
        m = (l + r) / 2;
        s = 0;
        c = 0;
        b = true;
        for (int i = 0; i < n; i++) {
            if (v[i] > m) {
                b = false;
                break;
            } else if (s + v[i] > m) {
                c++;
                s = v[i];
            } else {
                s += v[i];
            }
        }
        if (c + 1 <= k && b) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l;
    return 0;
}