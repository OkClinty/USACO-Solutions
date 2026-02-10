#include <bits/stdc++.h>
using namespace std;

vector<int> v(100000);
int n;

string solve(int i, bool b) {
    if (i == n || v[i] == 0) {
        return "";
    }
    string s = "";
    if (v[i] == 2) {
        s += 'R' + solve(i + 1, true) + 'L';
        v[i] -= 2;
    } else if (b) {
        while (v[i] > 2) {
            s += 'R' + solve(i + 1, false) + 'L';
            v[i] -= 2;
        }
        if (v[i] == 2) {
            s += 'R' + solve(i + 1, true) + 'L';
            v[i] -= 2;
        }
    } else {
        s += 'R' + solve(i + 1, false) + 'L';
        v[i] -= 2;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << solve(0, true);
    return 0;
}