#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;

int grids[maxn][maxn], tmp[maxn][maxn];
int n, m;

void seq(int row, int col, int& l, int& d) {
    l = d = 0;
    for (int j = col; j <= m; ++j) {
        if (grids[row][col] and grids[row][j] == grids[row][col]) {
            ++l;
        } else {
            break;
        }
    }

    for (int i = row; i <= n; ++i) {
        if (grids[row][col] and grids[i][col] == grids[row][col]) {
            ++d;
        } else {
            break;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grids[i][j];
            tmp[i][j] = grids[i][j];
        }
    }

    int l = 0, d = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            seq(i, j, l, d);

            if (l >= 3) {
                for (int k = j; k <= j + l - 1; ++k) {
                    tmp[i][k] = 0;
                }
            }

            if (d >= 3) {
                for (int k = i; k <= i + d - 1; ++k) {
                    tmp[k][j] = 0;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << tmp[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}


/*
#include <iostream>
#include <cmath>
 
using namespace std;
 
const int N = 30;
 
int grid[N][N], n, m;
 
int main()
{
    // 输入数据
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
 
    // 进行行标记（可以消除则置为负）
    for(int i=0; i<n; i++)
        for(int j=0; j<m-2; j++) {
            if(abs(grid[i][j]) == abs(grid[i][j+1]) && abs(grid[i][j+1]) == abs(grid[i][j+2])) {
                if(grid[i][j] > 0)
                    grid[i][j] = - grid[i][j];
                if(grid[i][j+1] > 0)
                    grid[i][j+1] = - grid[i][j+1];
                if(grid[i][j+2] > 0)
                    grid[i][j+2] = - grid[i][j+2];
            }
        }
 
    // 进行列标记（可以消除则置为负）
    for(int j=0; j<m; j++)
        for(int i=0; i<n-2; i++) {
            if(abs(grid[i][j]) == abs(grid[i+1][j]) && abs(grid[i+1][j]) == abs(grid[i+2][j])) {
                if(grid[i][j] > 0)
                    grid[i][j] = - grid[i][j];
                if(grid[i+1][j] > 0)
                    grid[i+1][j] = - grid[i+1][j];
                if(grid[i+2][j] > 0)
                    grid[i+2][j] = - grid[i+2][j];
            }
        }
 
    // 进行清除（可以消除则置为0）并且输出结果
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] < 0)
                grid[i][j] = 0;
            if(j != 0)
                cout << " ";
            cout << grid[i][j];
        }
        cout << endl;
    }
 
    return 0;
}
*/
