#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, t = 0;
    string s;
    cin >> n >> k >> s;
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = '.';
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') {
            if (i + k >= n) {
                i -= (i + k) - n + 1;
            }
            v[i + k] = 'G';
            i += k * 2;
            t++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'H') {
            if (i + k >= n) {
                i -= (i + k) - n + 1;
            }
            while (v[i + k] == 'G') {
                i--;
            }
            v[i + k] = 'H';
            i += k * 2;
            t++;
        }
    }
    cout << t << "\n";
    for (int i = 0; i < n; i++) {
        cout << v[i];
    }
    cout << "\n";
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