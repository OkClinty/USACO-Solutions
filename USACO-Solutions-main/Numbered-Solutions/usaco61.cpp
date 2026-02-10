#include <bits/stdc++.h>
using namespace std;

struct Wormhole {
	int a, b, w;
};

bool compWorm(const Wormhole &x, const Wormhole &y) {
	return x.w > y.w;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	ofstream cout ("wormsort.out");
    	ifstream cin ("wormsort.in");
	int n, m, l = 0, r, md, p1, p2;
	bool b = true;
	cin >> n >> m;
	r = m - 1;
	vector<int> v(n), p(n + 1), s(n + 1);
	vector<Wormhole> u(m);
	stack<int> st;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] != i + 1) {
			b = false;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> u[i].a >> u[i].b >> u[i].w;
	}
	if (b) {
		cout << -1;
		return 0;
	}
	sort(u.begin(), u.end(), compWorm);
	while (l < r) {
		md = (l + r - 1) / 2;
		b = true;
		for (int i = 0; i <= n; i++) {
			p[i] = -1;
			s[i] = 1;
		}
		for (int i = 0; i <= md; i++) {
			p1 = u[i].a;
			while (p[p1] != -1) {
				st.push(p1);
				p1 = p[p1];
			}
			while (!st.empty()) {
				p[st.top()] = p1;
				st.pop();
			}
			p2 = u[i].b;
			while (p[p2] != -1) {
				st.push(p2);
				p2 = p[p2];
			}
			while (!st.empty()) {
				p[st.top()] = p2;
				st.pop();
			}
			if (p1 != p2) {
				if (s[p1] > s[p2]) {
					s[p1] += s[p2];
					p[p2] = p1;
				} else {
					s[p2] += s[p1];
					p[p1] = p2;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			p1 = i + 1;
			while (p[p1] != -1) {
				st.push(p1);
				p1 = p[p1];
			}
			while (!st.empty()) {
				p[st.top()] = p1;
				st.pop();
			}
			p2 = v[i];
			while (p[p2] != -1) {
				st.push(p2);
				p2 = p[p2];
			}
			while (!st.empty()) {
				p[st.top()] = p2;
				st.pop();
			}
			if (p1 != p2) {
				b = false;
				break;
			}
		}
		if (b) {
			r = md;
		} else {
			l = md + 1;
		}
	}
	cout << u[l].w;
	return 0;
}