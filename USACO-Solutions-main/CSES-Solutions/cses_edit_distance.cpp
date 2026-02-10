#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> v(s1.length() + 1, vector<int>(s2.length() + 1));
    for (int i = 0; i <= s1.length(); i++) {
        v[i][0] = i;
    }
    for (int i = 0; i <= s2.length(); i++) {
        v[0][i] = i;
    }
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            v[i][j] = min(min(v[i - 1][j] + 1, v[i][j - 1] + 1), v[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
        }
    }
    cout << v[s1.length()][s2.length()];
    return 0;
}