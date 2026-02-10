#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("helpcross.out");
    ifstream cin ("helpcross.in");
    int c, n, num, r = 0;
    cin >> c >> n;
    multiset<int> ms;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < c; i++) {
        cin >> num;
        ms.insert(num);
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        auto it = ms.lower_bound(v[i].second);
        if (it != ms.end() && *it <= v[i].first) {
            r++;
            ms.erase(it);
        }
    }
    cout << r;
    return 0;
}