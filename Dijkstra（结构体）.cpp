#include<bits/stdc++.h>

#define int long long
using namespace std;
int n, m, s;    //n���㣬m���ߣ��ӵ�s�ŵ㿪ʼ
int node;   //��ǰ���ڴ���Ľڵ�
int minn;
int dist[10000];    //��¼ÿ���㵽���ľ���
bool vis[10000];    //��¼�Ƿ����
struct Edge {    //�ߵĽṹ��
    int w;  //��Ȩ
    int pre, to;    //����ߣ�preΪ��㣬toΪ�յ�
} l[10000];
struct Node {    //�ڵ�Ľṹ��
    int num;    //�������Ϊ���ıߵĸ���
    vector<int> about;  //�������Ϊ���ıߵı��
} a[10000];

int find_new() {    //ÿ�δ����꣬��ȥ���µĽڵ�
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0 && minn > dist[i]) {
            minn = dist[i];
            node = i;
        }
    }
    return node;
}

signed main() {
    cin >> n >> m >> s; //nΪ�ڵ�����mΪ������sΪ��ʼ��
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;  //��ʼ��
    }
    int x, y, z;
    for (int i = 1; i <= m; i++) {  //�����
        cin >> x >> y >> z;
        l[i].pre = x;
        l[i].to = y;
        l[i].w = z;
        a[x].num++;
        a[x].about.emplace_back(i);
    }
    dist[s] = 0;    //�����ľ�������Ϊ0
    node = s;
    while (!vis[node]) {
        vis[node] = 1;
        minn = INT_MAX;
        for (int i = 0; i < a[node].num; i++) { //ö��ÿ���������Ϊ���ı�
            int num = a[node].about[i]; //��ȡ��ǰö�ٵ��ıߵ����
            int exit = l[num].to;   //��ǰö�ٵ��ıߵ��յ�
            dist[exit] = min(dist[exit], dist[node] + l[num].w);  //�ɳ�
        }
        node = find_new();
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}