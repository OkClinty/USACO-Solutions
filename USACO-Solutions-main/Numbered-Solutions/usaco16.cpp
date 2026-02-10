#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream fout ("square.out");
    ifstream fin ("square.in");
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    fin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;
    fout << pow(max(max(ax2, bx2) - min(ax1, bx1), max(ay2, by2) - min(ay1, by1)), 2);
    return 0;
}