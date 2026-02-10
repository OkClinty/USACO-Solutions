#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s, f = "";
    int q, x, y, a, b, c;
    cin >> s >> q;
    vector<vector<int>> v(3);
    for (int i = 0; i < 3; i++) {
        v[i].resize(s.size() + 1);
    }
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < 3; j++) {
            v[j][i] = v[j][i - 1];
        }
        if (s[i - 1] == 'C') {
            v[0][i]++;
        } else if (s[i - 1] == 'O') {
            v[1][i]++;
        } else {
            v[2][i]++;
        }
    }
    while (q--) {
        cin >> x >> y;
        a = v[0][y] - v[0][x - 1];
        b = v[1][y] - v[1][x - 1];
        c = v[2][y] - v[2][x - 1];
        if ((b + c) % 2 == 0 && (a + b) % 2 == 1) {
            f += 'Y';
        } else {
            f += 'N';
        }
    }
    cout << f;
    return 0;
}