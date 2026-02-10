#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s, str = "";
    int l = 0, r;
    bool b = false;
    vector<int> v(26);
    cin >> s;
    r = s.length() - 1;
    for (char c : s) {
        v[c - 'A']++;
    }
    for (int i = 0; i < s.length(); i++) {
        str.push_back('.');
    }
    for (int i = 0; i < 26; i++) {
        if ((b || s.length() % 2 == 0) && v[i] % 2 == 1) {
            cout << "NO SOLUTION";
            return 0;
        } else if (v[i] % 2 == 1) {
            v[i]--;
            b = true;
            str[str.length() / 2] = (char) ('A' + i);
        }
        while (v[i] > 0) {
            str[l] = (char) ('A' + i);
            str[r] = (char) ('A' + i);
            l++;
            r--;
            v[i] -= 2;
        }
    }
    cout << str;
    return 0;
}