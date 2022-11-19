#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> persons;

bool judge(int cnt) {
    int tmp = cnt % 10;
    if (tmp == k) {
        return true;
    }

    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        persons.push(i);
    }

    int cnt = 1;
    while (persons.size() != 1) {
        int idx = persons.front();
        persons.pop();

        if (cnt % k != 0 and !judge(cnt)) {
            persons.push(idx);
        }

        ++cnt;
    }

    cout << persons.front() << '\n';
    return 0;
}
