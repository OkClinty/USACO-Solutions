#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("mowing.out");
    ifstream cin ("mowing.in");
    int field[2001][2001], t = 0, x = 1000, y = 1000, m = INT_MAX, n, num, cx, cy;
    char c;
    cin >> n;
    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) {
            field[i][j] = -1;
        }
    }
    field[1000][1000] = 0;
    while (n--) {
        cin >> c >> num;
        cx = 0;
        cy = 0;
        if (c == 'N') {
            cy = 1;
        } else if (c == 'E') {
            cx = 1;
        } else if (c == 'S') {
            cy = -1;
        } else {
            cx = -1;
        }
        while (num--) {
            t++;
            x += cx;
            y += cy;
            if (field[y][x] != -1) {
                m = min(m, t - field[y][x]);
            }
            field[y][x] = t;
        }
    }
    if (m == INT_MAX) {
        cout << -1;
    } else {
        cout << m;
    }
    return 0;
}