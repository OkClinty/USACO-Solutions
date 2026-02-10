#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    int c = 1;
    vector<string> v;
    cin >> s;
    sort(s.begin(), s.end());
    v.push_back(s);
    while (next_permutation(s.begin(), s.end())) {
        v.push_back(s);
        c++;
    }
    cout << c << "\n";
    for (string str : v) {
        cout << str << "\n";
    }
    return 0;
}