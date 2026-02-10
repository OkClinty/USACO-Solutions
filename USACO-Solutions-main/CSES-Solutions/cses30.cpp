#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, t = 1, num, a, b;
    cin >> n >> m;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        v[num - 1] = i;
        w[i] = num - 1;
    }
    for (int i = 0; i < n - 1; i++) {
        t += v[i + 1] < v[i];
    }
    while (m--) {
        cin >> a >> b;
        a--;
        b--;
        t -= (w[a] != 0 && v[w[a] - 1] > v[w[a]]) + (w[b] != 0 && v[w[b] - 1] > v[w[b]]) + (w[a] != n - 1 && v[w[a]] > v[w[a] + 1]) + (w[b] != n - 1 && v[w[b]] > v[w[b] + 1]);
        t += (abs(w[a] - w[b]) == 1 && ((w[a] < w[b] && v[w[a]] > v[w[b]]) || (w[a] > w[b] && v[w[a]] < v[w[b]])));
        swap(v[w[a]], v[w[b]]);
        swap(w[a], w[b]);
        t += (w[a] != 0 && v[w[a] - 1] > v[w[a]]) + (w[b] != 0 && v[w[b] - 1] > v[w[b]]) + (w[a] != n - 1 && v[w[a]] > v[w[a] + 1]) + (w[b] != n - 1 && v[w[b]] > v[w[b] + 1]);
        t -= (abs(w[a] - w[b]) == 1 && ((w[a] < w[b] && v[w[a]] > v[w[b]]) || (w[a] > w[b] && v[w[a]] < v[w[b]])));
        cout << t << "\n";
    }
    return 0;
}