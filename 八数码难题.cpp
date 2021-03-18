// https://www.luogu.com.cn/problem/P1379
// 思路：双向BFS
#include <bits/stdc++.h>

using namespace std;
queue<string> q1;            // 从前开始搜
queue<string> q2;            // 从后开始搜
map<string, int> vis;        // 记录是否被访问过
map<string, int> dis;        // 记录距离
string target = "123804765"; // 记录目标状态
int ans;                     // 记录最终答案
int dir[4] = {-3, 1, 3, -1}; // 分别为上、右、下、左

int find_zero(string str)
{ // 找到字符串中 '0' 所在位置
    int i;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
            break;
    }
    return i;
}

bool check(int pos, int t, int i)
{
    if (t >= 0 && t <= 8)
    {
        if (i == 0 || i == 2)
        { // 上下移动，只需要判断是否超过范围即可
            return true;
        }
        else
        { // 左右移动，还需要判断行数是否改变
            if (pos / 3 == t / 3)
                return true;
            else
                return false;
        }
    }
    else
    {
        return false;
    }
}

void double_bfs(string str)
{
    q1.push(str);
    vis[str] = 1;
    dis[str] = 0;
    q2.push(target);
    vis[target] = 2;
    dis[target] = 1;
    while (!q1.empty() && !q2.empty())
    {
        bool flag;
        string cur;
        if (q1.size() < q2.size())
        {
            cur = q1.front();
            q1.pop();
            flag = true;
        }
        else
        {
            cur = q2.front();
            q2.pop();
            flag = false;
        }
        int pos = find_zero(cur); // 找到 ‘0’ 所在的位置
        for (int i = 0; i < 4; i++)
        {
            string temp = cur;
            int t = pos + dir[i]; // 要改变的位置的下标
            if (check(pos, t, i))
            {
                temp[pos] = temp[t];
                temp[t] = '0';
                if (!vis[temp])
                {
                    vis[temp] = vis[cur];
                    dis[temp] = dis[cur] + 1;
                    flag == true ? q1.push(temp) : q2.push(temp);
                }
                else
                {
                    if (vis[temp] + vis[cur] == 3)
                    {
                        ans = dis[temp] + dis[cur];
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    string str;
    cin >> str;
    double_bfs(str);
    cout << ans << endl;
    return 0;
}