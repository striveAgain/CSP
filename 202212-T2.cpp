/*
最早开始从头算起，最晚开始从尾算起；注意每个任务制依赖于编号比他小的任务这一条件；
*/

#include <iostream>
using namespace std;

const int N = 370, M = 110;

int n, m;
int p[M], t[M];
int early[M], late[M];

void getEarliest() {
	for (int i = 1; i <= m; ++i) {
		early[i] = max(1, early[i]);
		if (p[i]) {
			early[i] = max(early[i], early[p[i]] + t[p[i]]);
		}
	}
}

void getLatest() {
	for (int i = 1; i <= m; ++i) {
		late[i] = INT_MAX;
	}
	
	for (int i = m; i > 0; --i) {
		late[i] = min(late[i], n - t[i] + 1);
		if (p[i]) {
			late[p[i]] = min(late[p[i]], late[i] - t[p[i]]);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> p[i];
	}
	
	for (int i = 1; i <= m; ++i) {
		cin >> t[i];
	}
	
	getEarliest();
	
	int maxEarliest = 0;
	for (int i = 1; i <= m; ++i) {
		maxEarliest = max(maxEarliest, early[i] + t[i] - 1);
		cout << early[i] << " ";
	}
	
	if (maxEarliest <= n) {
		getLatest();
		
		cout << '\n';
		for (int i = 1; i <= m; ++i) {
			cout << late[i] << " ";
		}
	}
	
	return 0;
}
