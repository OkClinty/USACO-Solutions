#include <bits/stdc++.h>
using namespace std;

int c = 0;
string s;

void recur(vector<vector<bool>> g, int p, int x, int y) {
    if (y < 0 || x < 0 || y > 6 || x > 6 || g[y][x]) {
        return;
    } else if (p == 48) {
        if (x == 0 && y == 6) {
            c++;
        }
        return;
    }
    g[y][x] = true;
    if (s[p] == '?') {
        recur(g, p + 1, x + 1, y);
        recur(g, p + 1, x - 1, y);
        recur(g, p + 1, x, y + 1);
        recur(g, p + 1, x, y - 1);
    } else if (s[p] == 'R') {
        recur(g, p + 1, x + 1, y);
    } else if (s[p] == 'L') {
        recur(g, p + 1, x - 1, y);
    } else if (s[p] == 'U') {
        recur(g, p + 1, x, y - 1);
    } else if (s[p] == 'D') {
        recur(g, p + 1, x, y + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s;
    vector<vector<bool>> g(7);
    for (int i = 0; i < 7; i++) {
        g[i].resize(7);
        for (int j = 0; j < 7; j++) {
            g[i][j] = false;
        }
    }
    recur(g, 0, 0, 0);
    cout << c << "\n";
    return 0;
}