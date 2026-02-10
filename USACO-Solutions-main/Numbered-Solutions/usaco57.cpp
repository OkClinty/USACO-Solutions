#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("reststops.out");
    ifstream cin ("reststops.in");
    int k, n, f, b, m = 0;
    long long c = 0;
    cin >> k >> n >> f >> b;
    vector<pair<int, int>> v(n);
    multiset<long long> ms;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        ms.insert(1ll * v[i].first * v[i].second);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (1ll * v[i].first * v[i].second == *prev(ms.end(), 1)) {
            c += 1ll * (v[i].first - m) * v[i].second;
            m = v[i].first;
        }
        ms.erase(ms.find(1ll * v[i].first * v[i].second));
    }
    cout << c;
    return 0;
}