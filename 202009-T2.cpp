#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;
const int maxm = 1e3 + 10;

pair<int, int> a[maxn][maxm];

int n, k, t, xl, yd, xr, yu;

bool checkPass(int x, int y) {
    return xl <= x && x <= xr && y >= yd && y <= yu;
}

int main() {
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= t; ++j) {
            cin >> a[i][j].first >> a[i][j].second;
        }
    }

    int ansP = 0, ansS = 0;

    for (int i = 1; i <= n; ++i) {
        bool pass = false;
        bool stay = false;
        int cnt = 0;

        for (int j = 1; j <= t; ++j) {
            if (pass && stay) {
                break;
            }

            if (checkPass(a[i][j].first, a[i][j].second)) {
                ++cnt;

                if (!pass) {
                    ++ansP;
                    pass = true;
                }
            } else {
                cnt = 0;
            }

            if (cnt >= k) {
                ++ansS;
                stay = true;
            }
        }
    }

    cout << ansP << '\n' << ansS << '\n';
    return 0;
}
