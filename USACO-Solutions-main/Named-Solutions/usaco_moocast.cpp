#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("moocast.out");
    ifstream cin ("moocast.in");
    int n, m = 0, cnt, num;
    cin >> n;
    vector<pair<pair<int, int>, int>> c(n);
    stack<int> s;
    vector<bool> v(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first.first >> c[i].first.second >> c[i].second;
        c[i].second *= c[i].second;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[j] = false;
        }
        cnt = 1;
        v[i] = true;
        s.push(i);
        while (!s.empty()) {
            num = s.top();
            s.pop();
            for (int j = 0; j < n; j++) {
                if (!v[j] && pow(abs(c[num].first.first - c[j].first.first), 2) + pow(abs(c[num].first.second - c[j].first.second), 2) <= c[num].second) {
                    v[j] = true;
                    cnt++;
                    s.push(j);
                }
            }
        }
        m = max(m, cnt);
    }
    cout << m;
    return 0;
}