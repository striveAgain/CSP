#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

vector<int> seat[maxn];
bool issit[maxn] = {false};
int n, row, col;

int main() {
    cin >> n;
    row = 20, col = 5;

    for (int i = 1, p; i <= n; ++i) {
        cin >> p;

        bool flag = false;
        for (int j = 1; j <= row and !flag; ++j) {
            int l = (j - 1) * col + 1;
            int r = j * col;

            while (issit[l]) {
                ++l;
            }

            if (r - l + 1 >= p) {
                for (int k = l; k <= l + p - 1; ++k) {
                    seat[i].push_back(k);
                    issit[k] = true;
                }
                flag = true;
            }
        }

        if (seat[i].empty()) {
            while (p--) {
                for (int j = 1; j <= 100; ++j) {
                    if (!issit[j]) {
                        seat[i].push_back(j);
                        issit[j] = true;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < seat[i].size(); ++j) {
            cout << seat[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
