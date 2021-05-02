#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
int size;
int heap[MAX_N];

void push(int num){
    int i = size++;
    while(i > 0) {
        int par = (i - 1) / 2;  //���׽ڵ�ı��
        if(heap[par] <= num)
            break;  //����Ѿ�û�д�С�ߵ����˳�
        heap[i] = heap[par];    //�����׽ڵ����ֵ������
        i = par;
    }
    heap[i] = num;
}

int pop(){
    int res = heap[0];  //��Сֵ
    int x = heap[--size];   //Ҫ�ᵽ������ֵ
    int i = 0;
    while(i * 2 + 1 < size) {   //�Ӹ���ʼ���½���
        int a = i * 2 + 1;
        int b = i * 2 + 2;
        if(b < size && heap[b] < heap[a])
            a = b;  //ȡ�����Һ����н�С��һ��
        if(heap[a] >= x)
            break;  //���û�д�С�ߵ����˳�
        heap[i] = heap[a];  //�����ӵ���ֵ������
        i = a;
    }
    heap[i] = x;    //��֮ǰ�ڸ�����ֵ������
    return res;
}

int main(){
    //��С��
    int n;
    int num;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        push(num);
    }
}