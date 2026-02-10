#include <bits/stdc++.h>
using namespace std;

int c = 0;

vector<vector<char>> reserve(vector<vector<char>> b, int x, int y) {
    for (int i = 0; i < 8; i++) {
        b[y][i] = '*';
        b[i][x] = '*';
        if (x + i < 8 && y + i < 8) {
            b[y + i][x + i] = '*';
        }
        if (x - i >= 0 && y + i < 8) {
            b[y + i][x - i] = '*';
        }
        if (x + i < 8 && y - i >= 0) {
            b[y - i][x + i] = '*';
        }
        if (x - i >= 0 && y - i >= 0) {
            b[y - i][x - i] = '*';
        }
    }
    return b;
}

void recur(vector<vector<char>> b, int d) {
    if (d == 8) {
        c++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (b[d][i] != '*') {
            recur(reserve(b, i, d), d + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<vector<char>> b(8);
    for (int i = 0; i < 8; i++) {
        b[i].resize(8);
        for (int j = 0; j < 8; j++) {
            cin >> b[i][j];
        }
    }
    recur(b, 0);
    cout << c << "\n";
    return 0;
}