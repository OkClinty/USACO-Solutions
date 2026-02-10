#include <bits/stdc++.h>
using namespace std;

bool compSecond(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;   
    }
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("split.out");
    ifstream cin ("split.in");
    int n;
    long long t = 0, mx = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    multiset<int> s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        s2.insert(v[i].second);
    }
    sort(v.begin(), v.end());
    t = 1ll * (v[n - 1].first - v[0].first) * (*s2.rbegin() - *s2.begin());
    for (int i = 0; i < n - 1; i++) {
        s2.erase(s2.find(v[i].second));
        s1.insert(v[i].second);
        if (v[i].first != v[i + 1].first || *s2.begin() > *s1.rbegin()) {
            mx = max(mx, t - (1ll * (v[i].first - v[0].first) * (*s1.rbegin() - *s1.begin())) - (1ll * (v[n - 1].first - v[i + 1].first) * (*s2.rbegin() - *s2.begin())));
        }
    }
    sort(v.begin(), v.end(), compSecond);
    s1.clear();
    s2.clear();
    for (int i = 0; i < n; i++) {
        s2.insert(v[i].first);
    }
    for (int i = 0; i < n - 1; i++) {
        s2.erase(s2.find(v[i].first));
        s1.insert(v[i].first);
        if (v[i].second != v[i + 1].second || *s2.begin() > *s1.rbegin()) {
            mx = max(mx, t - (1ll * (v[i].second - v[0].second) * (*s1.rbegin() - *s1.begin())) - (1ll * (v[n - 1].second - v[i + 1].second) * (*s2.rbegin() - *s2.begin())));
        }
    }
    cout << mx;
    return 0;
}