#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, l, r;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        l = 0;
        r = n - 1;
        while (l < r) {
            if (l == i) {
                l++;
                continue;
            } else if (r == i) {
                r--;
                continue;
            }
            if (v[l].first + v[r].first + v[i].first == x) {
                cout << v[l].second << " " << v[r].second << " " << v[i].second;
                return 0;
            } else if (v[l].first + v[r].first + v[i].first < x) {
                l++;
            } else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}