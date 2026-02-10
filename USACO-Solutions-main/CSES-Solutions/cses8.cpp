#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        if (n % 2 == 0) {
            cout << n / 2 << "\n";
            for (int i = 1; i <= n / 4; i++) {
                cout << i << " " << n - i + 1 << " ";
            }
            cout << "\n" << n / 2 << "\n";
            for (int i = n / 4 + 1; i <= n / 2; i++) {
                cout << i << " " << n - i + 1 << " ";
            }
            cout << "\n";
        } else {
            cout << n / 2 << "\n" << n << " ";
            for (int i = 1; i <= n / 4; i++) {
                cout << i << " " << n - i << " ";
            }
            cout << "\n" << n / 2 + 1 << "\n";
            for (int i = n / 4 + 1; i <= n / 2; i++) {
                cout << i << " " << n - i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}