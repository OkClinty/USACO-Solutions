#include <bits/stdc++.h>
using namespace std;

int toIndex(char c) {
    if (c < 96) {
        return c - 39;
    } else {
        return c - 97;
    }
}

void solve() {
    vector<char> a(52);
    vector<bool> v(52), c(52), d(52);
    char x, y;
    int t = 0;
    for (int i = 0; i < 52; i++) {
        a[i] = '.';
        v[i] = false;
        c[i] = false;
        d[i] = false;
    }
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++) {
        if (a[toIndex(s1[i])] != '.' && a[toIndex(s1[i])] != s2[i]) {
            cout << "-1\n";
            return;
        }
        a[toIndex(s1[i])] = s2[i];
    }
    bool b = true;
    for (int i = 0; i < 52; i++) {
        if (a[i] == '.') {
            b = false;
        }
    }
    if (b) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < s1.length(); i++) {
        if (!v[toIndex(s1[i])]) {
            x = y = s1[i];
            do {
                x = a[toIndex(x)];
                y = a[toIndex(y)];
                if (y == '.' || v[toIndex(y)] || c[toIndex(y)] && y != a[toIndex(y)]) {
                    break;
                }
                y = a[toIndex(y)];
            } while (y != '.' && !v[toIndex(y)] && !c[toIndex(y)] && x != y && y != a[toIndex(y)]);
            if (y == '.' || v[toIndex(y)] || c[toIndex(y)] || y == a[toIndex(y)]) {
                if (c[toIndex(y)] && !d[toIndex(y)]) {
                    t--;
                    d[toIndex(y)] = true;
                }
                x = s1[i];
                while (x != '.' && !v[toIndex(x)] && !c[toIndex(x)] && x != y) {
                    v[toIndex(x)] = true;
                    t++;
                    x = a[toIndex(x)];
                }
            } else {
                t++;
                do {
                    v[toIndex(x)] = true;
                    c[toIndex(x)] = true;
                    t++;
                    x = a[toIndex(x)];
                } while (x != y);
                x = s1[i];
                while (!v[toIndex(x)] && y != a[toIndex(x)]) {
                    v[toIndex(x)] = true;
                    t++;
                    y = a[toIndex(x)];
                }
            }
        }
    }
    cout << t << "\n";
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