#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream fout ("lightson.out");
    ifstream fin ("lightson.in");
    int n, m, x, y, a, b, t = 0;
    fin >> n >> m;
    vector<vector<pair<bool, vector<pair<int, int>>>>> v(n + 1);
    vector<vector<bool>> l(n + 1);
    stack<pair<int, int>> s;
    pair<int, int> p;
    s.push({1, 1});
    for (int i = 1; i <= n; i++) {
        v[i].resize(n + 1);
        l[i].resize(n + 1);
    }
    while (m--) {
        fin >> x >> y >> a >> b;
        v[x][y].second.push_back({a, b});
    }
    l[1][1] = true;
    for (int k = 0; k < 50; k++) {
        s.push({1, 1});
        while (!s.empty()) {
            p = s.top();
            s.pop();
            if (p.first == 0 || p.second == 0 || p.first == n + 1 || p.second == n + 1 || v[p.first][p.second].first || !l[p.first][p.second]) {
                continue;
            }
            v[p.first][p.second].first = true;
            for (int i = 0; i < v[p.first][p.second].second.size(); i++) {
                l[v[p.first][p.second].second[i].first][v[p.first][p.second].second[i].second] = true;
            }
            s.push({p.first + 1, p.second});
            s.push({p.first - 1, p.second});
            s.push({p.first, p.second + 1});
            s.push({p.first, p.second - 1});
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                v[i][j].first = false;
            }
        }   
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            t += l[i][j];
        }
    }
    fout << t;
    return 0;
}