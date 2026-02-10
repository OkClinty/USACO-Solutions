#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("ccski.in");
    ofstream cout ("ccski.out");
    int m, n, l = 0, d, r = 1e9, t = 0, c, num;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    vector<vector<bool>> v(m, vector<bool>(n)), w(m, vector<bool>(n));
    stack<pair<int, int>> s;
    pair<int, int> p, b = {-1, -1};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            w[i][j] = num;
            t += w[i][j];
            if (w[i][j] && b.first == -1) {
                b = {i, j};
            }
        }
    }
    if (t) {
        while (l < r) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    v[i][j] = false;
                }
            }
            d = (l + r) / 2;
            c = 0;
            s.push(b);
            while (!s.empty()) {
                p = s.top();
                s.pop();
                if (!v[p.first][p.second]) {
                    c += w[p.first][p.second];
                    v[p.first][p.second] = true;
                    if (p.first > 0 && abs(arr[p.first][p.second] - arr[p.first - 1][p.second]) <= d) {
                        s.push({p.first - 1, p.second});
                    }
                    if (p.first < m - 1 && abs(arr[p.first][p.second] - arr[p.first + 1][p.second]) <= d) {
                        s.push({p.first + 1, p.second});
                    }
                    if (p.second > 0 && abs(arr[p.first][p.second] - arr[p.first ][p.second - 1]) <= d) {
                        s.push({p.first, p.second - 1});
                    }
                    if (p.second < n - 1 && abs(arr[p.first][p.second] - arr[p.first][p.second + 1]) <= d) {
                        s.push({p.first, p.second + 1});
                    }
                }
            }
            if (c == t) {
                r = d;
            } else {
                l = d + 1;
            }
        }
    }
    cout << l;
    return 0;
}