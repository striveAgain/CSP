#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > u;
vector<pair<int, int> > v;

int n, a, b;

int main() {
    cin >> n >> a >> b;
    for (int i = 1, idx, val; i <= a; ++i) {
        cin >> idx >> val;
        u.push_back({idx, val});
    }

    for (int i = 1, idx, val; i <= b; ++i) {
        cin >> idx >> val;
        v.push_back({idx, val});
    }

    int posu = 0, posv = 0;
    long long ans = 0ll;
    while (posu < a and posv < b) {
        if (u[posu].first == v[posv].first) {
            ans += u[posu].second * v[posv].second * 1ll;
            ++posu, ++posv;
        } else if (u[posu].first < v[posv].first) {
            ++posu;
        } else {
            ++posv;
        }
    }

    cout << ans << '\n';
    return 0;
}
