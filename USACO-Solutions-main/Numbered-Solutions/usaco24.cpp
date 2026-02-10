#include <bits/stdc++.h>
using namespace std;

vector<int> v(100000);
int n;
string s = "";

void solve(int i, bool b) {
    if (i == n || v[i] == 0) {
        return;
    }
    if (v[i] == 2) {
        s.push_back('R');
        solve(i + 1, true);
        s.push_back('L');
        v[i] -= 2;
    } else if (b) {
        while (v[i] > 2) {
            s.push_back('R');
            solve(i + 1, false);
            s.push_back('L');
            v[i] -= 2;
        }
        if (v[i] == 2) {
            s.push_back('R');
            solve(i + 1, true);
            s.push_back('L');
            v[i] -= 2;
        }
    } else {
        s.push_back('R');
        solve(i + 1, false);
        s.push_back('L');
        v[i] -= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    solve(0, true);
    cout << s;
    return 0;
}