#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long t = 0, s;
    int n, x, y, m;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    vector<bool> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 1; i <= n; i++) {
        if (!b[i]) {
            s = 0;
            x = y = i;
            do {
                x = v[x].first;
                y = v[v[y].first].first;
            } while (x != y);
            x = i;
            while (x != y && !b[x]) {
                b[x] = true;
                s += v[x].second;
                x = v[x].first;
            }
            if (x == y) {
                m = INT_MAX;
                do {
                    if (!b[x]) {
                        s += v[x].second;
                    }
                    b[x] = true;
                    if (v[x].second < m) {
                        m = v[x].second;
                    }
                    x = v[x].first;
                } while (x != y);
                s -= m;
            }
            t += s;   
        }
    }
    cout << t;
    return 0;
}