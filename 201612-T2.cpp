#include <bits/stdc++.h>
using namespace std;

int T, S;
int range[7] = {0, 1500, 4500, 9000, 35000, 55000, 80000};
int rate[7] = {3, 10, 20, 25, 30, 35, 45};

int main() {
    cin >> T;

    if (T < 3500) {
        cout << T << '\n';
        return 0;
    }

    S += 3500;
    T -= 3500;
    for (int i = 0; i < 6; ++i) {
        int tmp = (range[i + 1] - range[i]) * (100 - rate[i]) / 100;

        if (T >= tmp) {
            S += range[i + 1] - range[i];
            T -= tmp;
        } else {
            S += T / (100 - rate[i]) * 100;
            break;
        }
    }

    cout << S << '\n';
    return 0;
}
