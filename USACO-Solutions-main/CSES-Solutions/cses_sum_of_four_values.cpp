#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    map<int, pair<int, int>> m;
    pair<int, int> p;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            m[v[i] + v[j]] = {i + 1, j + 1};
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m.find(x - v[i] - v[j]) != m.end()) {
                p = m[x - v[i] - v[j]];
                if (p.first != i + 1 && p.first != j + 1 && p.second != i + 1 && p.second != j + 1) {
                    cout << i + 1 << " " << j + 1 << " " << p.first << " " << p.second;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}