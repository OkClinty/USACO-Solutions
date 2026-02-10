#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, x, y, X = -1, Y = -1;
    string s;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m)), c(n, vector<char>(m));
    vector<vector<int>> dr(n, vector<int>(m));
    vector<vector<bool>> vs(n, vector<bool>(m));
    vector<pair<pair<int, int>, char>> d = {{{1, 0}, 'D'}, {{-1, 0}, 'U'}, {{0, 1}, 'R'}, {{0, -1}, 'L'}};
    queue<pair<pair<int, int>, int>> q;
    stack<char> st;
    pair<pair<int, int>, int> p;
    pair<int, int> a;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            v[i][j] = s[j];
            c[i][j] = '.';
            if (s[j] == 'A') {
                a = {i, j};
                c[i][j] = '!';
            } else if (s[j] == 'M') {
                q.push({{i, j}, 0});
            }
        }
    }
    while (!q.empty()) {
        p = q.front();
        q.pop();
        y = p.first.first;
        x = p.first.second;
        if (y >= 0 && x >= 0 && y < n && x < m && !vs[y][x] && v[y][x] != '#') {
            vs[y][x] = true;
            dr[y][x] = p.second;
            for (auto i : d) {
                q.push({{y + i.first.first, x + i.first.second}, p.second + 1});
            }
        }
    }
    if (!vs[a.first][a.second] || dr[a.first][a.second] != 0) {
        q.push({a, 0});
    }
    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (auto i : d) {
            y = p.first.first + i.first.first;
            x = p.first.second + i.first.second;
            if (y >= 0 && x >= 0 && y < n && x < m && c[y][x] == '.' && v[y][x] != '#' && (p.second + 1 < dr[y][x] || !vs[y][x])) {
                c[y][x] = i.second;
                q.push({{y, x}, p.second + 1});
                if (y == 0 || x == 0 || y == n - 1 || x == m - 1) {
                    Y = y;
                    X = x;
                }
            }
        }
    }
    if (a.first == 0 || a.second == 0 || a.first == n - 1 || a.second == m - 1) {
        Y = a.first;
        X = a.second;
    }
    if (Y == -1) {
        cout << "NO";
    } else {
        cout << "YES\n";
        while (v[Y][X] != 'A') {
            st.push(c[Y][X]);
            if (c[Y][X] == 'R') {
                X--;
            } else if (c[Y][X] == 'L') {
                X++;
            } else if (c[Y][X] == 'D') {
                Y--;
            } else if (c[Y][X] == 'U') {
                Y++;
            }
        }
        cout << st.size() << "\n";
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
    }
    return 0;
}