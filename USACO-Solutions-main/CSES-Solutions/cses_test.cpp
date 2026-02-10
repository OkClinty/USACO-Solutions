#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll total;
    ll prefix;
    ll suffix;
    ll best;
};

vector<Node> tree;
vector<ll> b;

void build(int idx, int l, int r, vector<ll>& base) {
    if (l == r) {
        tree[idx].total = base[l];
        tree[idx].prefix = max(0LL, base[l]);
        tree[idx].suffix = max(0LL, base[l]);
        tree[idx].best = max(0LL, base[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid, base);
    build(2 * idx + 1, mid + 1, r, base);
    Node left = tree[2 * idx];
    Node right = tree[2 * idx + 1];
    tree[idx].total = left.total + right.total;
    tree[idx].prefix = max(left.prefix, left.total + right.prefix);
    tree[idx].suffix = max(right.suffix, right.total + left.suffix);
    tree[idx].best = max({left.best, right.best, left.suffix + right.prefix});
}

void update(int idx, int l, int r, int pos, ll val) {
    if (l == r) {
        tree[idx].total = val;
        tree[idx].prefix = max(0LL, val);
        tree[idx].suffix = max(0LL, val);
        tree[idx].best = max(0LL, val);
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(2 * idx, l, mid, pos, val);
    } else {
        update(2 * idx + 1, mid + 1, r, pos, val);
    }
    Node left = tree[2 * idx];
    Node right = tree[2 * idx + 1];
    tree[idx].total = left.total + right.total;
    tree[idx].prefix = max(left.prefix, left.total + right.prefix);
    tree[idx].suffix = max(right.suffix, right.total + left.suffix);
    tree[idx].best = max({left.best, right.best, left.suffix + right.prefix});
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n;
    b.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    /*cin >> m;
    vector<pair<int, ll>> mods(m);
    for (int i = 0; i < m; i++) {
        cin >> mods[i].first >> mods[i].second;
        mods[i].second *= -1;
    }*/
    tree.resize(2 * (n + 1));
    build(1, 1, n, b);
    ll best = tree[1].best;
    /*for (int i = m - 1; i >= 0; i--) {
        int idx = mods[i].first;
        ll x = mods[i].second;
        ll new_val = b[idx] + x;
        update(1, 1, n, idx, new_val);
        if (tree[1].best > best) {
            best = tree[1].best;
        }
    }*/
    cout << best << endl;
    return 0;
}