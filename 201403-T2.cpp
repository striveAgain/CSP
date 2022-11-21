#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;

struct window {
    int x1, y1, x2, y2;
    int id;
};

window w[maxn];
int N, M;

int main() {
    cin >> N >> M;

    for (int i = 1, x1, y1, x2, y2; i <= N; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        w[i] = {x1, y1, x2, y2, i};
    }

    for (int i = 1, x, y; i <= M; ++i) {
        cin >> x >> y;

        int click = N;
        for (click; click >= 1; --click) {
            if (x >= w[click].x1 and x <= w[click].x2 and y >= w[click].y1 and
                y <= w[click].y2) {
                break;
            }
        }

        if (!click) {
            cout << "IGNORED" << '\n';
        } else {
            cout << w[click].id << '\n';
            window tmp = w[click];
            for (int j = click; j <= N - 1; ++j) {
                w[j] = w[j + 1];
            }

            w[N] = tmp;
        }
    }

    return 0;
}
