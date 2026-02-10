#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    long long r = 0;
    cin >> n;
    n /= 2;
    vector<pair<int, int>> v(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> v[0].first >> v[0].second;
    pq.push(max(v[0].first, v[0].second));
    for (int i = 1; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        pq.push(max(v[i].first, v[i].second));
        if (min(v[i].first, v[i].second) > pq.top()) {
            pq.pop();
            pq.push(min(v[i].first, v[i].second));
        }
    }
    while (!pq.empty()) {
        r += pq.top();
        pq.pop();
    }
    cout << r;
    return 0;
}