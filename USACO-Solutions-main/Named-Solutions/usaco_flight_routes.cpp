#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, r = 0;
	string s;
	cin >> n;
	vector<vector<bool>> v(n - 1), c(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			v[i].push_back((s[j] == '1'));
			c[i].push_back(false);
		}
	}
	for (int j = 0; j < n - 1; j++) {
		for (int i = 0; i < n - j - 1; i++) {
			if (v[i][j] != c[i][j]) {
				r++;
				c[i][j] = v[i][j];
				for (int k = 0; k < n - j - 2 - i; k++) {
				    if (c[i + j + 1][k]) {
						for (int l = 0; l < i; l++) {
							if (c[l][i - l - 1]) {
								c[l][j + k + 1 + (i - l)] = !c[l][j + k + 1 + (i - l)];
							}
						}
				        c[i][j + k + 1] = !c[i][j + k + 1];
				    }
				}
				for (int k = 0; k < i; k++) {
				    if (c[k][i - k - 1]) {
				        c[k][j + i - k] = !c[k][j + i - k];
				    }
				}
			}
		}
	}
	cout << r;
	return 0;
}