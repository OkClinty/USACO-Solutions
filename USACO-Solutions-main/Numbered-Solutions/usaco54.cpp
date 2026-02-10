#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("pails.out");
    ifstream cin ("pails.in");
    int x, y, m, mx = 0, c = 0;
    cin >> x >> y >> m;
    while (c <= m) {
        mx = max(mx, m - ((m - c) % x));
        c += y;
    }
    cout << mx << "\n";
    return 0;
}