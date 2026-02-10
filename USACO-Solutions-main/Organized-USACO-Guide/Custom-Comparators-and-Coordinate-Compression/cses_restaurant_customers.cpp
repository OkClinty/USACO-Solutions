#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, c = 0, m = 0;
    cin >> n;
    vector<pair<int, bool>> v(n * 2);
    for (int i = 0; i < n * 2; i += 2) {
        cin >> v[i].first >> v[i + 1].first;
        v[i].second = true;
        v[i + 1].second = false;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n * 2; i++) {
        if (v[i].second) {
            c++;
            m = max(m, c);
        } else {
            c--;
        }
    }
    cout << m << "\n";
    return 0;
}