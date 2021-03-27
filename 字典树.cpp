// 字典树Trie 模板
#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
int node[N][26];
int cnt = 1;

void insert(string s)
{
    int cur = 1;
    for (auto c : s)
    {
        if (!node[cur][c - 'a'])
            node[cur][c - 'a'] = ++cnt;
        cur = node[cur][c - 'a'];
    }
}

bool find_prefix(string s)
{
    int cur = 1;
    for (auto c : s)
    {
        if (!node[cur][c - 'a'])
            return false;
        cur = node[cur][c - 'a'];
    }
    return true;
}

int main()
{
}