#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
const int maxs = 55;
int n, L, S;

map<pair<int, int>, bool> l;
bool s[maxs][maxs] = {false};

int main() {
    cin >> n >> L >> S;

    for (int i = 1, x, y; i <= n; ++i) {
        cin >> x >> y;
        pair<int, int> tmp(x, y);
        l[tmp] = true;
    }

    for (int i = 0; i <= S; ++i) {
        for (int j = 0; j <= S; ++j) {
            int tmp;
            cin >> tmp;

            s[S - i][j] = tmp;
        }
    }

    int ans = 0;
    map<pair<int, int>, bool>::iterator it = l.begin();

    for (it; it != l.end(); ++it) {
        int baserow = (*it).first.first, basecol = (*it).first.second;
        bool flag = true;
        for (int i = 0; i <= S; ++i) {
            for (int j = 0; j <= S; ++j) {
                if (s[i][j] and !l.count({baserow + i, basecol + j})) {
                    flag = false;
                    break;
                } else if (!s[i][j] and l.count({baserow + i, basecol + j})) {
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                break;
            }
        }

        if (flag) {
            if (baserow + S <= L and basecol + S <= L) {
                ++ans;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
