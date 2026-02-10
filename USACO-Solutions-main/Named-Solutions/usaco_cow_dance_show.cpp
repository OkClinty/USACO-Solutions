#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int process(int k) {
    multiset<int> ms;
    for (int i = 0; i < k; i++) {
        ms.insert(v[i]);
    }
    for (int i = k; i < v.size(); i++) {
        ms.insert(*ms.begin() + v[i]);
        ms.erase(ms.begin());
    }
    return *prev(ms.end());
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("cowdance.out");
    ifstream cin ("cowdance.in");
    int n, t, l = 1, r, m;
    cin >> n >> t;
    r = n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while (l < r) {
        m = (l + r) / 2;
        if (process(m) <= t) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l;
    return 0;
}