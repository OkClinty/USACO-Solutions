#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("revegetate.in");
    ofstream cout ("revegetate.out");
    int n, m, a, b, num, cnt = 0;
    char c;
    cin >> n >> m;
    vector<vector<int>> s(n + 1), d(n + 1);
    vector<int> v(n + 1);
    stack<int> st;
    for (int i = 0; i < m; i++) {
        cin >> c >> a >> b;
        if (c == 'S') {
            s[a].push_back(b);
            s[b].push_back(a);
        } else {
            d[a].push_back(b);
            d[b].push_back(a);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            st.push(i);
            v[i] = 1;
            while (!st.empty()) {
                num = st.top();
                st.pop();
                for (int j : s[num]) {
                    if (v[j] != 0 && v[j] != v[num]) {
                        cout << '0';
                        return 0;
                    } else if (v[j] == 0) {
                        if (v[num] == 1) {
                            v[j] = 1;
                        } else {
                            v[j] = 2;
                        }
                        st.push(j);
                    }
                }
                for (int j : d[num]) {
                    if (v[j] != 0 && v[j] == v[num]) {
                        cout << '0';
                        return 0;
                    } else if (v[j] == 0) {
                        if (v[num] == 1) {
                            v[j] = 2;
                        } else {
                            v[j] = 1;
                        }
                        st.push(j);
                    }
                }
            }
            cnt++;
        }
    }
    cout << '1';
    while (cnt--) {
        cout << '0';
    }
    return 0;
}