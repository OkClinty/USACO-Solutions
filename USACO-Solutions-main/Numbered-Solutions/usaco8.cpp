#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> v(100001);

int spread(int s, int p, bool b) {
    if (v[s].size() - b == 0) {
        return 0;
    }
    int t = (int)ceil(log2(v[s].size() - b + 1));
    for (int i = 0; i < v[s].size(); i++) {
        if (v[s][i] != p) {
            t++;
            t += spread(v[s][i], s, true);
        }
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int x, y;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << spread(1, -1, false);
    return 0;
}