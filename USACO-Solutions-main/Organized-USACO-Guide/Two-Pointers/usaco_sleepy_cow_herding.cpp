#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("herding.out");
    ifstream cin ("herding.in");
    int n, r = 0, mn = INT_MAX;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int l = 0; l < n; l++) {
        while (r < n - 1 && v[r + 1] - v[l] <= n - 1) {
            r++;
        }
        mn = min(mn, n - (r - l + 1));
    }
    if ((v[n - 1] - v[1] == n - 2 && v[1] - v[0] > 2) || (v[n - 2] - v[0] == n - 2 && v[n - 1] - v[n - 2] > 2)) {
        cout << "2\n";
    } else {
        cout << mn << "\n";
    }
    cout << max(v[n - 2] - v[0], v[n - 1] - v[1]) - n + 2 << "\n";
    return 0;
}