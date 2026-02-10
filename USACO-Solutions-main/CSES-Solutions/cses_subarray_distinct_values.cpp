#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k, p = 0;
    long long r = 0;
    cin >> n >> k;
    set<int> s;
    map<int, int> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        s.insert(v[i]);
        m[v[i]]++;
        while (s.size() > k) {
            if (m[v[p]] == 1) {
                s.erase(s.find(v[p]));
            }
            m[v[p]]--;
            p++;
        }
        r += i - p + 1;
    }
    cout << r;
    return 0;
}