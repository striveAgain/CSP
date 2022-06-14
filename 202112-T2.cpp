#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
  暴力解法：从 1 到 N 求解所有的 g(x) 和 f(x)，时间复杂度 O(N)，N <= 1e9，无法接受；
  观察得到 n 在 1e5，并且 N / (n + 1) 在 1e4 级别，因此想到将 1-N 个数进行区间化，遍历区间求解答案；
*/

const int maxn = 1e5 + 10;
int n, N;

vector<int> a(maxn, 0);
vector<pair<int, int>> f;
vector<pair<int, int>> g;

int main() {
    cin >> n >> N;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    // 区间化 f
    for (int i = 0; i <= n - 1; ++i) {
        f.emplace_back(a[i], a[i + 1]);
    }
    f.emplace_back(a[n], N);
    
    // 区间化 g
    int r = N / (n + 1);
    for (int i = 0; i <= N - 1; i += r) {
        int bor = (i + r > N) ? N : i + r;
        g.emplace_back(i, bor);
    }
    
    // 遍历区间进行求解
    int posf = 0, posg = 0;
    ll ans = 0ll;
    while (posf < f.size() && posg < g.size()) {
        int l = max(f[posf].first, g[posg].first);
        int r = min(f[posf].second, g[posg].second);

        ans += (abs(posf - posg) * (r - l));
        if (r == f[posf].second) {
            ++posf;
        }

        if (r == g[posg].second) {
            ++posg;
        }
    }

    cout << ans << '\n';
    return 0;
}
