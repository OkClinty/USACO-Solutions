#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, l = 0, r;
    cin >> n >> x;
    r = n - 1;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    while (l < r) {
        if (v[l].first + v[r].first == x) {
            cout << v[l].second << " " << v[r].second;
            return 0;
        } else if (v[l].first + v[r].first > x) {
            r--;
        } else {
            l++;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}