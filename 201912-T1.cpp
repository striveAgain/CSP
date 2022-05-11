#include <bits/stdc++.h>
using namespace std;

vector<int> cnt(4, 0);

int main() {
    int n;
    cin >> n;

    int pos = 0;
    for (int i = 1; i <= n + pos; ++i) {
        if (i % 7 == 0) {
            ++cnt[i % 4];
            ++pos;
        } else {
            int tmp = i;

            while (tmp) {
                if (tmp % 10 == 7) {
                    ++cnt[i % 4];
                    ++pos;
                    break;
                }

                tmp /= 10;
            }
        }
    }

    for (int i = 1; i < 4; ++i) {
        cout << cnt[i] << '\n';
    }
    cout << cnt[0] << '\n';

    return 0;
}
