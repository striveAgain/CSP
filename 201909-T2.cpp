#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 5;
vector<int> drop(maxN, 0);
int n;

// 注意多次掉落只算一次

int main() {
    cin >> n;

    long long T = 0ll;
    int D = 0, E = 0;
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;

        int apple = -1;
        bool isdrop = false;
        for (int j = 1, tmp; j <= m; ++j) {
            cin >> tmp;

            if (tmp <= 0) {
                if (apple + tmp <= 0) {
                    apple = 0;
                } else {
                    apple += tmp;
                }
            } else {
                if (apple == -1) {
                    apple = tmp;
                } else {
                    if (apple != tmp) {
                        if (!isdrop) {
                            ++D;
                            isdrop = true;
                        }
                        drop[i] = 1;
                    }
                    apple = tmp;
                }
            }
        }

        T += apple * 1ll;
    }

    drop[n + 1] = drop[1], drop[n + 2] = drop[2];
    for (int i = 1; i <= n; ++i) {
        if (drop[i] and drop[i + 1] and drop[i + 2]) {
            ++E;
        }
    }

    cout << T << " " << D << " " << E;
    return 0;
}
