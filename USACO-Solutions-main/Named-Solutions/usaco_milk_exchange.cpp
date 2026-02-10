#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, p, c, cnt, mx = 2;
	cin >> n;
	vector<int> v(n);
	vector<long long> r(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] > mx) {
			mx = v[i];
		}
	}
	if (mx == 2) {
		long long s = 0;
		int pnt = -1, cur = 0;
		vector<int> d(n);
		for (int i = 0; i < n; i++) {
			s += v[i];
			if (pnt == -1 && v[i] == 1) {
				pnt = n + i;
			}
		}
		for (int i = 0; i < n; i++) {
			r[i] = s;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (v[i] == 1) {
				pnt = i;
			} else {
				d[pnt - i - 1]++;
			}
		}
		for (int i = 0; i < n; i++) {
			cur += d[i];
			r[i] -= cur;
		}
	} else {
		for (int i = 0; i < n; i++) {
			p = i;
			c = v[p];
			cnt = 0;
			do {
				p++;
				if (p == n) {
					p = 0;
				}
				c = min(c, v[p]);
				r[cnt] += c;
				cnt++;
			} while (p != i);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << r[i] << "\n";
	}
	return 0;
}