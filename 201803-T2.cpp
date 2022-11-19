#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

// 注意输入不一定有序，输出时注意顺序

struct ball {
    int pos;
    int to;

    ball(int _pos = 0, int _to = 0) {
        pos = _pos;
        to = _to;
    }
};
int balls[maxn];
map<int, ball> mp;

int n, L, t;

int main() {
    cin >> n >> L >> t;

    mp[0] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        cin >> balls[i];

        mp[balls[i]] = {balls[i], 1};
    }
    mp[L] = {L, 0};

    map<int, ball>::iterator it;
    map<int, ball>::iterator it1 = mp.begin();
    for (int i = 1; i <= n + 1; ++i) {
        ++it1;
    }

    for (int i = 1; i <= t; ++i) {
        for (it = mp.begin(); it != mp.end(); ++it) {
            (*it).second.pos += (*it).second.to;
        }

        for (it = mp.begin(); it != it1; ++it) {
            map<int, ball>::iterator it2 = it;
            ++it2;

            if ((*it).second.pos == (*it2).second.pos) {
                (*it).second.to *= -1;
                (*it2).second.to *= -1;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << mp[balls[i]].pos << " ";
    }

    return 0;
}
