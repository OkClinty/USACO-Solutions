#include <bits/stdc++.h>
using namespace std;
 
bool comp(const pair<pair<int, int>, pair<int, pair<int, int>>> &a, const pair<pair<int, int>, pair<int, pair<int, int>>> &b) {
    return a.first.first < b.first.first;
}
 
void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, pair<int, pair<int, int>>>> v(n), h(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].first.first = INT_MAX - v[i].first.first;
        v[i].first.second = INT_MAX - v[i].first.second;
        v[i].second.first = i + 1;
    }
    h = v;
    sort(h.begin(), h.end());
    for (int i = 0; i < n; i++) {
        w[i] = {{v[i].first.second, v[i].first.first}, v[i].second};
    }
    sort(w.begin(), w.end());
    h[n - 1].second.second = {h[n - 1].first.second, h[n - 1].second.first};
    w[n - 1].second.second = {w[n - 1].first.second, w[n - 1].second.first};
    for (int i = n - 2; i >= 0; i--) {
        if (h[i].first.second > h[i + 1].second.second.first) {
            h[i].second.second = {h[i].first.second, h[i].second.first};
        } else {
            h[i].second.second = h[i + 1].second.second;
        }
        if (w[i].first.second > w[i + 1].second.second.first) {
            w[i].second.second = {w[i].first.second, w[i].second.first};
        } else {
            w[i].second.second = w[i + 1].second.second;
        }
    }
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(h.begin(), h.end(), v[i], comp);
        if (it != h.end() && (*it).second.second.first > v[i].first.second) {
            cout << (*it).second.second.second << " ";
            continue;
        }
        it = upper_bound(w.begin(), w.end(), v[i], comp);
        if (it != w.end() && (*it).second.second.first > v[i].first.second) {
            cout << (*it).second.second.second << " ";
            continue;
        }
        cout << "-1 ";
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}