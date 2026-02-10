#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream fout ("moobuzz.out");
    ifstream fin ("moobuzz.in");
    int n, t, c = 0; 
    fin >> n;
    t = (n / 8) * 15;
    if (n % 8 == 0) {
        t--;
    }
    n %= 8;
    for (int i = 1; i <= 15; i++) {
        if (i % 3 != 0 && i % 5 != 0) {
            c++;
        }
        if (c == n) {
            t += i;
            break;
        }
    }
    fout << t;
    return 0;
}