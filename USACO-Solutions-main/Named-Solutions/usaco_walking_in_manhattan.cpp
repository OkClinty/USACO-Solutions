#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, q, p, x, y, d, a, b;
	char c;
	bool o;
	cin >> n >> q;
	vector<int> h, v;
	while (n--) {
		cin >> c >> p;
		if (c == 'H') {
			h.push_back(p);
		} else {
			v.push_back(p);
		}
	}
	sort(h.begin(), h.end());
	sort(v.begin(), v.end());
	while (q--) {
		cin >> x >> y >> d;
		auto it = binary_search(v.begin(), v.end(), x);
		if (it) {
			a = distance(h.begin(), lower_bound(h.begin(), h.end(), y));
			b = distance(v.begin(), lower_bound(v.begin(), v.end(), x));
			if (a == h.size() || h[a] - y > d) {
				cout << x << " " << y + d << "\n";
				continue;
			}
			d -= h[a] - y;
			o = ((h[a] - y) % 2 == 1);
			y = h[a];
		} else {
			a = distance(h.begin(), lower_bound(h.begin(), h.end(), y));
			b = distance(v.begin(), lower_bound(v.begin(), v.end(), x));
			if (b == v.size() || v[b] - x > d) {
				cout << x + d << " " << y << "\n";
				continue;
			}
			d -= v[b] - x;
			o = ((v[b] - x) % 2 == 1);
			x = v[b];
		}
		while (d > 0) {
			if (o) {
				if (b + 1 == v.size() || v[b + 1] - v[b] > d) {
					x += d;
					break;
				}
				d -= v[b + 1] - v[b];
				o ^= ((v[b + 1] - v[b]) % 2 == 1);
				x = v[b + 1];
				b++;
			} else {
				if (a + 1 == h.size() || h[a + 1] - h[a] > d) {
					y += d;
					break;
				}
				d -= h[a + 1] - h[a];
				o ^= ((h[a + 1] - h[a]) % 2 == 1);
				y = h[a + 1];
				a++;
			}
		}
		cout << x << " " << y << "\n";
	}
	return 0;
}