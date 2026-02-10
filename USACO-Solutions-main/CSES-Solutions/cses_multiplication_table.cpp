#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
	long long n, l = 1, r, m, c;
	cin >> n;
	r = n * n;
	while (l < r) {
		m = (l + r) / 2;
		c = 0;
		for (int i = 1; i <= n; i++) { 
		    c += min(n, m / i); 
		}
		if (c >= (n * n + 1) / 2) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	cout << r;
    return 0;
}