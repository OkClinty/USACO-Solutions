#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("measurement.out");
    ifstream cin ("measurement.in");
    int n, g, c = 0;
    cin >> n >> g;
    map<int, int> m1;
    map<int, int> m2;
    vector<pair<pair<int, int>, int>> v(n);
    m2[0] = n + 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        int &ref = m1[v[i].first.second];
        bool b1 = (ref == (*m2.rbegin()).first);
        int cnt1 = m2[ref]--;
        if (cnt1 == 1) {
            m2.erase(ref);
        }
        ref += v[i].second;
        int cnt2 = ++m2[ref];
        bool b2 = (ref == (*m2.rbegin()).first);
        if (b1) {
            c += (!b2 || cnt1 != 1 || cnt2 != 1);
        } else if (b2) {
            c++;
        }
    }
    cout << c << "\n";
    return 0;
}