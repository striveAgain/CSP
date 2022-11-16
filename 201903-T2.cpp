#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        string exp;
        cin >> exp;

        deque<char> ops;
        deque<int> nums;
        for (int j = 0; j < exp.size(); ++j) {
            if (isdigit(exp[j])) {
                nums.push_back(exp[j] - '0');
            } else if (exp[j] == '+' or exp[j] == '-') {
                ops.push_back(exp[j]);
            } else if (exp[j] == 'x' or exp[j] == '/') {
                int num1 = nums.back();
                nums.pop_back();

                int num2 = exp[j + 1] - '0';

                int num = (exp[j] == 'x') ? num1 * num2 : num1 / num2;
                nums.push_back(num);
                ++j;
            }
        }

        int opSize = ops.size();
        for (int i = 1; i <= opSize; ++i) {
            char op = ops.front();
            ops.pop_front();

            int num1 = nums.front();
            nums.pop_front();
            
            int num2 = nums.front();
            nums.pop_front();

            int num = (op == '+') ? num1 + num2 : num1 - num2;
            nums.push_front(num);
        }

        if (nums.front() == 24) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }

    return 0;
}
