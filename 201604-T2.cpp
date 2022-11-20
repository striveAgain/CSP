// solution 1
#include <bits/stdc++.h>
using namespace std;

int grids[24][11] = {0};
int block[5][5] = {0};

int n;

bool check(int x1, int y1) {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (grids[x1 + i - 1][y1 + j - 1] and block[i][j]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    for (int i = 20; i <= 23; ++i) {
        for (int j = 1; j <= 10; ++j) {
            grids[i][j] = 1;
        }
    }

    for (int i = 5; i <= 19; ++i) {
        for (int j = 1; j <= 10; ++j) {
            cin >> grids[i][j];
        }
    }

    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            cin >> block[i][j];
        }
    }

    cin >> n;

    int bdy = 1;
    for (int i = 5; i <= 22; ++i) {
        int xBeg = i - 3, yBeg = n;

        if (!check(xBeg, yBeg)) {
            ++bdy;
        } else {
            break;
        }
    }

    for (int i = bdy; i <= bdy + 3; ++i) {
        for (int j = n; j <= n + 3; ++j) {
            grids[i][j] |= block[i - bdy + 1][j - n + 1];
        }
    }

    for (int i = 5; i <= 19; ++i) {
        for (int j = 1; j <= 10; ++j) {
            cout << grids[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
