#include <bits/stdc++.h>
using namespace std;

struct Node {
    int num, prev, next;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, c = 0;
    cin >> n;
    vector<Node> v(n);
    Node nd;
    for (int i = 0; i < n; i++) {
        v[i].num = i + 1;
        v[i].prev = i - 1;
        v[i].next = i + 1;
    }
    v[0].prev = n - 1;
    v[n - 1].next = 0;
    nd = v[0];
    while (c < n) {
        nd = v[nd.next];
        cout << nd.num << " ";
        v[nd.prev].next = nd.next;
        v[nd.next].prev = nd.prev;
        nd = v[nd.next];
        c++;
    }
    return 0;
}