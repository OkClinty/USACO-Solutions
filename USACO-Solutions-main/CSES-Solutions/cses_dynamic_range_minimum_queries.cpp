#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q, num, a, b, pw = pow(2, 18), p, x, y, s;
    cin >> n >> q;
    vector<int> v(pow(2, 19), INT_MAX);
    for (int i = pw; i < pw + n; i++) {
        cin >> v[i];
    }
    for (int i = pw - 1; i > 0; i--) {
        v[i] = min(v[i * 2], v[i * 2 + 1]);
    }
    while (q--) {
        cin >> num >> a >> b;
        a--;
        b--;
        if (num == 1) {
            v[pw + a] = b + 1;
            p = (pw + a) / 2;
            while (p > 0) {
                v[p] = min(v[p * 2], v[p * 2 + 1]);
                p /= 2;
            }
        } else {
            x = a + pw;
            y = b + pw;
            s = INT_MAX;
            while (x <= y) {
                if (x % 2 == 1) {
                    s = min(s, v[x]);
                    x++;
                }
                if (y % 2 == 0) {
                    s = min(s, v[y]);
                    y--;
                }
                x /= 2;
                y /= 2;
            }
            cout << s << "\n";
        }
    }
    return 0;
}