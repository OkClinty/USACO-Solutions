#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("mootube.in");
    ofstream cout ("mootube.out");
    int n, q, a, b, r, cnt;
    cin >> n >> q;
    vector<vector<pair<int, int>>> v(n + 1);
    stack<pair<int, pair<int, int>>> s;
    pair<int, pair<int, int>> p;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> r;
        v[a].push_back({b, r});
        v[b].push_back({a, r});
    }
    while (q--) {
        cin >> a >> b;
        cnt = 0;
        s.push({INT_MAX, {-1, b}});
        while (!s.empty()) {
            p = s.top();
            s.pop();
            if (p.first >= a) {
                cnt++;
                for (auto i : v[p.second.second]) {
                    if (i.first != p.second.first) {
                        s.push({min(i.second, p.first), {p.second.second, i.first}});
                    }
                }
            }
        }
        cout << cnt - 1 << "\n";
    }
    return 0;
}