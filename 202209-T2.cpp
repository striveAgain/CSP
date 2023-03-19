// Solution 1 -- 01背包
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, x, w[35], dp[N];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 300001; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i <= 300001; ++i) {
        if (dp[i] >= x) {
            ans = min(ans, dp[i]);
        }
    }

    cout << ans << '\n';
    return 0;
}

// solution 2 -- dfs + 前缀和剪枝
#include <bits/stdc++.h>
using namespace std;

const int N = 35;

int n, x, q[N], ans, pre[N];

void dfs(int cur, int sum) {
    if (sum >= x) {
        ans = min(ans, sum);
        return;
    }

    if (sum + pre[n] - pre[cur - 1] < x) {
        return;
    }

    dfs(cur + 1, sum);
    dfs(cur + 1, sum + q[cur]);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> q[i];
        pre[i] = pre[i - 1] + q[i];
    }

    ans = INT_MAX;
    dfs(1, 0);

    cout << ans << '\n';
    return 0;
}

