#include <bits/stdc++.h>
using namespace std;

/*
  主要思路：二维前缀和
*/

const int maxn = 605;
int n, L, r, t;

int pre[maxn][maxn];

int main() {
    cin >> n >> L >> r >> t;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int tmp;
            cin >> tmp;

            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + tmp;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int lux = (i - r >= 1) ? i - r : 1;
            int luy = (j - r >= 1) ? j - r : 1;

            int rdx = (i + r >= n) ? n : i + r;
            int rdy = (j + r >= n) ? n : j + r;

            int row = rdx - lux + 1;
            int col = rdy - luy + 1;

            int sum = pre[rdx][rdy] - pre[lux - 1][rdy] - pre[rdx][luy - 1] +
                      pre[lux - 1][luy - 1];

            if (sum <= t * row * col) {
                ++ans;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
