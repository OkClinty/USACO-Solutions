#include <bits/stdc++.h>
using namespace std;

vector<int> X(1000), Y(1000);

bool eSort(int a, int b) {
    return Y[a] < Y[b];
}

bool nSort(int a, int b) {
    return X[a] < X[b];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, y;
    char c;
    cin >> n;
    vector<int> E, N, didS(n);
    vector<bool> isS(n);
    for (int i = 0; i < n; i++) {
        cin >> c >> x >> y;
        X[i] = x;
        Y[i] = y;
        if (c == 'E') {
            E.push_back(i);
        } else {
            N.push_back(i);
        }
    }
    sort(E.begin(), E.end(), eSort);
    sort(N.begin(), N.end(), nSort);
    for (int i : E) {
        for (int j : N) {
            if (!isS[i] && !isS[j] && X[i] <= X[j] && Y[i] >= Y[j]) {
                if (X[j] - X[i] > Y[i] - Y[j]) {
                    isS[i] = true;
                    didS[j] += 1 + didS[i];
                } else if (X[j] - X[i] < Y[i] - Y[j]) {
                    isS[j] = true;
                    didS[i] += 1 + didS[j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << didS[i] << "\n";
    }
    return 0;
}