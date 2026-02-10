#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, c = 0;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    vector<vector<int>> v(n, vector<int>(m));
    stack<pair<int, int>> s;
    pair<int, int> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '.' && !v[i][j]) {
                s.push({i, j});
                c++;
                while (!s.empty()) {
                    p = s.top();
                    s.pop();
                    if (!v[p.first][p.second] && arr[p.first][p.second] == '.') {
                        v[p.first][p.second] = true;
                        if (p.first != 0) {
                            s.push({p.first - 1, p.second});
                        }
                        if (p.first != n - 1) {
                            s.push({p.first + 1, p.second});
                        }
                        if (p.second != 0) {
                            s.push({p.first, p.second - 1});
                        }
                        if (p.second != m - 1) {
                            s.push({p.first, p.second + 1});
                        }
                    }
                }
            }
        }
    }
    cout << c;
    return 0;
}