#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1";  
    } else if (n < 4) {
        cout << "NO SOLUTION";
    } else {
        for (int i = n / 2 + 1; i <= n - n % 2; i++) {
            cout << i << " " << i - n / 2 << " ";
        }
        if (n % 2 == 1) {
            cout << n << " ";
        }
    }
    return 0;
}