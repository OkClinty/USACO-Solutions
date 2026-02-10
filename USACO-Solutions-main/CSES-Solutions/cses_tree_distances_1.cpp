#include <bits/stdc++.h>
using namespace std;

struct Node {
    int p = -1, d1 = 0, d2 = 0, v1 = -1, v2 = -1;
    vector<int> c;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, y, num;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<Node> v(n);
    vector<int> r(n);
    stack<int> s;
    queue<int> q;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    s.push(0);
    while (!s.empty()) {
        num = s.top();
        s.pop();
        for (int i : adj[num]) {
            if (v[i].c.size() == 0) {
                v[i].p = num;
                v[num].c.push_back(i);
                s.push(i);
            }
        }
        if (v[num].c.size() == 0) {
            q.push(num);
        }
    }
    while (!q.empty()) {
        num = q.front();
        q.pop();
        if (v[num].p != -1) {
            q.push(v[num].p);   
        }
        for (int i : v[num].c) {
            if (v[i].d1 + 1 > v[num].d1) {
                v[num].v2 = v[num].v1;
                v[num].v1 = i;
                v[num].d2 = v[num].d1;
                v[num].d1 = v[i].d1 + 1;
            } else if (v[i].d1 + 1 > v[num].d2) {
                v[num].v2 = i;
                v[num].d2 = v[i].d1 + 1;
            }
        }
    }
    q.push(0);
    while (!q.empty()) {
        num = q.front();
        q.pop();
        if (v[num].p != -1) {
            if (v[v[num].p].v1 != num) {
                if (v[num].d1 < v[v[num].p].d1 + 1) {
                    v[num].v1 = -2;
                    v[num].d1 = v[v[num].p].d1 + 1;
                } else if (v[num].d2 < v[v[num].p].d1 + 1) {
                    v[num].v2 = -2;
                    v[num].d2 = v[v[num].p].d1 + 1;
                }
            } else if (v[v[num].p].v2 != num) {
                if (v[num].d1 < v[v[num].p].d2 + 1) {
                    v[num].v1 = -2;
                    v[num].d1 = v[v[num].p].d2 + 1;
                } else if (v[num].d2 < v[v[num].p].d2 + 1) {
                    v[num].v2 = -2;
                    v[num].d2 = v[v[num].p].d2 + 1;
                }
            }
        }
        for (int i : v[num].c) {
            q.push(i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i].d1 << " ";
    }
    return 0;
}