#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("angry.out");
    ifstream cin ("angry.in");
    int n, k, min, l = 0, r = 500000000, m, c, z;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    while (l < r) {
        m = (r + l) / 2;
        c = 1;
        z = v[0] + (m * 2);
        for (int i = 0; i < n; i++) {
            if (v[i] > z) {
                c++;
                z = v[i] + (m * 2);
            }
        }
        if (c <= k) {
            r = m;
            min = m;
        } else {
            l = m + 1;
        }
    }
    cout << min;
    return 0;
}