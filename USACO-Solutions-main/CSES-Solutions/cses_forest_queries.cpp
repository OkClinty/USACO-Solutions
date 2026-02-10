#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q, y1, x1, y2, x2;
    string s;
    cin >> n >> q;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= n; j++) {
            v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            v[i][j] += (s[j - 1] == '*');
        }
    }
    while (q--) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << v[y2][x2] - v[y2][x1 - 1] - v[y1 - 1][x2] + v[y1 - 1][x1 - 1] << "\n";
    }
    return 0;
}