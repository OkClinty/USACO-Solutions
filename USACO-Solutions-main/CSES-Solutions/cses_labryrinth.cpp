#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, x, y;
    string s;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m)), c(n, vector<char>(m));
    vector<pair<pair<int, int>, char>> d = {{{1, 0}, 'D'}, {{-1, 0}, 'U'}, {{0, 1}, 'R'}, {{0, -1}, 'L'}};
    queue<pair<int, int>> q;
    stack<char> st;
    pair<int, int> p;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            v[i][j] = s[j];
            c[i][j] = '.';
            if (s[j] == 'A') {
                q.push({i, j});
                c[i][j] = '!';
            }
        }
    }
    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (auto i : d) {
            y = p.first + i.first.first;
            x = p.second + i.first.second;
            if (y >= 0 && x >= 0 && y < n && x < m && c[y][x] == '.' && v[y][x] != '#') {
                c[y][x] = i.second;
                q.push({y, x});
            }
        }
    }
    y = -1;
    x = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'B' && c[i][j] != '.') {
                y = i;
                x = j;
            }
        }
    }
    if (y == -1) {
        cout << "NO";
    } else {
        cout << "YES\n";
        while (v[y][x] != 'A') {
            st.push(c[y][x]);
            if (c[y][x] == 'R') {
                x--;
            } else if (c[y][x] == 'L') {
                x++;
            } else if (c[y][x] == 'D') {
                y--;
            } else if (c[y][x] == 'U') {
                y++;
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