#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("triangles.out");
    ifstream cin ("triangles.in");
    long long n, a, b, c, num;
    long long t = 0;
    cin >> n;
    vector<pair<int, stack<int>>> x(20003), y(20031);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        a += 10001;
        b += 10001;
        v[i] = {a, b};
        x[b].second.push(a);
        y[a].second.push(b);
    }
    for (int i = 0; i < n; i++) {
        if (x[v[i].second].second.size() > 1) {
            c = 0;
            num = v[i].second;
            while (!x[v[i].second].second.empty()) {
                c += abs(num - x[v[i].second].second.top());
                x[v[i].second].second.pop();
            }
            x[v[i].second].first = c;
        }
        if (y[v[i].first].second.size() > 1) {
            c = 0;
            num = v[i].first;
            while (!y[v[i].first].second.empty()) {
                c += abs(num - y[v[i].first].second.top());
                y[v[i].first].second.pop();
            }
            y[v[i].first].first = c;
        }
    }
    for (int i = 0; i < n; i++) {
        t += (1ll * x[v[i].second].first * y[v[i].first].first) % m;
        t %= m;
    }
    cout << t;
    return 0;
}