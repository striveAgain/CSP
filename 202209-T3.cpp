#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
typedef long long ll;

struct danPer {
    int d, u, r;
};

int n;
set<int> dRs[maxn];
vector<danPer> danLst;

int main() {
    cin >> n;

    for (int i = 0, r, m; i < n; ++i) {
        cin >> r >> m;

        for (int j = 1, p; j <= r; ++j) {
            cin >> p;
            for (int k = i; k <= i + 6; ++k) {
                dRs[k].insert(p);
            }
        }

        for (int j = 1, d, u, re; j <= m; ++j) {
            cin >> d >> u >> re;

            if (d < 0) {
                continue;
            }

            if (!dRs[d].count(re)) {
                continue;
            }

            danLst.push_back({d, u, re});
        }

        set<int> ans;
        for (int j = 0; j < danLst.size(); ++j) {
            if (danLst[j].d + 6 < i) {
                continue;
            }

            bool flag = true;
            for (int k = danLst[j].d; k <= i; ++k) {
                if (!dRs[k].count(danLst[j].r)) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans.insert(danLst[j].u);
            }
        }

        cout << i << " ";
        for (auto u : ans) {
            cout << u << " ";
        }
        cout << '\n';
    }

    return 0;
}
