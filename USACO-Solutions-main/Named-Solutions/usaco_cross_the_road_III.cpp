#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("countcross.in");
    ofstream cout ("countcross.out");
    int n, k, r, a, b, c, d, cnt, t = 0, rs = 0;
    cin >> n >> k >> r;
    set<pair<pair<int, int>, pair<int, int>>> s;
    vector<vector<bool>> v(n, vector<bool>(n)), arr(n, vector<bool>(n));
    stack<pair<int, int>> st;
    pair<int, int> p;
    while (r--) {
        cin >> a >> b >> c >> d;
        s.insert({{a - 1, b - 1}, {c - 1, d - 1}});
        s.insert({{c - 1, d - 1}, {a - 1, b - 1}});
    }
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        arr[a - 1][b - 1] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!v[i][j]) {
                cnt = 0;
                st.push({i, j});
                while (!st.empty()) {
                    p = st.top();
                    st.pop();
                    if (p.first >= 0 && p.first < n && p.second >= 0 && p.second < n && !v[p.first][p.second]) {
                        v[p.first][p.second] = true;
                        cnt += arr[p.first][p.second];
                        if (s.find({{p.first, p.second}, {p.first + 1, p.second}}) == s.end()) {
                            st.push({p.first + 1, p.second});
                        }
                        if (s.find({{p.first, p.second}, {p.first - 1, p.second}}) == s.end()) {
                            st.push({p.first - 1, p.second});
                        }
                        if (s.find({{p.first, p.second}, {p.first, p.second + 1}}) == s.end()) {
                            st.push({p.first, p.second + 1});
                        }
                        if (s.find({{p.first, p.second}, {p.first, p.second - 1}}) == s.end()) {
                            st.push({p.first, p.second - 1});
                        }
                    }
                }
                t += cnt;
                rs += cnt * (k - t);
            }
        }
    }
    cout << rs;
    return 0;
}