#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, c, t = 0;
    cin >> n;
    c = pow(2, n) - 1;
    stack<int> x, y, z;
    for (int i = n; i >= 1; i--) {
        x.push(i);
    }
    cout << c << "\n";
    if (n % 2 == 0) {
        while (c--) {
            if (t == 0) {
                if (y.empty() || (!x.empty() && x.top() < y.top())) {
                    cout << "1 2\n";
                    y.push(x.top());
                    x.pop();
                } else {
                    cout << "2 1\n";
                    x.push(y.top());
                    y.pop();
                }
            } else if (t == 1) {
                if (z.empty() || (!x.empty() && x.top() < z.top())) {
                    cout << "1 3\n";
                    z.push(x.top());
                    x.pop();
                } else {
                    cout << "3 1\n";
                    x.push(z.top());
                    z.pop();
                }
            } else {
                if (z.empty() || (!y.empty() && y.top() < z.top())) {
                    cout << "2 3\n";
                    z.push(y.top());
                    y.pop();
                } else {
                    cout << "3 2\n";
                    y.push(z.top());
                    z.pop();
                }   
            }
            t++;
            t %= 3;
        }
    } else {
        while (c--) {
            if (t == 0) {
                if (z.empty() || (!x.empty() && x.top() < z.top())) {
                    cout << "1 3\n";
                    z.push(x.top());
                    x.pop();
                } else {
                    cout << "3 1\n";
                    x.push(z.top());
                    z.pop();
                }
            } else if (t == 1) {
                if (y.empty() || (!x.empty() && x.top() < y.top())) {
                    cout << "1 2\n";
                    y.push(x.top());
                    x.pop();
                } else {
                    cout << "2 1\n";
                    x.push(y.top());
                    y.pop();
                }
            } else {
                if (z.empty() || (!y.empty() && y.top() < z.top())) {
                    cout << "2 3\n";
                    z.push(y.top());
                    y.pop();
                } else {
                    cout << "3 2\n";
                    y.push(z.top());
                    z.pop();
                }   
            }
            t++;
            t %= 3;
        }
    }
    return 0;
}