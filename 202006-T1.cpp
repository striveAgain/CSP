/*
  1. 分别计算 A 类点和 B 类点 代入直线得到的结果；
  2. 分别对两个结果进行排序；
  3. 排序后我们只需要检查首尾即可：
    3.1 若 A 排序后第一个元素 > 0，即最小值 > 0；则 B 的最大值（排序后最后一个元素）就一定得 < 0；
    3.2 同理可以反推 B 第一个元素 > 0，A 最后一个元素 < 0；
*/


#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
struct ptn {
    int x, y;
    string type;
} ptns[maxn];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> ptns[i].x >> ptns[i].y >> ptns[i].type;
    }

    for (int i = 1; i <= m; ++i) {
        int t0, t1, t2;
        cin >> t0 >> t1 >> t2;
        
        // 代入直线计算结果，并保存结果数量
        int reA[maxn], reB[maxn], posA = 0, posB = 0;
        for (int j = 1; j <= n; ++j) {
            if (ptns[j].type == "A") {
                ++posA;
                reA[posA] = t0 + t1 * ptns[j].x + t2 * ptns[j].y;
            }

            if (ptns[j].type == "B") {
                ++posB;
                reB[posB] = t0 + t1 * ptns[j].x + t2 * ptns[j].y;
            }
        }

        sort(reA + 1, reA + 1 + posA);
        sort(reB + 1, reB + 1 + posB);

        if ((reA[1] > 0 && reB[posB] < 0) || (reB[1] > 0 && reA[posA] < 0)) {
            cout << "Yes" << '\n';
            continue;
        }

        cout << "No" << '\n';
    }

    return 0;
}
