#include <bits/stdc++.h>
using namespace std;

bool compSecond(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("pairup.out");
    ifstream cin ("pairup.in");
    int n, l = 0, r, m = 0;
    cin >> n;
    r = n - 1;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), compSecond);
    while (l <= r) {
        if (l == r) {
            m = max(m, v[l].second * 2);
            break;
        } else if (v[l].first == v[r].first) {
            m = max(m, v[l].second + v[r].second);
            l++;
            r--;
        } else if (v[l].first > v[r].first) {
            v[l].first -= v[r].first;
            m = max(m, v[l].second + v[r].second);
            r--;
        } else {
            v[r].first -= v[l].first;
            m = max(m, v[l].second + v[r].second);
            l++;
        }
    }
    cout << m << "\n";
    return 0;
}