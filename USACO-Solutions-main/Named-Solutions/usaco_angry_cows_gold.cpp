#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("angry.out");
    ifstream cin ("angry.in");
    int n, l = 1, r = 1e10, m, c, sum;
    bool b, a;
    cin >> n;
    vector<int> u(n), v;
    for (int i = 0; i < n; i++) {
        cin >> u[i];
        u[i] *= 2;
    }
    sort(u.begin(), u.end());
    for (int i = 0; i < n - 1; i++) {
        if (u[i] != u[i + 1]) {
            v.push_back(u[i]);
        }
    }
    v.push_back(u[n - 1]);
    n = v.size();
    while (l < r) {
        m = (l + r) / 2;
        c = 0;
        b = false;
        a = true;
        for (int i = 0; i < n - 1; i++) {
            if (b) {
                if (v[i + 1] - v[i] > c) {
                    a = false;
                    break;
                } else {
                    c -= 2;
                }
            } else {
                c = max(c + 2, v[i + 1] - v[i]);
                if (c < m) {
                    continue;
                } else if (c > m * 2) {
                    a = false;
                    break;
                } else {
                    sum = c;
                    while (sum <= m * 2 && i < n - 1) {
                        i++;
                        sum += v[i + 1] - v[i];
                    }
                    if (sum > m * 2) {
                        i--;
                    }
                    b = true;
                    c = m - 2;
                }
            }
        }
        if (a) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l / 2 << '.' << (l % 2 ? 5 : 0) << '\n';
    return 0;
}