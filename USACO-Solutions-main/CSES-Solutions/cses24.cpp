#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, c = 0, t = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (t <= v[i].second) {
            c++;
            t = v[i].first;
        }
    }
    cout << c << "\n";
    return 0;
}