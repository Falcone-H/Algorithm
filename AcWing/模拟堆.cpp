// https://www.acwing.com/problem/content/841/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int h[N];
int hp[N];  // 在堆中的插入顺序
int ph[N];  // 存放第 k 个插入点的下标
int n, m;   // m 表示堆中还有多少个数
int len;    // 已经插入了多少个数

void heap_swap(int x, int y) {
    swap(h[x], h[y]);
    swap(hp[x], hp[y]);
    swap(ph[hp[x]], ph[hp[y]]);
}

void up(int x) {
    while((x - 1) >> 1 >= 0) {
        int par = (x - 1) >> 1;
        if(h[par] <= h[x])
            break;
        heap_swap(par, x);
        x = par;
    }
}

void down(int x) {
    while((x << 1) + 1 < m) {
        int l = (x << 1) + 1;
        int r = (x << 1) + 2;
        int pos = l;
        if(r < m && h[l] > h[r])
            pos = r;
        if(h[pos] >= h[x])
            break;
        heap_swap(x, pos);
        x = pos;
    }
}

int main() {
    cin >> n;
    string oper;
    int k, x;
    while(n--) {
        cin >> oper;
        if(oper == "I") {
            cin >> x;
            h[m] = x;
            hp[m] = len;
            ph[len] = m;
            up(m);
            m++;
            len++;
        } else if(oper == "PM") {
            cout << h[0] << "\n";
        } else if(oper == "DM") {
            heap_swap(0, m - 1);
            m--;
            down(0);
        } else if(oper == "D") {
            cin >> k;
            int pos = ph[k - 1];    // 下标从 0 开始，所以需要减1
            heap_swap(pos, m - 1);
            m--;
            up(pos);
            down(pos);
        } else if(oper == "C") {
            cin >> k >> x;
            int pos = ph[k - 1];    // 下标从 0 开始，所以需要减1
            h[pos] = x;
            up(pos);
            down(pos);
        }
    }
    return 0;
}