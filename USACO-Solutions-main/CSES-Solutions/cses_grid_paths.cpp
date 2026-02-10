#include <bits/stdc++.h>
using namespace std;
 
int c = 0;
string s;

vector<vector<bool>> g(7);
 
void recur(int p, int x, int y) {
    if (y < 0 || x < 0 || y > 6 || x > 6 || g[y][x]) {
        return;
    } else if (p == 48) {
        if (x == 0 && y == 6) {
            c++;
        }
        return;
    }
    if ((x == 0 && y == 6) || ((((y == 0 || g[y - 1][x]) && (y == 6 || g[y + 1][x])) && x != 0 && x != 6 && !g[y][x - 1] && !g[y][x + 1])) || ((((x == 0 || g[y][x - 1]) && (x == 6 || g[y][x + 1])) && y != 0 && y != 6 && !g[y - 1][x] && !g[y + 1][x]))) {
        return;
    }
    g[y][x] = true;
    if (s[p] == '?') {
        recur(p + 1, x + 1, y);
        recur(p + 1, x - 1, y);
        recur(p + 1, x, y + 1);
        recur(p + 1, x, y - 1);
    } else if (s[p] == 'R') {
        recur(p + 1, x + 1, y);
    } else if (s[p] == 'L') {
        recur(p + 1, x - 1, y);
    } else if (s[p] == 'U') {
        recur(p + 1, x, y - 1);
    } else if (s[p] == 'D') {
        recur(p + 1, x, y + 1);
    }
    g[y][x] = false;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s;
    for (int i = 0; i < 7; i++) {
        g[i].resize(7);
        for (int j = 0; j < 7; j++) {
            g[i][j] = false;
        }
    }
    recur(0, 0, 0);
    cout << c << "\n";
    return 0;
}