#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("gates.out");
    ifstream cin ("gates.in");    
    int n, t = 0, x = 1001, y = 1001, xc, yc;
    bool b;
    string s;
    cin >> n >> s;
    bool a[2001][2001];
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            a[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        b = false;
        xc = 0;
        yc = 0;
        switch (s[i]) {
            case 'N':
                yc++;
                b = a[x - 1][y] || a[x + 1][y];
                break;
            case 'E':
                xc++;
                b = a[x][y - 1] || a[x][y + 1];
                break;
            case 'S':
                yc--;
                b = a[x - 1][y] || a[x + 1][y];
                break;
            case 'W':
                xc--;
                b = a[x][y - 1] || a[x][y + 1];
                break;
        }
        if (a[x][y] && b) {
            t++;
        }
        a[x][y] = true;
        x += xc;
        y += yc;
    }
    cout << t;
    return 0;
}