#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("feast.out");
    ifstream cin ("feast.in");
    int t, a, b;
    cin >> t >> a >> b;
    vector<bool> v(t + 1);
    v[0] = true;
    for (int i = 0; i <= t; i++) {
        if (v[i]) {
            if (i + a <= t) {
                v[i + a] = true;
            }
            if (i + b <= t) {
                v[i + b] = true;
            }
        }
    }
    for (int i = 0; i <= t; i++) {
        if (v[i]) {
            v[i] = false;
            v[i / 2] = true;
        }
    }
    for (int i = 0; i <= t; i++) {
        if (v[i]) {
            if (i + a <= t) {
                v[i + a] = true;
            }
            if (i + b <= t) {
                v[i + b] = true;
            }
        }
    }
    for (int i = t; i >= 0; i--) {
        if (v[i]) {
            cout << i;
            break;
        }
    }
    return 0;
}