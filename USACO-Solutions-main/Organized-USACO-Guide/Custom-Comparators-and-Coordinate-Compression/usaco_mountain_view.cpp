#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("mountains.out");
    ifstream cin ("mountains.in");
    int n, a, b, m = INT_MIN, cnt = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i] = {a - b, a + b};
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; i++) {
        if (v[i].second > m) {
            m = v[i].second;
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}