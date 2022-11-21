#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int mat[maxn][maxn];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mat[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!(i & 1)) {
            for (int j = 1; j <= i; ++j) {
                cout << mat[j][i - j + 1] << " ";
            }
        } else {
            for (int j = 1; j <= i; ++j) {
                cout << mat[i - j + 1][j] << " ";
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (!((i + n - 1) & 1)) {
            for (int j = i; j <= n; ++j) {
                cout << mat[j][n + i - j] << " ";
            }
        } else {
            for (int j = i; j <= n; ++j) {
                cout << mat[n - j + i][j] << " ";
            }
        }
    }

    return 0;
}
