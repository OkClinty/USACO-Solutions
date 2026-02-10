#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

vector<vector<pair<char, int>>> v(1500);
vector<int> r(1500), d(1500);
int n;

int count(const int i, const int j) {
    int t = 0, p;
    for (int x = i; x >= 0; x--) {
        for (int y = j; y >= 0; y--) {
            p = v[x][y].second;
            if (y == n - 1 && v[x][y].first == 'R') {
                v[x][y].second = r[x];
            } else if (x == n - 1 && v[x][y].first == 'D') {
                v[x][y].second = d[y];
            } else {
                if (v[x][y].first == 'R') {
                    v[x][y].second = v[x][y + 1].second;
                } else {
                    v[x][y].second = v[x + 1][y].second;
                }
            }
            t += v[x][y].second - p;
        }
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q, x, y, t;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        v[i].resize(n);
        cin >> s;
        for (int j = 0; j < n; j++) {
            v[i][j].first = s[j];
        }
        cin >> r[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    t = count(n - 1, n - 1);
    cout << t << "\n";
    cin >> q;
    while (q--) {
        cin >> x >> y;
        if (v[x - 1][y - 1].first == 'R') {
            v[x - 1][y - 1].first = 'D';
        } else {
            v[x - 1][y - 1].first = 'R';   
        }
        t += count(x - 1, y - 1);
        cout << t << "\n";
    }
    return 0;
}