#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("cardgame.out");
    ifstream cin ("cardgame.in");
    int n, c = 0;
    cin >> n;
    vector<int> v(n);
    set<int, greater<int>> a;
    set<int> b;
    vector<bool> arr(n * 2 + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        arr[v[i]] = true;
    }
    for (int i = 1; i <= n * 2; i++) {
        if (!arr[i]) {
            if (a.size() < n / 2) {
                a.insert(i);
            } else {
                b.insert(i);
            }
        }
    }
    for (int i = 0; i < n / 2; i++) {
        auto it = b.upper_bound(v[i]);
        if (it != b.end()) {
            c++;
            b.erase(it);
        }
    }
    for (int i = n / 2; i < n; i++) {
        auto it = a.upper_bound(v[i]);
        if (it != a.end()) {
            c++;
            a.erase(it);
        }
    }
    cout << c;
    return 0;
}