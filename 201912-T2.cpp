#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int n;
map<pair<int, int>, bool> mp;
vector<int> place(5);

int main() {
    cin >> n;
    for (int i = 1, x, y; i <= n; ++i) {
        cin >> x >> y;
        mp[{x, y}] = true;
    }

    map<pair<int, int>, bool>::iterator it = mp.begin();
    for (it; it != mp.end(); ++it) {
        int posx = (*it).first.first, posy = (*it).first.second;
        int x[4] = {posx, posx, posx - 1, posx + 1};
        int y[4] = {posy - 1, posy + 1, posy, posy};

        int sc = 0;
        for (int i = 0; i < 4; ++i) {
            if (mp.count({x[i], y[i]})) {
                ++sc;
            }
        }

        if (sc == 4) {
            int dx[4] = {1, 1, -1, -1};
            int dy[4] = {1, -1, 1, -1};
            int s = 0;
            for (int i = 0; i < 4; ++i) {
                if (mp.count({posx + dx[i], posy + dy[i]})) {
                    ++s;
                }
            }

            ++place[s];
        }
    }

    for (int i = 0; i < 5; ++i) {
        cout << place[i] << '\n';
    }

    return 0;
}
