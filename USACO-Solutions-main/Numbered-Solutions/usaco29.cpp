#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("hps.out");
    ifstream cin ("hps.in");
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i].first = a;
        v[i].second = b;
    }
    a = b = 0;
    for (int i = 0; i < n; i++) {
        if ((v[i].first == 1 && v[i].second == 2) || (v[i].first == 2 && v[i].second == 3) || (v[i].first == 3 && v[i].second == 1)) {
            a++;
        } else if ((v[i].first == 1 && v[i].second == 3) || (v[i].first == 3 && v[i].second == 2) || (v[i].first == 2 && v[i].second == 1)) {
            b++;
        }
    }
    cout << max(a, b);
    return 0;
}