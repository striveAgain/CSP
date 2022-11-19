#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int N, K;

int hooks[maxn];

struct op {
    int time;
    int key;
    bool lend;

    bool operator<(const op& a) const {
        if (time != a.time) {
            return time < a.time;
        } else if (lend != a.lend) {
            return lend < a.lend;
        }

        return key < a.key;
    }
};
op ops[2 * maxn];

int main() {
    cin >> N >> K;

    int cnt = 0;
    for (int i = 1, w, s, c; i <= K; ++i) {
        cin >> w >> s >> c;

        ++cnt;
        ops[cnt] = {s, w, true};
        ++cnt;
        ops[cnt] = {s + c, w, false};
    }
    sort(ops + 1, ops + cnt + 1);

    for (int i = 1; i <= N; ++i) {
        hooks[i] = i;
    }

    for (int i = 1; i <= cnt; ++i) {
        if (ops[i].lend) {
            for (int j = 1; j <= N; ++j) {
                if (hooks[j] == ops[i].key) {
                    hooks[j] = 0;
                    break;
                }
            }
        } else {
            for (int j = 1; j <= N; ++j) {
                if (!hooks[j]) {
                    hooks[j] = ops[i].key;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << hooks[i] << " ";
    }

    return 0;
}
