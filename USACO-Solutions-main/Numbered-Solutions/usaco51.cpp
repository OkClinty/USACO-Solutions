#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("triangles.out");
    ifstream cin ("triangles.in");    
    int n, m = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i != j && j != k && i != k && v[i].first == v[j].first && v[j].second == v[k].second) {
                    m = max(m, abs(v[i].second - v[j].second) * abs(v[j].first - v[k].first));
                }
            }
        }
    }
    cout << m << "\n";
    return 0;
}