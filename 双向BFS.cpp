#include <bits/stdc++.h>

using namespace std;
int n, m;
char graph[50][50];       // 迷宫
int dis[50][50];          // 表示从起点到该点要走多少步，起点的步数是1
int vis[50][50];          // 表示该点是否被访问过
int ans;                  // 最终答案
queue<pair<int, int>> q1; // 从前面开始搜的队列
queue<pair<int, int>> q2; // 从后面开始搜的队列
int dir[4][2] = {{0, -1}, // 四个方向
                 {1, 0},
                 {0, 1},
                 {-1, 0}};

bool check(int cx, int cy)
{
    if (cx >= 0 && cx < n && cy >= 0 && cy < m && graph[cx][cy] == '.')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void double_bfs()
{
    q1.push(make_pair(0, 0));
    dis[0][0] = 1;
    vis[0][0] = 1; // 从前搜为1
    q2.push(make_pair(n - 1, m - 1));
    dis[n - 1][m - 1] = 1;
    vis[n - 1][m - 1] = 2; // 从后搜为2
    while (!q1.empty() && !q2.empty())
    {
        int x0, y0;
        bool flag;
        if (q1.size() < q2.size())
        { // 每次扩展搜索树小的队列
            x0 = q1.front().first;
            y0 = q1.front().second;
            q1.pop();
            flag = true; // flag = true 表示从前搜
        }
        else
        {
            x0 = q2.front().first;
            y0 = q2.front().second;
            q2.pop();
            flag = false; // flag = false 表示从后搜
        }
        for (int i = 0; i < 4; i++)
        {
            int dx = x0 + dir[i][0];
            int dy = y0 + dir[i][1];
            if (check(dx, dy))
            { // 表示该点可以走
                if (!vis[dx][dy])
                {
                    dis[dx][dy] = dis[x0][y0] + 1;
                    vis[dx][dy] = vis[x0][y0];
                    flag == true ? q1.push(make_pair(dx, dy)) : q2.push(make_pair(dx, dy));
                }
                else
                {
                    if (vis[dx][dy] + vis[x0][y0] == 3)
                    {
                        ans = dis[dx][dy] + dis[x0][y0];
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    double_bfs();
    cout << ans << endl;
    return 0;
}