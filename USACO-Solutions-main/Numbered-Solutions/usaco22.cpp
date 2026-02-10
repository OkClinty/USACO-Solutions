#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q, x, y, t = 0;
    cin >> n;
    string str;
    vector<vector<tuple<bool, int, vector<pair<int, int>>>>> v(n);
    vector<int> r(n), s(n);
    pair<int, int> p;
    for (int i = 0; i < n; i++) {
        v[i].resize(n);
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (str[j] == 'R') {
                get<0>(v[i][j]) = true;
            } else {
                get<0>(v[i][j]) = false;
            }
        }
        cin >> r[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p = {i, j};
            while (p.first < n && p.second < n) {
                if (get<0>(v[p.first][p.second]) == false) {
                    p.first++;
                } else {
                    p.second++;
                }
            }
            if (p.first == n) {
                t += s[p.second];
            } else {
                t += r[p.first];
            }
        }
    }
    cout << t << "\n";
    cin >> q;
    while (q--) {
        cin >> x >> y;
        x--;
        y--;
        t = 0;
        get<0>(v[x][y]) = !get<0>(v[x][y]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p = {i, j};
                while (p.first < n && p.second < n) {
                    if (get<0>(v[p.first][p.second]) == false) {
                        p.first++;
                    } else {
                        p.second++;
                    }
                }
                if (p.first == n) {
                    t += s[p.second];
                } else {
                    t += r[p.first];
                }
            }
        }
        cout << t << "\n";
    }
    return 0;
}