#include <bits/stdc++.h>
using namespace std;

vector<pair<int, vector<int>>> v, c;

void rsolve(int s) {
    for (int x : c[s].second) {
        if (c[x].first < 12) {
            c[x].first++;
            rsolve(x);
            break;
        }
    }
}

bool solve(int s) {
    for (int x : c[s].second) {
        if (c[x].first != 12) {
            c[x].first++;
            rsolve(x);   
            break;
        }
    }
    for (auto y : c) {
        if (y.first != 12) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("clocktree.out");
    ifstream cin ("clocktree.in");
    int n, x, y, t = 0;
    cin >> n;
    c.resize(n + 1);
    v.resize(n + 1);
    v[0].first = 12;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first;
    }
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        v[x].second.push_back(y);
        v[y].second.push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        c = v;
        t += solve(i);
    }
    cout << t;
    return 0;
}