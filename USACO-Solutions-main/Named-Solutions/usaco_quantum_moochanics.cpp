#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, a, b, c = 0;
	bool A, B;
	cin >> n;
	vector<long long> p(n), s(n), r(n);
	priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i < n; i++) {
		pq.push({2 * (((p[i] - p[i - 1] - 1) / (s[i] + s[i - 1])) + 1) - (i % 2), {i - 1, i}});
	}
	while (c < n) {
		auto cur = pq.top();
		pq.pop();
		a = cur.second.first;
		b = cur.second.second;
		if (r[a] == 0 && r[b] == 0) {
			r[a] = cur.first;
			r[b] = cur.first;
			c += 2;
			a--;
			b++;
			while (a >= 0 && b < n) {
				A = (r[a] == 0);
				B = (r[b] == 0);
				if (A && B) {
					pq.push({2 * (((p[b] - p[a] - 1) / (s[b] + s[a])) + 1) - (b % 2), {a, b}});
					break;
				}
				if (!A) {
					a--;
				}
				if (!B) {
					b++;
				}
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		cout << r[i] << " ";
	}
	cout << r[n - 1] << "\n";
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