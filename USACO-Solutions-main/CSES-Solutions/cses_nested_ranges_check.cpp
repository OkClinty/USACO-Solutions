#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    vector<int> r(n);
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].first.second = INT_MAX - v[i].first.second;
        v[i].second = i;
        ms.insert(v[i].first.second);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (i != 0 && v[i].first.first == v[i - 1].first.first && v[i].first.second == v[i - 1].first.second) {
            r[v[i].second] = 1;
        } else {
            if (ms.lower_bound(v[i].first.second) == prev(ms.end(), 1)) {
                r[v[i].second] = 0;
            } else {
                r[v[i].second] = 1;
            }
        }
        ms.erase(ms.find(v[i].first.second));
    }
    for (int i = 0; i < n; i++) {
        cout << r[i] << " ";
        v[i].first.second = INT_MAX - v[i].first.second;
        ms.insert(v[i].first.second);
    }
    cout << "\n";
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1 && v[i].first.first == v[i + 1].first.first && v[i].first.second == v[i + 1].first.second) {
            r[v[i].second] = 1;
        } else {
            if (v[i].first.second == *prev(ms.end(), 1) && ms.count(v[i].first.second) == 1) {
                r[v[i].second] = 0;
            } else {
                r[v[i].second] = 1;
            }
        }
        ms.erase(ms.find(v[i].first.second));
    }
    for (int i = 0; i < n; i++) {
        cout << r[i] << " ";
    }
    cout << "\n";
    return 0;
}