#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, q;
	long long mn, a, b, l, r, rem = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; i++) {
		rem += 1ll * (v[i + 1] - v[i]) * (n - 1 - i);
	}
	cin >> q;
	while (q--) {
		cin >> a >> b;
		mn = rem * b;
		l = 0;
		r = rem;
		for (int i = 1; i < n; i++) {
			l += i * (v[i] - v[i - 1]);
			r -= (n - i) * (v[i] - v[i - 1]);
			mn = min(mn, l * a + r * b);
		}
		cout << mn << "\n";
	}
	return 0;
}