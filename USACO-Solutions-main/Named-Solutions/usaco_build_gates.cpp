#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("gates.in");
    ofstream cout ("gates.out");
    int n, x = 1000, y = 1000, c = 0;
    string s;
    cin >> n >> s;
    vector<vector<bool>> v(2001, vector<bool>(2001));
    set<pair<pair<int, int>, pair<int, int>>> e;
    stack<pair<int, int>> st;
    pair<int, int> p;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') {
            e.insert({{x, y}, {x, y + 1}});
            y++;
        } else if (s[i] == 'E') {
            e.insert({{x, y}, {x + 1, y}});
            x++;
        } else if (s[i] == 'S') {
            e.insert({{x, y - 1}, {x, y}});
            y--;
        } else if (s[i] == 'W') {
            e.insert({{x - 1, y}, {x, y}});
            x--;
        }
    }
    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) {
            if (!v[i][j]) {
                c++;
                st.push({i, j});
                while (!st.empty()) {
                    p = st.top();
                    st.pop();
                    if (p.first >= 0 && p.second >= 0 && p.first <= 2000 && p.second <= 2000 && !v[p.first][p.second]) {
                        v[p.first][p.second] = true;
                        if (e.find({{p.first, p.second + 1}, {p.first + 1, p.second + 1}}) == e.end()) {
                            st.push({p.first, p.second + 1});
                        } 
                        if (e.find({{p.first, p.second}, {p.first + 1, p.second}}) == e.end()) {
                            st.push({p.first, p.second - 1});
                        } 
                        if (e.find({{p.first + 1, p.second}, {p.first + 1, p.second + 1}}) == e.end()) {
                            st.push({p.first + 1, p.second});
                        } 
                        if (e.find({{p.first, p.second}, {p.first, p.second + 1}}) == e.end()) {
                            st.push({p.first - 1, p.second});
                        }
                    }
                }
            }
        }
    }
    cout << c - 1;
    return 0;
}