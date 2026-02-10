#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	long long c = 0, cc, s = 0, p, cnt = 1, cnty;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		s += i;
	}
	while (c < min(s, v[n - 1])) {
		c += cnt;
		p = n - 1;
		cnty = 1;
		cc = c;
		if (cc > v[n - 2] && cc <= v[n - 1]) {
			while (p > 0 && cc > 0) {
				if ((cc == v[p - 1] && v[p] == v[p - 1]) || (cc > v[p - 1] && cc <= v[p])) {
					cc -= cnty;
					cnty++;
				} else {
					p--;
				}
			}
			if (cc == 0) {
				cout << c << "\n";
				return;
			}
		}
		cnt++;
	}
	cout << min(s, v[n - 1]) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}