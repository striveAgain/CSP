#include <bits/stdc++.h>
using namespace std;

/*
  分别对每个阈值记录其前缀 0 和后缀 1 的个数即可；
  （可以使用前后缀和，也可以使用差分，这里用的是差分）
*/

const int maxm = 1e5 + 10;
vector<pair<int, int>> a(maxm);
vector<int> pre0(maxm);
vector<int> nxt1(maxm);

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin() + 1, a.begin() + 1 + n);

    for (int i = 1; i <= n; ++i) {
        if (!a[i].second) {
            ++pre0[i];
        } else {
            ++nxt1[i];
        }
    }

    for (int i = 1; i <= n; ++i) {
        pre0[i] += pre0[i - 1];
    }

    for (int i = n - 1; i >= 1; --i) {
        nxt1[i] += nxt1[i + 1];
    }

    int ans = 0, tmp = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i].first == a[i - 1].first) {
            continue;
        }

        if (pre0[i - 1] + nxt1[i] >= tmp) {
            tmp = pre0[i - 1] + nxt1[i];
            ans = max(ans, a[i].first);
        }
    }

    cout << ans << '\n';
    return 0;
}
