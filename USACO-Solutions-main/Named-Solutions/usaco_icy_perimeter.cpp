#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("perimeter.in");
    ofstream cout ("perimeter.out");
    int n, a, p, ba = 0, bp = 0;
    string s;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    vector<vector<bool>> v(n, vector<bool>(n));
    stack<pair<int, int>> st;
    pair<int, int> pr;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!v[i][j] && arr[i][j] == '#') {
                st.push({i, j});
                a = 0;
                p = 0;
                while (!st.empty()) {
                    pr = st.top();
                    st.pop();
                    if (pr.first < 0 || pr.second < 0 || pr.first >= n || pr.second >= n || arr[pr.first][pr.second] == '.') {
                        p++;
                    } else if (!v[pr.first][pr.second]) {
                        v[pr.first][pr.second] = true;
                        a++;
                        st.push({pr.first + 1, pr.second});
                        st.push({pr.first - 1, pr.second});
                        st.push({pr.first, pr.second + 1});
                        st.push({pr.first, pr.second - 1});
                    }
                }
                if (a > ba || (a == ba && p < bp)) {
                    ba = a;
                    bp = p;
                }
            }
        }
    }
    cout << ba << " " << bp;
    return 0;
}