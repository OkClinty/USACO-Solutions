#include <bits/stdc++.h>
using namespace std;

void balance(int k, multiset<int> &l, multiset<int> &r) {
    if (l.size() >= r.size()) {
        while (r.size() < k / 2) {
            multiset<int>::iterator it = prev(l.end(), 1);
            r.insert(*it);
            l.erase(it);
        }
    } else {
        while (r.size() > k / 2) {
            multiset<int>::iterator it = r.begin();
            l.insert(*it);
            r.erase(it);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    multiset<int> l, r;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    l.insert(v[0]);
    for (int i = 1; i < k; i++) {
        if (v[i] > *prev(l.end(), 1)) {
            r.insert(v[i]);
        } else {
            l.insert(v[i]);
        }
    }
    balance(k, l, r);
    cout << *prev(l.end(), 1);
    for (int i = 0; i < n - k; i++) {
        if (v[i] > *prev(l.end(), 1)) {
            r.erase(r.find(v[i]));
        } else {
            l.erase(l.find(v[i]));
        }
        if (!l.empty() && v[i + k] > *prev(l.end(), 1)) {
            r.insert(v[i + k]);
        } else {
            l.insert(v[i + k]);
        }
        balance(k, l, r);
        cout << " " << *prev(l.end(), 1);
    }
    return 0;
}