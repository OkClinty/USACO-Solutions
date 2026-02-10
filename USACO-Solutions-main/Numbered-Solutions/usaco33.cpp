#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("measurement.out");
    ifstream cin ("measurement.in");
    int n, b = 7, e = 7, m = 7, x, y, t = 0;
    bool pb = true, pe = true, pm = true;
    string s;
    cin >> n;
    vector<tuple<int, string, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> s >> y;
        v[i] = {x, s, y};
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (get<1>(v[i]) == "Bessie") {
            b += get<2>(v[i]);
        } else if (get<1>(v[i]) == "Elsie") {
            e += get<2>(v[i]);
        } else {
            m += get<2>(v[i]);
        }
        t += ((pb != (b >= e && b >= m)) || (pe != (e >= b && e >= m)) || (pm != (m >= e && m >= b)));
        pb = (b >= e && b >= m);
        pe = (e >= b && e >= m);
        pm = (m >= e && m >= b);
    }
    cout << t;
    return 0;
}