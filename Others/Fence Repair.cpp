// POJ 3253
// �㷨��̰��
// ˼·��ÿ�ζ�ѡȡ��С���������֣���֤ÿ����ӵõ��ĺ���С���ٰѺͼ������ȶ��С�

#include <iostream> // ר��POJ����������ͷ
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdio>
#define int long long

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int n, num, res;
signed main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        q.push(num);
    }
    while(q.size() > 1){
        int q1 = q.top();
        q.pop();
        int q2 = q.top();
        q.pop();
        res += (q1 + q2);
        q.push(q1 + q2);
    }
    cout << res << endl;
    return 0;
}