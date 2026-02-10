#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("snowboots.in");
    ofstream cout ("snowboots.out");
    int n, b, x, y, num;
    cin >> n >> b;
    vector<int> arr(n), t;
    vector<bool> v(n);
    vector<pair<int, int>> p(b);
    stack<int> s;
    t.push_back(0);
    v[0] = true;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> x >> y;
        p[i] = {x, y};
    }
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < t.size(); j++) {
            s.push(t[j]);
        }
        while (!s.empty()) {
            num = s.top();
            s.pop();
            if (p[i].first >= arr[num]) {
                for (int j = max(0, num - p[i].second); j <= min(n - 1, num + p[i].second); j++) {
                    if (!v[j] && p[i].first >= arr[j]) {
                        v[j] = true;
                        t.push_back(j);
                        s.push(j);
                    }
                }
            }
        }
        if (v[n - 1]) {
            cout << i;
            return 0;
        }
    }
    return 0;
}