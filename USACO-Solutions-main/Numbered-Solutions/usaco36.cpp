#include <bits/stdc++.h>
using namespace std;

bool compareSecond(const pair<int, int> p1, const pair<int, int> p2) {
    return p1.second < p2.second;
}

int rangeSum(int x1, int y1, int x2, int y2, const vector<vector<int>>& v) {
    return v[x1][y1] + v[x2 + 1][y2 + 1] - v[x1][y2 + 1] - v[x2 + 1][y1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, y;
    long long t = 1;
    cin >> n;
    vector<pair<int, int>> p(n);
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        p[i] = {x, y};
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        p[i].first = i + 1;
    }
    sort(p.begin(), p.end(), compareSecond);
    for (int i = 0; i < n; i++) {
        p[i].second = i + 1;
    }
    for (int i = 0; i <= n; i++) {
        v[i].resize(n + 1);
    }
    for (int i = 0; i < n; i++) {
        v[p[i].first][p[i].second] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            t += rangeSum(0, i, min(p[i].first, p[j].first) - 1, j, v) * rangeSum(max(p[i].first, p[j].first) - 1, i, n - 1, j, v);
        }
    }
    cout << t;
    return 0;
}