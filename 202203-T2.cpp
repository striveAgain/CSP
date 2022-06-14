#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const int maxt = 2e5 + 10;
int d[maxt];

/*
  主要思路：前缀和 + 差分（多次修改，少数查询）
*/

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int maxT = 0;
    for (int i = 1, t, c; i <= n; ++i) {
        cin >> t >> c;
        maxT = max(maxT, t);

        int l = (t - c + 1 <= 1) ? 1 : t - c + 1;
        ++d[l];
        --d[t + 1];
    }

    for (int i = 1; i <= maxT; ++i) {
        d[i] += d[i - 1];
    }

    for (int i = 1, q; i <= m; ++i) {
        cin >> q;
        // 这里需要特判一下，因此 q <= 2e5, k <= 1e5，二者相加可能超过出行计划的最大值 t (<= 2e5)，此时可能 RE
        if (q + k > 200000) {
            cout << 0 << '\n';
        } else {
            cout << d[q + k] << '\n';
        }
    }

    return 0;
}
