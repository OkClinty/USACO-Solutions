#include <bits/stdc++.h>
using namespace std;

long long distance(const long long x1, const long long y1, const long long x2, const long long y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("moocast.in");
    ofstream cout ("moocast.out");
    int n, num;
    long long l = 0, r = 1250000000, m;
    bool b;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<vector<long long>> d(n, vector<long long>(n));
    vector<bool> v(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = distance(a[i].first, a[i].second, a[j].first, a[j].second);
        }
    }
    while (l < r) {
        m = (l + r) / 2;
        b = true;
        for (int i = 0; i < n; i++) {
            v[i] = false;
        }
        s.push(0);
        v[0] = true;
        while (!s.empty()) {
            num = s.top();
            s.pop();
            for (int i = 0; i < n; i++) {
                if (!v[i] && d[num][i] <= m) {
                    s.push(i);
                    v[i] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                b = false;
                break;
            }
        }
        if (b) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l;
    return 0;
}