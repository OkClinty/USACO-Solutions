#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k, c = 0;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; i++) {
        if (!s.empty() && s.upper_bound(v[i].first) != s.begin()) {
            s.erase(prev(s.upper_bound(v[i].first)));
            s.insert(v[i].second);
            c++;
        } else if (s.size() < k) {
            s.insert(v[i].second);
            c++;
        }
    }
    cout << c;
    return 0;
}