#include <bits/stdc++.h>
using namespace std;

void cop(vector<int> &v, vector<int> &vv) {
	for (int i = 0; i < v.size(); i++) {
		vv[i] = v[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t, c, num, p, pp, sum = 0, cnt, mx = 0;
	string s;
	cin >> t >> c;
	vector<bool> a(2 * c + 5);
	vector<int> v(2 * c + 5), vv(2 * c + 5);
	for (int i = 0; i < t; i++) {
		cin >> num;
		a[num + c + 2] = true;
	}
	cin >> s;
	p = c + 2;
	for (int i = 0; i < c; i++) {
		if (s[i] == 'L') {
			p--;
		} else if (s[i] == 'R') {
			p++;
		} else {
			if (a[p]) {
				v[p]++;
				if (v[p] == 1) {
					sum++;
				}
			}
		}
	}
	mx = sum;
	if (s[c - 1] == 'L') {
		mx += (a[p + 1] && v[p + 1] == 0);
	} else if (s[c - 1] == 'R') {
		mx += (a[p - 1] && v[p - 1] == 0);
	}
	for (int j = -2; j <= 2; j++) {
		if (j != 0) {
			cop(v, vv);
			cnt = sum;
			pp = p + j;
			for (int i = c - 1; i > 0; i--) {
				if (s[i] == 'L') {
					pp++;
				} else if (s[i] == 'R') {
					pp--;
				} else {
					if (a[pp - j]) {
						vv[pp - j]--;
						if (vv[pp - j] == 0) {
							cnt--;
						}
					}
					if (a[pp]) {
						vv[pp]++;
						if (vv[pp] == 1) {
							cnt++;
						}
					}
				}
				if ((j == -1 || j == 1) && s[i - 1] == 'F') {
					mx = max(mx, cnt - (a[pp - j] && vv[pp - j] == 1));
				} else if ((j == -1 && s[i - 1] == 'R') || (j == 1 && s[i - 1] == 'L')) {
					mx = max(mx, cnt + (a[pp] && vv[pp] == 0));
				} else if ((j == -2 && s[i - 1] == 'R') || (j == 2 && s[i - 1] == 'L')) {
					mx = max(mx, cnt);
				}
			}
		}
	}
	cout << mx;
	return 0;
}