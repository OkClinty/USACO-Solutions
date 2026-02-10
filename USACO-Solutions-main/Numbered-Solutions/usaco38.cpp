#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("homework.out");
    ifstream cin ("homework.in");
    int n, l;
    double m = 0, t;
    cin >> n;
    vector<int> v(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    t = v[n - 1];
    l = v[n - 1];
    for (int i = n - 2; i > 0; i--) {
        t += v[i];
        if (v[i] < l) {
            l = v[i];
        }
        if ((t - l) / (n - i - 1) > m) {
            m = (t - l) / (n - i - 1);
        }
    }
    t = v[n - 1];
    l = v[n - 1];
    for (int i = n - 2; i > 0; i--) {
        t += v[i];
        if (v[i] < l) {
            l = v[i];
        }
        if ((t - l) / (n - i - 1) == m) {
            s.push(i);
        }
    }
    while (!s.empty()) {
        cout << s.top() << "\n";
        s.pop();
    }
    return 0;
}