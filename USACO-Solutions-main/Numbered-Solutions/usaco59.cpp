#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("lazy.out");
    ifstream cin ("lazy.in");
    int n, k, num, c, m = 0;
    cin >> n >> k;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num;
            v[i][j] = num + v[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c = 0;
            for (int l = max(1, i - k); l <= min(n, i + k); l++) {
                c += v[l][min(j + k - abs(i - l), n)] - v[l][max(0, j - k + abs(i - l) - 1)];
            }
            m = max(m, c);
        }
    }
    cout << m << endl;
    return 0;
}