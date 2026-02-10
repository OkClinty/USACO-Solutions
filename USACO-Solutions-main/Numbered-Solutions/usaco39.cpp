#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("hps.out");
    ifstream cin ("hps.in");
    int n, m = 0;
    char c;
    cin >> n;
    vector<int> h(n + 1), p(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c;
        switch (c) {
            case 'H':
                h[i]++;
                break;
            case 'P':
                p[i]++;
                break;
            case 'S':
                s[i]++;
                break;
        }
        h[i] += h[i - 1];
        p[i] += p[i - 1];
        s[i] += s[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        m = max(m, max(h[i], max(p[i], s[i])) + max(h[n] - h[i], max(p[n] - p[i], s[n] - s[i])));
    }
    cout << m;
    return 0;
}