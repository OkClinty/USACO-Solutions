#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("milkvisits.in");
    ofstream cout ("milkvisits.out");
    int n, m, x, y, cnt = 1;
    string s;
    char c;
    cin >> n >> m >> s;
    vector<vector<int>> v(n);
    vector<int> r(n);
    stack<pair<int, int>> st;
    pair<int, int> p;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }
    for (int i = 0; i < n; i++) {
        if (!r[i]) {
            st.push({-1, i});
            while (!st.empty()) {
                p = st.top();
                st.pop();
                if (s[i] == s[p.second]) {
                    r[p.second] = cnt + (s[p.second] == 'G');
                    for (int j : v[p.second]) {
                        if (j != p.first) {
                            st.push({p.second, j});
                        }
                    }
                }
            }
            cnt += 2;
        }
    }
    while (m--) {
        cin >> x >> y >> c;
        cout << !(r[x - 1] == r[y - 1] && (c == 'G') == (r[x - 1] % 2));
    }
    return 0;
}