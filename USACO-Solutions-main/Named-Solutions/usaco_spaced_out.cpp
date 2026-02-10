#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, a = 0, b = 0, x, y;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		x = 0;
		y = 0;
		for (int j = 0; j < n; j += 2) {
			x += v[i][j];
			if (j + 1 != n) {
				y += v[i][j + 1];
			}
		}
		a += max(x, y);
	}
	for (int j = 0; j < n; j++) {
		x = 0;
		y = 0;
		for (int i = 0; i < n; i += 2) {
			x += v[i][j];
			if (i + 1 != n) {
				y += v[i + 1][j];
			}
		}
		b += max(x, y);
	}
	cout << max(a, b);
	return 0;
}