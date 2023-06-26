/*
注意将矩阵 Z 字扫描成一维数组以及用一维数组来 Z 字填充矩阵的方法和下标映射关系即可
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n, T;
int Q[N][N], M[N][N], QM[N][N];
double Mprime[N][N];

void fillup(int n) {
	for (int i = 1; i <= 8; ++i) {
		if (n) {
			if (!(i & 1)) {
				for (int j = 1; j <= i && n; ++j) {
					cin >> M[j][i - j + 1];
					--n;
				}
			} else {
				for (int j = 1; j <= i && n; ++j) {
					cin >> M[i - j + 1][j];
					--n;
				}
			}
		} else {
			return;
		}
	}
	
	for (int i = 2; i <= 8; ++i) {
		if (n) {
			if (!((i + 8 - 1) & 1)) {
				for (int j = i; j <= 8 && n; ++j) {
					cin >> M[j][8 + i - j];
					--n;
				}
			} else {
				for (int j = i; j <= 8 && n; ++j) {
					cin >> M[8 - j + i][j];
					--n;
				}
			}
		} else {
			return;
		}
	}
}

void multi() {
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			QM[i][j] = Q[i][j] * M[i][j];
		}
	}
}

double alpha(int x) {
	if (!x) {
		return sqrt(1.0 / 2.0);
	} else {
		return 1;
	}
}

void cosTrans() {
	double pi = acos(-1);
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			double sum = 0.0;
			
			for (int m = 1; m <= 8; ++m) {
				for (int n = 1; n <= 8; ++n) {
					double cos1 = cos(pi / 8.0 * (i - 1.0 + 0.5) * (m - 1));
					double cos2 = cos(pi / 8.0 * (j - 1.0 + 0.5) * (n - 1));
					
					sum += alpha(m - 1) * alpha(n - 1) * QM[m][n] * cos1 * cos2;
				}
			}
			
			Mprime[i][j] = sum / 4.0;
		}
	}
}

int main() {
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			cin >> Q[i][j];
		}
	}
	
	cin >> n >> T;
	
	fillup(n);
	if (T == 0) {
		for (int i = 1; i <= 8; ++i) {
			for (int j = 1; j <= 8; ++j) {
				cout << M[i][j] << " ";
			}
			cout << '\n';
		}
	} else if (T == 1) {
		multi();
		for (int i = 1; i <= 8; ++i) {
			for (int j = 1; j <= 8; ++j) {
				cout << QM[i][j] << " ";
			}
			cout << '\n';
		}
	} else if (T == 2) {
		multi();
		cosTrans();
		for (int i = 1; i <= 8; ++i) {
			for (int j = 1; j <= 8; ++j) {
				int tmp = int(Mprime[i][j] + 0.5 + 128.0);
				tmp = min(tmp, 255);
				tmp = max(tmp, 0);
				
				cout << tmp << " ";
			}
			cout << '\n';
		}
	}
	
	return 0;
}
