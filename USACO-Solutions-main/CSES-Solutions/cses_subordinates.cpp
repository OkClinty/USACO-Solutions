#include <bits/stdc++.h>
using namespace std;

vector<int> r;
vector<vector<int>> adj;

void recur(int num) {
    int cnt = 0;
    for (int i : adj[num]) {
        recur(i);
        cnt += 1 + r[i];
    }
    r[num] = cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, num;
    cin >> n;
    r.resize(n);
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        cin >> num;
        adj[num - 1].push_back(i);
    }
    recur(0);
    for (int i : r) {
        cout << i << " ";
    } 
    return 0;
}