#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("diamond.out");
    ifstream cin ("diamond.in");
    long long n, k, l = 0, m = 0, p;
    cin >> n >> k;
    vector<long long> v(n), u(n);
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        while (v[i] - v[l] > k) {
            u[l] = i - l;
            ms.insert(u[l]);
            l++;
        }
    }
    while (l < n) {
        u[l] = n - l;
        ms.insert(u[l]);
        l++;
    }
    p = 0;
    for (int i = 0; i < n; i++) {
        while (p < min(n - 1, i + u[i])) {
            ms.erase(ms.find(u[p]));
            p++;
        }
        while (p > i + u[i]) {
            ms.insert(u[p]);
            p--;
        }
        m = max(m, u[i]);
        if (!ms.empty()) {
            m = max(m, u[i] + (long long)*ms.rbegin());
        }
    }
    cout << m << endl;
    return 0;
}