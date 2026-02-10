#include <bits/stdc++.h>
using namespace std;
 
bool compareSecond(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, c = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    stack<int> st;
    set<int> s;
    set<int>::iterator it;
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
        v[i].first = i;
    }
    sort(v.begin(), v.end(), compareSecond);
    for (int i = 1; i < n; i++) {
        v[i].second += c;
        if (v[i] == v[i - 1]) {
            c++;
            v[i].second++;
        }
    }
    for (int i = 0; i < n; i++) {
        it = s.upper_bound(INT_MAX - v[i].first);
        st.push(INT_MAX - v[i].first);
        if (i == n - 1 || v[i].second != v[i + 1].second) {
            while (!st.empty()) {
                s.insert(st.top());
                st.pop();
            }
        }
        if (it == s.end()) {
            v[i].second = 0;
        } else {
            v[i].second = INT_MAX - *it + 1;
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i].second << " ";
    }
    return 0;
}