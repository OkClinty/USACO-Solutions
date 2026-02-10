#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int a, t, s;
    bool operator<(const Cow &c) const { return s > c.s; }
};

bool comp(const Cow &x, const Cow &y) {
    return x.a < y.a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("convention2.out");
    ifstream cin ("convention2.in");
    int n, mx = 0, t = 0, p = 0;
    cin >> n;
    vector<Cow> v(n);
    priority_queue<Cow> pq;
    Cow c;
    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].t;
        v[i].s = i;
    }
    sort(v.begin(), v.end(), comp);
    while (p < n || !pq.empty()) {
        while (t >= v[p].a && p < n) {
            pq.push(v[p]);
            p++;
        }
        if (pq.empty()) {
            t = v[p].a;
        } else {
            c = pq.top();
            pq.pop();
            mx = max(mx, t - c.a);
            t += c.t;
        }
    }
    cout << mx;
    return 0;
}