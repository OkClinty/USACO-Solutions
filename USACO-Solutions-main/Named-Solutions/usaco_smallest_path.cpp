#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

void solve() {
    int n, m, x, y, pre;
    char c;
    cin >> n >> m;
    vector<set<pair<char, int>>> v(n + 1);
    priority_queue<pair<pair<int, char>, pair<int, int>>> pq;
    pair<pair<int, char>, pair<int, int>> p;
    vector<int> r(n + 1, -1);
    map<char, int> best;
    while (m--) {
        cin >> x >> y >> c;
        v[x].insert({c, y});
        v[y].insert({c, x});
    }
    pq.push({{0, '{'}, {1, 0}});
    while (!pq.empty()) {
        p = pq.top();
        pq.pop();
        if (best.find(p.f.s) != best.end()) {
            pre = best[p.f.s];
        } else {
            pre = -1;
        }
        best[p.f.s] = -1;
        if (r[p.s.f] == -1 && ((best.begin()->first == p.f.s) || (prev(best.find(p.f.s))->second > p.s.s))) {
            if (pre != -1) {
                best[p.f.s] = min(pre, p.s.s);
            } else {
                best[p.f.s] = p.s.s;
            }
            r[p.s.f] = p.s.s;
            for (auto pp : v[p.s.f]) {
                if (pp.f == (*v[p.s.f].begin()).f) {
                    pq.push({{-((int)(pp.f - 'a') + (p.s.s + 1) * 27), pp.f}, {pp.s, p.s.s + 1}});
                } else {
                    break;
                }
            }
        } else {
            if (pre == -1) {
                best.erase(p.f.s);
            } else {
                best[p.f.s] = pre;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        cout << r[i] << " ";
    }
    cout << r[n] << endl;
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}