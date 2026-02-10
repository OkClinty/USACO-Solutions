#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("notlast.out");
    ifstream cin ("notlast.in");
    int n, x;
    string s;
    bool b;
    cin >> n;
    vector<pair<int, string>> v;
    for (int i = 0; i < n; i++) {
        cin >> s >> x;
        b = false;
        for (int j = 0; j < v.size(); j++) {
            if (v[j].second == s) {
                v[j].first += x;
                b = true;
                break;
            }
        }
        if (!b) {
            v.push_back({x, s});   
        }
    }
    sort(v.begin(), v.end());
    if (v.size() != 7) {
        if (n == 1 || v[0].first != v[1].first) {
            cout << v[0].second << "\n";
        } else {
            cout << "Tie\n";   
        }
    } else {
        for (int i = 1; i < n; i++) {
            if (v[i].first != v[i - 1].first) {
                if (i != n - 1 && v[i].first == v[i + 1].first) {
                    break;
                }
                cout << v[i].second << "\n";
                return 0;
            }
        }
        cout << "Tie\n";
    }
    return 0;
}