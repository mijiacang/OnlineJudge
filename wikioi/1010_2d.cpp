/*
题目描述 Description
　如图，A 点有一个过河卒，需要走到目标 B 点。卒行走规则：可以向下、或者向右。同时在棋盘上的任一点有一个对方的马（如上图的C点），该马所在的点和所有跳跃一步可达的点称为对方马的控制点。例如上图 C 点上的马可以控制 9 个点（图中的P1，P2 … P8 和 C）。卒不能通过对方马的控制点。

　　棋盘用坐标表示，A 点（0，0）、B 点（n,m）(n,m 为不超过 20 的整数，并由键盘输入)，同样马的位置坐标是需要给出的（约定: C不等于A，同时C不等于B）。现在要求你计算出卒从 A 点能够到达 B 点的路径的条数。
1<=n,m<=15

Solutions:
sols[i][j] paths to position (i, j)
sols[i][j] = in horseRange ? 0 : sols[i - 1][j] + sols[i][j - 1];
*/
#include <cstdio>
int main() {
    int n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    int sols[n + 1][m + 1], dx[] = {0, -1, -2, -2, -1, 1, 2, 2, 1}, dy[] = {0, -2, -1, 1, 2, 2, 1, -1, -2}, step = sizeof(dx) / sizeof(int);
    for (int k = 0; k < step; k++) {
        int xx = x + dx[k], yy = y + dy[k];
        if (xx >= 0 && yy >= 0 && xx <= n && yy <= m) sols[xx][yy] = -1;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            sols[i][j] = (sols[i][j] == -1 ? 0 : (i == 0 && j == 0 ? 1 : ((i == 0 ? 0 : sols[i - 1][j]) + (j == 0 ? 0 : sols[i][j - 1]))));
            
        }
    }
    printf("%d", sols[n][m]);
    return 0;
}
