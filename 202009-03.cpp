#include <bits/stdc++.h>
using namespace std;

const int maxm = 1e8 + 10;
vector<int> a(maxm);
vector<bool> success(maxm);
vector<int> pre0(maxm);
vector<int> nxt1(maxm);

int main() {
    int n;
    cin >> n;

    for (int i = 1, tmp; i <= n; ++i) {
        cin >> a[i] >> tmp;
        success[a[i]] = tmp;
    }

    auto it = unique(a.begin() + 1, a.begin() + 1 + n);
    a.erase(it, a.end());

    n = a.size();
    cout << n << '\n';

    for (int i = 1; i <= n; ++i) {
        if (!success[a[i]]) {
            ++pre0[i + 1];
        } else {
            ++nxt1[i];
        }
    }

    for (int i = 1; i <= n; ++i) {
        pre0[i] += pre0[i - 1];
    }
    for (int i = 0; i <= n; ++i) {
        cout << pre0[i] << " ";
    }
    cout << '\n';

    for (int i = n - 1; i >= 0; --i) {
        nxt1[i] += nxt1[i + 1];
    }
    for (int i = 0; i <= n; ++i) {
        cout << nxt1[i] << " ";
    }
    cout << '\n';

    for (int i = 1; i <= n; ++i) {
        pre0[i] += nxt1[i];
    }

    int mx = *max_element(pre0.begin() + 1, pre0.begin() + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (pre0[i] == mx) {
            ans = max(ans, a[i]);
        }
    }

    cout << ans << '\n';
    return 0;
}
