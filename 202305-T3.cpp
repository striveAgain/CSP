/*
1. 注意 readBytes 这种字节读入方法；
2. 将字符串按照某种进制转换成 10 进制可以使用 stoi(string, int* pos, int base) 来做到；
3. 将数字转换成它的二进制表示可以使用 bitset<位数>(int num).to_string() 来做到，最终结果是二进制表示的字符串；
4. 关于将读出来的字节转换成小端模式：采用 substr 方法来从后往前转换
          string lit = readBytes(litLen);
          string data;
          for (int i = lit.size() - 2; i >= 0; i -= 2) {
              data += lit.substr(i, 2);
          }
*/
#include <bits/stdc++.h>

using namespace std;

const int S = 2e6 + 10;

int s, idx = 0;
string ans;

string readBytes(int len) {
    char tmp[2 * len + 1];
    for (int i = 0; i < 2 * len; ++i) {
        cin >> tmp[i];
    }
    tmp[2 * len] = '\0';

    idx += 2 * len;
    return string(tmp);
}

void traceBack(int o, int l) {
    int start = ans.size() - o * 2;
    string traceBackString = ans.substr(start, o * 2);

    int cnt = l / o;
    int last = l - o * cnt;
    for (int i = 1; i <= cnt; ++i) {
        ans += traceBackString;
    }

    if (last) {
        ans += traceBackString.substr(0, last * 2);
    }
}

int main() {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);

    cin >> s;

    vector<int> lenFacs;
    string bits;
    while ((bits = readBytes(1)) >= "80") {
        int fac = stoi(bits, nullptr, 16) - 128;
        lenFacs.push_back(fac);
    }

    int fac = stoi(bits, nullptr, 16);
    lenFacs.push_back(fac);

    // 引导区长度
    int len = 0;
    for (int i = 0; i < lenFacs.size(); ++i) {
        len += lenFacs[i] * pow(128, i);
    }

    while (idx < s * 2) {
        bits = readBytes(1);
        string binary = bitset<8>(stoi(bits, nullptr, 16)).to_string();

        string low2bits = binary.substr(6, 2);
        if (low2bits == "00") {
            string high6bits = binary.substr(0, 6);
            int l = stoi(high6bits, nullptr, 2);

            if (l <= 59) {
                ans += readBytes(l + 1);
            } else {
                int litLen = l - 59;

                string lit = readBytes(litLen);
                string data;
                for (int i = lit.size() - 2; i >= 0; i -= 2) {
                    data += lit.substr(i, 2);
                }

                int l = stoi(data, nullptr, 16) + 1;
                ans += readBytes(l);
            }
        } else if (low2bits == "01") {
            string midl = binary.substr(3, 3);
            int l = stoi(midl, nullptr, 2) + 4;

            string high3bits = binary.substr(0, 3);
            string low8bits =
                bitset<8>(stoi(readBytes(1), nullptr, 16)).to_string();

            string oo = high3bits + low8bits;
            int o = stoi(oo, nullptr, 2);

            traceBack(o, l);
        } else if (low2bits == "10") {
            string ll = binary.substr(0, 6);
            int l = stoi(ll, nullptr, 2) + 1;

            string next2Bytes = readBytes(2);
            string data;
            for (int i = next2Bytes.size() - 2; i >= 0; i -= 2) {
                data += next2Bytes.substr(i, 2);
            }

            int o = stoi(data, nullptr, 16);

            traceBack(o, l);
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if ((i + 1) % 16 == 0) {
            cout << '\n';
        }
    }

    return 0;
}
