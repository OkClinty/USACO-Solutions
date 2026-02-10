#include <bits/stdc++.h>
using namespace std;

bool compSecond(const pair<long long, long long> &a, const pair<long long, long long> &b) {
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("rental.out");
    ifstream cin ("rental.in");
    long long n, m, r, cnt = 0, p = 0, pp = 0, ppp, sum = 0, t;
    cin >> n >> m >> r;
    vector<long long> v(n), s(r);
    vector<pair<long long, long long>> c(m), cc;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cnt += v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        cin >> c[i].first >> c[i].second;
    }
    sort(c.begin(), c.end(), compSecond);
    for (int i = 0; i < r; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), greater<long long>());
    while (cnt > 0 && p < m) {
        cc.push_back({min(cnt, c[p].first), c[p].second});
        sum += c[p].second * min(cnt, c[p].first);
        cnt -= min(cnt, c[p].first);
        p++;
    }
    if (cnt > 0) {
        cc.push_back({cnt, 0});
    }
    p = cc.size() - 1;
    for (int i = 0; i < n; i++) {
        cnt = 0;
        ppp = p;
        t = v[i];
        while (t > 0) {;
            cnt += min(t, cc[ppp].first) * cc[ppp].second;
            t -= min(t, cc[ppp].first);
            ppp--;
        }
        if (cnt < s[pp]) {
            sum -= cnt;
            sum += s[pp];
            pp++;
            t = v[i];
            while (t > 0) {
                if (t > cc[p].first) {
                    t -= cc[p].first;
                    p--;
                } else {
                    cc[p].first -= t;
                    break;
                }
            }
	    if (pp > r) {
                break;
            }
        }
    }
    cout << sum << endl;
    return 0;
}