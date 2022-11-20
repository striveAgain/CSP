#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;

int grids[maxn][maxn], tmp[maxn][maxn];
int n, m;

void seq(int row, int col, int& l, int& d) {
    l = d = 0;
    for (int j = col; j <= m; ++j) {
        if (grids[row][col] and grids[row][j] == grids[row][col]) {
            ++l;
        } else {
            break;
        }
    }

    for (int i = row; i <= n; ++i) {
        if (grids[row][col] and grids[i][col] == grids[row][col]) {
            ++d;
        } else {
            break;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grids[i][j];
            tmp[i][j] = grids[i][j];
        }
    }

    int l = 0, d = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            seq(i, j, l, d);

            if (l >= 3) {
                for (int k = j; k <= j + l - 1; ++k) {
                    tmp[i][k] = 0;
                }
            }

            if (d >= 3) {
                for (int k = i; k <= i + d - 1; ++k) {
                    tmp[k][j] = 0;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << tmp[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
