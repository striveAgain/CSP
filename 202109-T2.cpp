#include <bits/stdc++.h>
using namespace std;

/*
  主要思路：差分
  假设海水将所有岛屿都淹没，现在海平面开始下降
    1. 若出现一个凸峰，则岛屿数 + 1；（此时的海平面记为 t，对任意 i < t，这都是一个凸峰）；
    2. 若出现一个凹谷，则岛屿数 - 1；（对任意 i < t，这都是一个凹谷）；
  因此，我们维护的相当于是一个后缀和，因此从后向前进行求后缀和，然后输出最大值即可；
*/

const int maxn = 5e5 + 10;
int a[maxn];
int d[maxn];

int main() {
    int n;
    cin >> n;

    int maxA = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }

    n = unique(a, a + n + 2) - a - 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i - 1] < a[i] and a[i] > a[i + 1]) {
            ++d[a[i]];
        } else if (a[i - 1] > a[i] and a[i] < a[i + 1]) {
            --d[a[i]];
        }
    }

    for (int i = maxA; i >= 1; --i) {
        d[i] += d[i + 1];
    }

    cout << *max_element(d + 1, d + 1 + maxA) << '\n';
    return 0;
}
