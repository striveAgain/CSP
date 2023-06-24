/*
1. m * n 的矩阵 A 和 n * d 的矩阵 B 做乘积的时间复杂度为 m * n * d；
2. 本题要先使后面两个矩阵相乘，再乘第一个以降低复杂度！！！！
3. 注意开 long long
*/
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int N = 1e4 + 10;
const int D = 25;

int n, d;
int Q[N][D], K[D][N], V[N][D];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= d; ++j) {
			cin >> Q[i][j];
		}
	}
	
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= d; ++i) {
			cin >> K[i][j];
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= d; ++j) {
			cin >> V[i][j];
		}
	}
	
	for (int i = 1, tmp; i <= n; ++i) {
		cin >> tmp;
		for (int j = 1; j <= d; ++j) {
			Q[i][j] *= tmp;
		}
	}
	
	ll tmp1[D][D];
	for (int i = 1; i <= d; ++i) {
		for (int j = 1; j <= d; ++j) {
			ll sum = 0;
			for (int k = 1; k <= n; ++k) {
				sum += K[i][k] * V[k][j] * 1ll;
			}
			
			tmp1[i][j] = sum;
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= d; ++j) {
			ll sum = 0;
			for (int k = 1; k <= d; ++k) {
				sum += Q[i][k] * tmp1[k][j] * 1ll;
			}
			
			cout << sum << " ";
		}
		cout << '\n';
	}
	
	return 0;
}
