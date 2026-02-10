#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, k, mx = 0, c, p1, p2;
	cin >> n >> k;
	vector<int> a(k), b(k), o1(k), o2(k);
	vector<bool> v(n + 1);
	set<int> s;
	map<int, int> m;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		m[a[i]] = i;
		s.insert(a[i]);
	}
	for (int i = 0; i < k; i++) {
		cin >> b[i];
		s.insert(b[i]);
	}
	for (int i = 0; i < k; i++) {
		if (!v[b[i]] && m.find(b[i]) != m.end()) {
			c = -1;
			p1 = i;
			p2 = m[b[i]];
			while (!v[b[p1]] && b[p1] == a[p2]) {
				v[b[p1]] = true;
				c++;
				p1 = (p1 - 1 + k) % k;
				p2 = (p2 - 1 + k) % k;
			}
			v[b[i]] = false;
			p1 = i;
			p2 = m[b[i]];
			while (!v[b[p1]] && b[p1] == a[p2]) {
				v[b[p1]] = true;
				c++;
				p1 = (p1 + 1 + k) % k;
				p2 = (p2 + 1 + k) % k;
			}
			o1[(m[b[i]] - i + k) % k] += c;
		}
	}
	for (int i = 0; i <= n; i++) {
		v[i] = false;
	}
	reverse(b.begin(), b.end());
	for (int i = 0; i < k; i++) {
		if (!v[b[i]] && m.find(b[i]) != m.end()) {
			c = -1;
			p1 = i;
			p2 = m[b[i]];
			while (!v[b[p1]] && b[p1] == a[p2]) {
				v[b[p1]] = true;
				c++;
				p1 = (p1 - 1 + k) % k;
				p2 = (p2 - 1 + k) % k;
			}
			v[b[i]] = false;
			p1 = i;
			p2 = m[b[i]];
			while (!v[b[p1]] && b[p1] == a[p2]) {
				v[b[p1]] = true;
				c++;
				p1 = (p1 + 1 + k) % k;
				p2 = (p2 + 1 + k) % k;
			}
			o2[(m[b[i]] - i + k) % k] += c;
		}
	}
	for (int i = 0; i < k; i++) {
		mx = max(mx, max(o1[i], o2[i]));
	}
	cout << mx + (n - s.size());
	return 0;
}