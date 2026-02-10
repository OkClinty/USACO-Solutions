#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, num, x, y, c, p;
    cin >> n;
    vector<int> f(n + 1), r(n + 1);
    vector<vector<int>> b(n + 1);
    vector<bool> v(n + 1);
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        f[i] = num;
        b[num].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            x = i;
            y = i;
            do {
                x = f[x];
                y = f[f[y]];
            } while (x != y);
            c = 0;
            do {
                y = f[y];
                c++;
            } while (x != y);
            do {
                y = f[y];
                r[y] = c;
            } while (x != y);
            q.push({x, c});
            while (!q.empty()) {
                num = q.front().first;
                p = q.front().second;
                q.pop();
                if (!v[num]) {
                    v[num] = true;
                    if (r[num] == 0) {
                        r[num] = p + 1;
                    }
                    for (int j : b[num]) {
                        q.push({j, r[num]});
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << r[i] << " ";
    }
    return 0;
}