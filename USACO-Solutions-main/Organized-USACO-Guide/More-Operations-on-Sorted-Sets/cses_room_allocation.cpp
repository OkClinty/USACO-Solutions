#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, num;
    cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    vector<int> arr(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (pq.empty() || v[i].first.first <= pq.top().first) {
            pq.push({v[i].first.second, v[i].second});
            arr[v[i].second] = pq.size();
        } else {
            num = arr[pq.top().second];
            pq.pop();
            pq.push({v[i].first.second, v[i].second});
            arr[v[i].second] = num;
        }
    }
    cout << pq.size() << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}