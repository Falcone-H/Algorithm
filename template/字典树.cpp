// 字典树Trie 模板
#include <bits/stdc++.h>

using namespace std;
const int N = 50005;
int node[N][26];    // node[i][j] 表示序号为 i 的节点的 第 j 个 子节点
int cnt = 1;        // 表示节点的个数，根节点为 1
int pre_num[N];     // pre[i] 表示以该节点 及 之前的字符串为前缀的单词的数量
int end_num[N];     // end[i] 表示以当前单词结尾的单词数量
void insert(string s) {
    int cur = 1;
    for (auto c : s) {
        if (!node[cur][c - 'a'])    // 该分支不存在，则添加进去
            node[cur][c - 'a'] = ++cnt;
        cur = node[cur][c - 'a'];
        pre_num[cur]++;
    }
    end_num[cur]++;
}

// 查询该单词是否存在，如果存在，就返回数量；否则返回 -1
int search(string s) {
    if (s.size() == 0 || cnt == 1)
        return -1;
    int cur = 1;
    for (auto c : s) {
        if (!node[cur][c - 'a'])    // 表示该分支不存在
            return -1;
        cur = node[cur][c - 'a'];   // 如果存在，则继续向下遍历
    }
    return end_num[cur];
}

// 查找以字符串 s 为前缀的单词数量
int searchPrefix(string s) {
    if (cnt == 0 || s.size() == 0)
        return -1;
    int cur = 1;
    for (auto c : s) {
        if (!node[cur][c - 'a'])
            return -1;
        cur = node[cur][c - 'a'];
    }
    return pre_num[cur];
}

int main() {
    insert("hello");
    insert("hello");
    insert("hello");
    insert("helloworld");
    cout << search("hello") << "\n";
    cout << searchPrefix("hel") << "\n";
    return 0;
}