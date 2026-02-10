#include <bits/stdc++.h>
using namespace std;

int index(char c) {
    if (c > 96) {
        return c - 97;
    } else {
        return c - 39;
    }
}

void solve() {
    string s1, s2;
    int t = 0;
    char a, b;
    cin >> s1 >> s2;
    vector<char> l(52);
    vector<bool> v(52);
    for (int i = 0; i < 52; i++) {
        l[i] = '.';
    }
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] > 96) {
            if (l[index(s1[i])] != '.' && l[index(s1[i])] != s2[i]) {
                cout << "-1\n";
                return;
            }
            l[index(s1[i])] = s2[i];
        } else {
            if (l[index(s1[i])] != '.' && l[index(s1[i])] != s2[i]) {
                cout << "-1\n";
                return;
            }
            l[index(s1[i])] = s2[i];
        }
    }
    for (int i = 0; i < s1.size(); i++) {
        if (v[index(s1[i])] || s1[i] == s2[i]) {
            continue;
        }
        a = b = s1[i];
        do {
            a = l[index(a)];
            if (a == l[index(a)]) {
                break;
            }
            b = l[index(b)];
            if (b == '.') {
                break;
            }
            b = l[index(b)];
        } while (a != b && b != '.');
        if (b != '.' && a != l[index(a)]) {
            do {
                v[index(a)] = true;
                a = l[index(a)];
                t++;
            } while (a != b);
        }
        t++;
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