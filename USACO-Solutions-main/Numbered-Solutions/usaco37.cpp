#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("haybales.out");
    ifstream cin ("haybales.in");
    int n, q, a, b, t;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    while (q--) {
        cin >> a >> b;
        cout << upper_bound(v.begin(), v.end(), b) - upper_bound(v.begin(), v.end(), a) + (upper_bound(v.begin(), v.end(), a) - 1 == lower_bound(v.begin(), v.end(), a)) << "\n";
    }
    return 0;
}