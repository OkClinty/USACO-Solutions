#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, y, cnt = 0;
    cin >> n;
    vector<vector<bool>> v(2003, vector<bool>(2003));
    stack<pair<int, int>> s;
    pair<int, int> p;
    while (n--) {
        cin >> x >> y;
        cnt -= v[x + 501][y + 501];
        v[x + 501][y + 501] = true;
        s.push({x + 501, y + 501});
        s.push({x + 500, y + 501});
        s.push({x + 502, y + 501});
        s.push({x + 501, y + 500});
        s.push({x + 501, y + 502});
        while (!s.empty()) {
            p = s.top();
            s.pop();
            if (v[p.first + 1][p.second] + v[p.first - 1][p.second] + v[p.first][p.second + 1] + v[p.first][p.second - 1] == 3 && v[p.first][p.second]) {
                cnt++;
                if (!v[p.first + 1][p.second]) {
                    v[p.first + 1][p.second] = true;
                    s.push({p.first + 1, p.second});
                    s.push({p.first + 2, p.second});
                    s.push({p.first + 1, p.second + 1});
                    s.push({p.first + 1, p.second - 1});
                }
                if (!v[p.first - 1][p.second]) {
                    v[p.first - 1][p.second] = true;
                    s.push({p.first - 1, p.second});
                    s.push({p.first - 2, p.second});
                    s.push({p.first - 1, p.second + 1});
                    s.push({p.first - 1, p.second - 1});
                }
                if (!v[p.first][p.second + 1]) {
                    v[p.first][p.second + 1] = true;
                    s.push({p.first, p.second + 1});
                    s.push({p.first, p.second + 2});
                    s.push({p.first + 1, p.second + 1});
                    s.push({p.first - 1, p.second + 1});
                }
                if (!v[p.first][p.second - 1]) {
                    v[p.first][p.second - 1] = true;
                    s.push({p.first, p.second - 1});
                    s.push({p.first, p.second - 2});
                    s.push({p.first + 1, p.second - 1});
                    s.push({p.first - 1, p.second - 1});
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}