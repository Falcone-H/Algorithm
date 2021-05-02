#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
int size;
int heap[MAX_N];

void push(int num){
    int i = size++;
    while(i > 0) {
        int par = (i - 1) / 2;  //父亲节点的编号
        if(heap[par] <= num)
            break;  //如果已经没有大小颠倒则退出
        heap[i] = heap[par];    //将父亲节点的数值换下来
        i = par;
    }
    heap[i] = num;
}

int pop(){
    int res = heap[0];  //最小值
    int x = heap[--size];   //要提到根的数值
    int i = 0;
    while(i * 2 + 1 < size) {   //从根开始向下交换
        int a = i * 2 + 1;
        int b = i * 2 + 2;
        if(b < size && heap[b] < heap[a])
            a = b;  //取出左右孩子中较小的一个
        if(heap[a] >= x)
            break;  //如果没有大小颠倒则退出
        heap[i] = heap[a];  //将孩子的数值提上来
        i = a;
    }
    heap[i] = x;    //将之前在根的数值换下来
    return res;
}

int main(){
    //最小堆
    int n;
    int num;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        push(num);
    }
}