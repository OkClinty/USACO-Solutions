#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream fout ("lightson.out");
    ifstream fin ("lightson.in");
    int n, m, a, b, c, d, t = 0;
    fin >> n >> m;
    vector<vector<pair<bool, vector<pair<int, int>>>>> v(n + 1);
    vector<vector<bool>> y(n + 1);
    stack<pair<int, int>> s;
    pair<int, int> p;
    s.push({1, 1});
    for (int i = 1; i <= n; i++) {
        v[i].resize(n + 1);
        y[i].resize(n + 1);
    }
    while (m--) {
        fin >> a >> b >> c >> d;
        v[a][b].second.push_back({c, d});
    }
    while (!s.empty()) {
        p = s.top();
        s.pop();
        if (!v[p.first][p.second].first) {
            v[p.first][p.second].first = true;
            t++;
        }
        for (auto x : v[p.first][p.second].second) {
            if (!v[x.first][x.second].first) {
                s.push(x);
            }
        }
    }
    fout << t;
    return 0;
}